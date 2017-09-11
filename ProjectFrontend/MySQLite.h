/*
**DataBase.h
**The header of database classes
**Powered By SQLite3
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <stdexcept>

#include "sqlite3.h"

#ifdef _DEBUG
#pragma comment (lib,"sqlite3d.lib")
#else
#pragma comment (lib,"sqlite3r.lib")
#endif

/*
**class MyDataBase
**Its core is a sqlite3 pointer to appoint a sqlite object.
*/

using std::string;
using std::vector;

const vector<string> strNils;	//Notify an empty vector

class MyDataBase
{
private:
	sqlite3_stmt *m_pTempQuery;
protected:
	sqlite3 * m_pDBCore;	//Core pointer
	int m_nStatus;			//Status Indication
	string m_strErrMsg;		//Error message
public:
	string m_strFileName;
	//Constructors
	MyDataBase(const string & strFileName = "");
	MyDataBase(const MyDataBase &) = delete;
	MyDataBase(MyDataBase &&) = delete;
	//Operators
	MyDataBase & operator=(const MyDataBase &) = delete;
	MyDataBase & operator=(MyDataBase &&) = delete;
	//Destructor
	~MyDataBase();
	//Open and Close
	void Open(const string & strFileName);
	void Close();
	//Check if a table has already existed
	bool IsTableExist(const string & strTableName);
	//Check status
	bool IsReady();
	bool IsClosed();
	bool IsProcess();
	bool IsEnd();
	const string & GetErrorMessage();
	//Create a table
	void CreateTable(const string & strTableName, const vector<string> strTerms , const vector<string> strOptions = strNils);
	//Deleta a table
	void DeleteTable(const string & strTableName);
	//Manipulate values
	void InsertValue(const string & strTableName, const vector<string> strVals);
	void UpdateValue(const string & strTableName, const vector<string> strTermNames, const vector<string> strTermValues, const string & strConditions = "");
	void DeleteValue(const string & strTableName, const string & strConditions = "");
	//Query data
	void QuerySelection(const string & strTableName, 
		vector<string> & rstrResults,
		const string & strConditions = "", const vector<string> strTerms = strNils, const string & strRestrictions = "");
	//Confirm suspension or set a suspension
	void EndQuery();
};

/*
**enum DBSTATE
**a set describing the state of MyDataBase objects.
*/

enum DBSTATE
{
	DB_NULL = 0,
	DB_READY = 1,
	DB_NCLOSE = 2,
	DB_NCOMPILE = 3,
	DB_FAIL = 4,
	DB_PROCESS = 5,
	DB_ENDQUERY = 6
};

#endif
