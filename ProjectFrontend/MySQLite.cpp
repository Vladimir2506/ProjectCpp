/*
**Database.cpp
**The implementation of class MyDatabase
**Powered By SQLite3
*/

#include "stdafx.h"
#include <cassert>

constexpr int nDefaultEnd = -1;

using namespace std;

MyDataBase::MyDataBase(const string & strFileName)
	:m_strFileName(strFileName)
{
	//If no parametres
	if (strFileName.empty())
	{
		m_pDBCore = nullptr;
		m_nStatus = DBSTATE::DB_NULL;
		m_strErrMsg = "";
	}
	//Try to open a database and set status
	else
	{
		int nOpenResult = sqlite3_open(strFileName.c_str(), &m_pDBCore);
		if (nOpenResult != SQLITE_OK)
		{
			m_pDBCore = nullptr;
			m_nStatus = DBSTATE::DB_NULL;
			m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		}
		else
		{
			m_nStatus = DBSTATE::DB_READY;
			m_strErrMsg = "";
		}
	}
	m_pTempQuery = nullptr;
}

MyDataBase::~MyDataBase()
{
	//If a database is open and connected
	//Try to close it first
	if (m_nStatus == DBSTATE::DB_READY)
	{
		int nCloseResult = sqlite3_close_v2(m_pDBCore);
		assert(nCloseResult == SQLITE_OK);
		m_pDBCore = nullptr;
		m_nStatus = DBSTATE::DB_NULL;
	}
}

void MyDataBase::Open(const string & strFileName)
{
	//Try to open or new a database
	//If a database is already open then do nothing
	if (m_nStatus != DBSTATE::DB_NULL)
	{
		return;
	}
	int nOpenResult = sqlite3_open(strFileName.c_str(), &m_pDBCore);
	if (nOpenResult != SQLITE_OK)
	{
		m_pDBCore = nullptr;
		m_nStatus = DBSTATE::DB_NULL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
	}
	else
	{
		m_nStatus = DBSTATE::DB_READY;
		m_strErrMsg = "";
		m_strFileName = strFileName;
	}
}

void MyDataBase::Close()
{
	//If no database is open then do nothing
	if (m_nStatus != DBSTATE::DB_READY)
	{
		return;
	}
	//Try to close a database
	if (m_nStatus == DBSTATE::DB_READY)
	{
		int nCloseResult = sqlite3_close_v2(m_pDBCore);
		if (nCloseResult == SQLITE_OK)
		{
			m_pDBCore = nullptr;
			m_nStatus = DBSTATE::DB_NULL;
			m_strErrMsg = "";
			m_strFileName = "";
		}
		else
		{
			//If close fails then set status
			m_nStatus = DBSTATE::DB_NCLOSE;
			m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		}
	}
}

bool MyDataBase::IsTableExist(const string & strTableName)
{
	//Check if Tablename is empty
	if (strTableName.empty())
	{
		return false;
	}
	if ((m_nStatus != DBSTATE::DB_READY) && (m_nStatus != DBSTATE::DB_PROCESS))
	{
		return false;
	}
	//Get a statement
	string strSqlStatement = "SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name = '" + strTableName +"';";
	string strResult;
	char *err = nullptr;
	int nExResult = sqlite3_exec(m_pDBCore, strSqlStatement.c_str(),
		[](void *pRes, int argc, char **szVals, char**column)
	{
		static_cast<string*>(pRes)->operator=(szVals[0]);
		return 0;
	},
		&strResult, &err);
	if (nExResult != SQLITE_OK)
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = err;
		sqlite3_free(err);
		err = nullptr;
	}
	return stoi(strResult) > 0;
}


bool MyDataBase::IsReady()
{
	return m_nStatus == DBSTATE::DB_READY;
}

bool MyDataBase::IsClosed()
{
	return m_nStatus == DBSTATE::DB_NULL;
}

bool MyDataBase::IsProcess()
{
	return m_nStatus == DBSTATE::DB_PROCESS;
}

bool MyDataBase::IsEnd()
{
	return m_nStatus == DBSTATE::DB_ENDQUERY;
}

const string & MyDataBase::GetErrorMessage()
{
	return m_strErrMsg;
}

void MyDataBase::CreateTable(const string & strTableName, const vector<string> strTerms, const vector<string> strOptions)
{
	//If the database is not ready then return
	if (m_nStatus != DBSTATE::DB_READY)
	{
		return;
	}
	//If the Parametres is contradictory then return
	if (strTerms.size() != strOptions.size())
	{
		return;
	}
	const auto nHeader = strTerms.size();
	//Concatenate every parameters to a sql statement
	string strSqlStatement = "CREATE TABLE " + strTableName + "(";
	for (int i = 0; i < nHeader; ++i)
	{
		strSqlStatement += strTerms[i];
		if (i == 0)
		{
			strSqlStatement += " PRIMARY KEY";
		}
		strSqlStatement += " " + strOptions[i];
		if (i != nHeader - 1)
		{
			strSqlStatement += ",";
		}
	}
	strSqlStatement += ");";
	sqlite3_stmt *pSqlStatement = nullptr;
	int nPrepResult = sqlite3_prepare_v2(m_pDBCore, strSqlStatement.c_str(), nDefaultEnd, &pSqlStatement, nullptr);
	//If something goes wrong then set status and return
	if (nPrepResult != SQLITE_OK)
	{
		m_nStatus = DBSTATE::DB_NCOMPILE;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Else execute the statement
	int nStepResult = sqlite3_step(pSqlStatement);
	if (nStepResult != SQLITE_DONE)
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Clear the memory
	sqlite3_finalize(pSqlStatement);
}

void MyDataBase::DeleteTable(const string & strTableName)
{
	//If the database is not ready then return
	if (m_nStatus != DBSTATE::DB_READY)
	{
		return;
	}
	//If the table does not exist
	if (!IsTableExist(strTableName))
	{
		return;
	}
	//Generate a sql statement
	string strSqlStatement = "DROP TABLE " + strTableName + ";";
	sqlite3_stmt *pSqlStatement = nullptr;
	int nPrepResult = sqlite3_prepare_v2(m_pDBCore, strSqlStatement.c_str(),
		nDefaultEnd, &pSqlStatement, nullptr);
	//If something goes wrong then set status and return
	if (nPrepResult != SQLITE_OK)
	{
		m_nStatus = DBSTATE::DB_NCOMPILE;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Else execute the statement
	int nStepResult = sqlite3_step(pSqlStatement);
	if (nStepResult != SQLITE_DONE)
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Clear the memory
	sqlite3_finalize(pSqlStatement);
}

void MyDataBase::InsertValue(const string & strTableName, const vector<string> strVals)
{
	//If the database is not ready then return
	if (m_nStatus != DBSTATE::DB_READY)
	{
		return;
	}
	auto nHeader = strVals.size();
	//Concatenate every parameters to a sql statement
	string strSqlStatement = "INSERT intO " + strTableName + " VALUES(" ;
	for (int i = 0; i < nHeader; ++i)
	{
		strSqlStatement += strVals[i];
		if (i != nHeader - 1)
		{
			strSqlStatement += ",";
		}
	}
	strSqlStatement += ");";
	sqlite3_stmt *pSqlStatement = nullptr;
	int nPrepResult = sqlite3_prepare_v2(m_pDBCore, strSqlStatement.c_str(), nDefaultEnd, &pSqlStatement, nullptr);
	//If something goes wrong then set status and return
	if (nPrepResult != SQLITE_OK)
	{
		m_nStatus = DBSTATE::DB_NCOMPILE;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Else execute the statement
	int nStepResult = sqlite3_step(pSqlStatement);
	if (nStepResult != SQLITE_DONE)
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Clear the memory
	sqlite3_finalize(pSqlStatement);
}

void MyDataBase::UpdateValue(const string & strTableName, const vector<string> strTermNames, const vector<string> strTermValues, const string & strConditions)
{
	//If the database is not ready then return
	if (m_nStatus != DBSTATE::DB_READY)
	{
		return;
	}
	//If the Parametres is contradictory then return
	if (strTermNames.size() != strTermValues.size())
	{
		return;
	}
	const auto nTerms = strTermNames.size();
	//Concatenate every parameters to a sql statement
	string strSqlStatement = "UPDATE " + strTableName + " SET ";
	for (int i = 0; i < nTerms; ++i)
	{
		strSqlStatement += strTermNames[i] + " = " + strTermValues[i];
		if (i != nTerms - 1)
		{
			strSqlStatement += ",";
		}
	}
	if (!strConditions.empty())
	{
		strSqlStatement += " WHERE " + strConditions;
	}
	strSqlStatement += ";";
	sqlite3_stmt *pSqlStatement = nullptr;
	int nPrepResult = sqlite3_prepare_v2(m_pDBCore, strSqlStatement.c_str(), nDefaultEnd, &pSqlStatement, nullptr);
	//If something goes wrong then set status and return
	if (nPrepResult != SQLITE_OK)
	{
		m_nStatus = DBSTATE::DB_NCOMPILE;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Else execute the statement
	int nStepResult = sqlite3_step(pSqlStatement);
	if (nStepResult != SQLITE_DONE)
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Clear the memory
	sqlite3_finalize(pSqlStatement);
}

void MyDataBase::DeleteValue(const string & strTableName, const string & strConditions)
{
	//If the database is not ready then return
	if (m_nStatus != DBSTATE::DB_READY)
	{
		return;
	}
	//Concatenate every parameters to a sql statement
	string strSqlStatement = "DELETE FROM " + strTableName;
	if (!strConditions.empty())
	{
		strSqlStatement += " WHERE " + strConditions;
	}
	strSqlStatement += ";";
	sqlite3_stmt *pSqlStatement = nullptr;
	int nPrepResult = sqlite3_prepare_v2(m_pDBCore, strSqlStatement.c_str(), nDefaultEnd, &pSqlStatement, nullptr);
	//If something goes wrong then set status and return
	if (nPrepResult != SQLITE_OK)
	{
		m_nStatus = DBSTATE::DB_NCOMPILE;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Else execute the statement
	int nStepResult = sqlite3_step(pSqlStatement);
	if (nStepResult != SQLITE_DONE)
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
	//Clear the memory
	sqlite3_finalize(pSqlStatement);
}

void MyDataBase::QuerySelection(const string & strTableName, vector<string>& rstrResults, const string & strConditions, const vector<string> strTerms, const string & strRestrictions)
{
	sqlite3_stmt *pSqlStatement = nullptr;
	int nPrepResult = 0;
	//If the database is not ready then return
	if (m_nStatus != DBSTATE::DB_READY && m_nStatus != DBSTATE::DB_PROCESS)
	{
		return;
	}
	//Select statement preparation
	if (m_nStatus == DBSTATE::DB_READY)
	{
		//Concatenate every parameters to a sql statement
		string strSqlStatement = "SELECT ";
		if (strTerms.empty())
		{
			strSqlStatement += "*";
		}
		else
		{
			const auto nHeader = strTerms.size();
			for (int i = 0; i < nHeader; ++i)
			{
				strSqlStatement += strTerms[i];
				if (i != nHeader - 1)
				{
					strSqlStatement += ",";
				}
			}
		}
		strSqlStatement += " FROM " + strTableName;
		//If there are some conditions 
		if (!strConditions.empty())
		{
			strSqlStatement += " WHERE " + strConditions;
		}
		//If the result is restricted
		if (!strRestrictions.empty())
		{
			strSqlStatement += " " + strRestrictions;
		}
		strSqlStatement += ";";
		nPrepResult = sqlite3_prepare_v2(m_pDBCore, strSqlStatement.c_str(), nDefaultEnd, &pSqlStatement, nullptr);
		if (nPrepResult != SQLITE_OK)
		{
			m_nStatus = DBSTATE::DB_NCOMPILE;
			m_strErrMsg = sqlite3_errmsg(m_pDBCore);
			return;
		}
	}
	else
	{
		pSqlStatement = m_pTempQuery;
	}
	//Conduct query
	int nQueryResult = sqlite3_step(pSqlStatement);
	//Set flags according to the return value.
	if (nQueryResult == SQLITE_ROW)
	{
		m_nStatus = DBSTATE::DB_PROCESS;
		int nTerm = sqlite3_column_count(pSqlStatement);
		//Return results
		for (int i = 0; i < nTerm; ++i)
		{
			auto typeVal = sqlite3_column_type(pSqlStatement, i);
			switch (typeVal)
			{
			case SQLITE_TEXT:
				rstrResults.push_back(reinterpret_cast<const char*>(sqlite3_column_text(pSqlStatement, i)));
				break;
			case SQLITE_INTEGER:
				rstrResults.push_back(to_string(sqlite3_column_int(pSqlStatement, i)));
				break;
			case SQLITE_FLOAT:
				rstrResults.push_back(to_string(sqlite3_column_double(pSqlStatement, i)));
				break;
			default:
				m_nStatus = DBSTATE::DB_FAIL;
				m_strErrMsg = sqlite3_errmsg(m_pDBCore);
				return;
			}
		}
		m_pTempQuery = pSqlStatement;
	}
	else if (nQueryResult == SQLITE_DONE)
	{
		//If query ends,the database will hang up.
		m_nStatus = DBSTATE::DB_ENDQUERY;
		m_pTempQuery = nullptr;
		sqlite3_finalize(pSqlStatement);
		pSqlStatement = nullptr;
	}
	else
	{
		m_nStatus = DBSTATE::DB_FAIL;
		m_strErrMsg = sqlite3_errmsg(m_pDBCore);
		return;
	}
}

void MyDataBase::EndQuery()
{
	if (m_nStatus == DBSTATE::DB_ENDQUERY)
	{
		m_nStatus = DBSTATE::DB_READY;
	}
}
