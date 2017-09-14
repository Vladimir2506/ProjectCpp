/*
**Cafeteria.cpp
**This file contains all implementation of Backend's features.
*/

#include "stdafx.h"

using namespace std;

//Static variables initialisation
map<string, Cuisine> MainLogic::s_currentMenu;
map<string, Order> MainLogic::s_currentOrders;
map<string, Cook> MainLogic::s_currentCooks;
map<string, Customer> MainLogic::s_currentCustomers;
map<string, Comment> MainLogic::s_currentComments;
map<string, Waitor> MainLogic::s_currentWaitors;
map<string, Manager> MainLogic::s_currentManagers;
map<string, Maintainer> MainLogic::s_currentMaintainers;
MainLogic * MainLogic::m_pInstance = nullptr;

//Classes implementation

MainLogic::MainLogic()
	:MainDB("Main.db")
{
	pUser = nullptr;
}

MainLogic::~MainLogic()
{
	MainDB.~MyDataBase();
}

MainLogic * MainLogic::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new MainLogic;
	}
	return m_pInstance;
}

void MainLogic::DestroyInstance()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

string MainLogic::ToSql(const string & str)
{
	return "'" + str + "'";
}

void MainLogic::Initialise()
{
	if (!MainDB.IsReady())
	{
		throw runtime_error(MainDB.GetErrorMessage());
	}
	if (MainDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(MainDB.m_strFileName);
	}
	string strTableName;
	Object *ptr = nullptr;
	//Menu 1st
	strTableName = "Cuisine";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Cuisine;
		ptr->LoadInfo(MainDB);
		if (*ptr != Cuisine())
		{
			s_currentMenu.emplace(ptr->GetId(), *dynamic_cast<Cuisine*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Orders 2nd
	strTableName = "Orders";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Order;
		ptr->LoadInfo(MainDB);
		if (*ptr != Order())
		{
			s_currentOrders.emplace(ptr->GetId(), *dynamic_cast<Order*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Customers 3rd
	strTableName = "Customer";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Customer;
		ptr->LoadInfo(MainDB);
		if (*ptr != Customer())
		{
			s_currentCustomers.emplace(ptr->GetId(), *dynamic_cast<Customer*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Comments 4th
	strTableName = "Comment";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Comment;
		ptr->LoadInfo(MainDB);
		if (*ptr != Comment())
		{
			s_currentComments.emplace(ptr->GetId(), *dynamic_cast<Comment*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Cooks 5th
	strTableName = "Cook";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Cook;
		ptr->LoadInfo(MainDB);
		if (*ptr != Cook())
		{
			s_currentCooks.emplace(ptr->GetId(), *dynamic_cast<Cook*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Waitors 6th
	strTableName = "Waitor";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Waitor;
		ptr->LoadInfo(MainDB);
		if (*ptr != Waitor())
		{
			s_currentWaitors.emplace(ptr->GetId(), *dynamic_cast<Waitor*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Managers 7th
	strTableName = "Manager";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Manager;
		ptr->LoadInfo(MainDB);
		if (*ptr != Manager())
		{
			s_currentManagers.emplace(ptr->GetId(), *dynamic_cast<Manager*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
	//Maintainers 8th
	strTableName = "Maintainer";
	while ((!MainDB.IsEnd()) && MainDB.IsTableExist(strTableName))
	{
		ptr = new Maintainer;
		ptr->LoadInfo(MainDB);
		if (*ptr != Maintainer())
		{
			s_currentMaintainers.emplace(ptr->GetId(), *dynamic_cast<Maintainer*>(ptr));
		}
		delete ptr;
		ptr = nullptr;
	}
	MainDB.EndQuery();
}

void MainLogic::Finalise()
{
	if (!MainDB.IsReady())
	{
		throw runtime_error(MainDB.GetErrorMessage());
	}
	if (MainDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(MainDB.m_strFileName);
	}
	//No order
	for (auto &rc : s_currentMenu)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentComments)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentCustomers)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentOrders)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentWaitors)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentCooks)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentManagers)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
	for (auto &rc : s_currentMaintainers)
	{
		if (rc.first != "")
		{
			rc.second.SaveInfo(MainDB);
		}
	}
}

People * MainLogic::FindExist(const string & strPhone)
{
	for (auto &r : MainLogic::s_currentCustomers)
	{
		if (r.second.GetPhone() == strPhone)
		{
			return &r.second;
		}
	}
	for (auto &r : MainLogic::s_currentManagers)
	{
		if (r.second.GetPhone() == strPhone)
		{
			return &r.second;
		}
	}
	for (auto &r : MainLogic::s_currentCooks)
	{
		if (r.second.GetPhone() == strPhone)
		{
			return &r.second;
		}
	}
	for (auto &r : MainLogic::s_currentWaitors)
	{
		if (r.second.GetPhone() == strPhone)
		{
			return &r.second;
		}
	}
	for (auto &r : MainLogic::s_currentMaintainers)
	{
		if (r.second.GetPhone() == strPhone)
		{
			return &r.second;
		}
	}
	return nullptr;
}

Object::Object(const string & strId, const string & strName)
	:m_strId(strId), m_strName(strName)
{

}

void Object::SetName(const string & strName)
{
	m_strName = strName;
}

string Object::GetName() const
{
	return m_strName;
}

void Object::SetId(const string & strId)
{
	m_strId = strId;
}

string Object::GetId() const
{
	return m_strId;
}

bool Object::operator==(const Object & obj) const
{
	return m_strId == obj.m_strId;
}

bool Object::operator<(const Object & obj) const
{
	return m_strId < obj.m_strId;
}

bool Object::operator>(const Object & obj) const
{
	return m_strId > obj.m_strId;
}

bool Object::operator!=(const Object & obj) const
{
	return m_strId != obj.m_strId;
}

Object::~Object()
{

}

People::People(const string & strId, const string & strName, const string & strPassword, const string & strPhone)
	:Object(strId, strName), m_strPassword(strPassword), m_strPhone(strPhone)
{

}

void People::SetPassword(const string & strPassword)
{
	m_strPassword = strPassword;
}

string People::GetPassword() const
{
	return m_strPassword;
}

void People::SetPhone(const string & strPhone)
{
	m_strPhone = strPhone;
}

string People::GetPhone() const
{
	return m_strPhone;
}

People::~People()
{

}

Comment::Comment(const string & strId, const string & strName, const string & strUserId, const string & strDishId, const string & strDate)
	:Object(strId, strName), m_strDishId(strDishId), m_strUserId(strUserId), m_strDate(strDate)
{

}


void Comment::SetUserId(const string & strUserId)
{
	m_strUserId = strUserId;
}

string Comment::GetUserId() const
{
	return m_strUserId;
}

void Comment::SetDishId(const string & strDishId)
{
	m_strDishId = strDishId;
}

string Comment::GetDishId() const
{
	return m_strDishId;
}

void Comment::SetDate(const string & strDate)
{
	m_strDate = strDate;
}

string Comment::GetDate() const
{
	return m_strDate;
}

void Comment::LoadInfo(MyDataBase &theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 7;
	const string strTableName = "Comment";
	//The schema
	/*
	TABLE Comment
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	STAR INT NOT NULL
	CONTENT NTEXT NOT NULL
	USERID NTEXT NOT NULL
	DISHID NTEXT NOT NULL
	DATE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_nStar = stoi(strResults[2]);
		m_strContent = strResults[3];
		m_strUserId = strResults[4];
		m_strDishId = strResults[5];
		m_strDate = strResults[6];
	}
}

void Comment::SaveInfo(MyDataBase &theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),to_string(m_nStar),MainLogic::ToSql(m_strContent),MainLogic::ToSql(m_strUserId),MainLogic::ToSql(m_strDishId),MainLogic::ToSql(m_strDate) };
	constexpr int nLength = 7;
	const string strTableName = "Comment";
	//The schema
	/*
	TABLE Comment
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	STAR INT NOT NULL
	CONTENT NTEXT NOT NULL
	USERID NTEXT NOT NULL
	DISHID NTEXT NOT NULL
	DATE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		vector<string> strTerms{ "ID NTEXT","NAME NTEXT","STAR int","CONTENT NTEXT","USERID NTEXT","DISHID NTEXT","DATE NTEXT" };
		vector<string> strOptions(nLength, "NOT NULL");
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		vector<string> strResults;
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
}

void Comment::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Comment";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
}

Cuisine::Cuisine(const string & strId, const string & strName, const int nPrice)
	:Object(strId, strName), m_nPrice(nPrice)
{

}

void Cuisine::SetPrice(const int nPrice)
{
	m_nPrice = nPrice;
}

int Cuisine::GetPrice() const
{
	return m_nPrice;
}

void Cuisine::LoadInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 3;
	const string strTableName = "Cuisine";
	//The schema
	/*
	TABLE Cuisine
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PRICE int NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_nPrice = stoi(strResults[2]);
	}
}

void Cuisine::SaveInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),to_string(m_nPrice) };
	constexpr int nLength = 3;
	const string strTableName = "Cuisine";
	//The schema
	/*
	TABLE Cuisine
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PRICE int NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		vector<string> strTerms{ "ID NTEXT","NAME NTEXT","PRICE int" };
		vector<string> strOptions(nLength, "NOT NULL");
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		vector<string> strResults;
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
}

void Cuisine::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Cuisine";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
}

Order::Order(const string & strId, const string & strName, const string & strCustomerId, const string & strWaitorId)
	:Object(strId, strName), m_strCustomerId(strCustomerId), m_strWaitorId(strWaitorId)
{
	bAssigned = false;
}

void Order::SetCustomerId(const string & strCustomerId)
{
	m_strCustomerId = strCustomerId;
}

string Order::GetCustomerId() const
{
	return m_strCustomerId;
}

void Order::SetWaitorId(const string & strWaitorId)
{
	m_strWaitorId = strWaitorId;
}

string Order::GetWaitorId() const
{
	return m_strWaitorId;
}

map<Cuisine, int> Order::GetFoodMap() const
{
	return m_mapOrderFood;
}

void Order::SetFoodMap(const map<Cuisine, int>& mapOrderFood)
{
	m_mapOrderFood = mapOrderFood;
}

void Order::SetTableNum(const int & nTableNum)
{
	m_nTableNum = nTableNum;
}

int Order::GetTableNum() const
{
	return m_nTableNum;
}

void Order::Adjust(const Cuisine theDish, int nAmount)
{
	//Deal with the ordered
	auto dish = m_mapOrderFood.find(theDish);
	if (dish != m_mapOrderFood.end())
	{
		if (nAmount == 0)
		{
			m_mapOrderFood.erase(dish);
		}
		else
		{
			dish->second = nAmount;
		}
	}
	else if (nAmount != 0)
	{
		m_mapOrderFood.emplace(theDish, nAmount);
	}
	//Deal with the bill
	auto bil = m_mapBill.find(theDish);
	if(bil != m_mapBill.end())
	{
		if (nAmount == 0)
		{
			m_mapBill.erase(bil);
		}
		else
		{
			bil->second = nAmount * theDish.GetPrice();
		}
	}
	else if (nAmount != 0)
	{
		m_mapBill.emplace(theDish, nAmount * theDish.GetPrice());
	}
}


int Order::CheckOut()
{
	int nResult = 0;
	for (auto m : m_mapBill)
	{
		nResult += m.second;
	}
	m_mapFoodToDo = m_mapOrderFood;
	return nResult;
}

void Order::Assign()
{
	if (bAssigned)
	{
		return;
	}
	auto as = m_mapFoodToDo;
	auto rc = MainLogic::s_currentCooks.begin();
	for (auto dish = as.begin(); dish != as.end();)
	{
		if (dish->second > 0)
		{
			--(dish->second);
			rc->second.Pick(make_pair(dish->first,this));
			++rc;
		}
		else
		{
			++dish;
		}
		if (rc == MainLogic::s_currentCooks.end())
		{
			rc = MainLogic::s_currentCooks.begin();
		}
	}
	bAssigned = true;
}

void Order::Consume(const Cuisine theDish)
{
	if (m_mapFoodToDo[theDish] > 0)
	{
		--m_mapFoodToDo[theDish];
	}
}

string Order::Appoint()
{
	if (!m_strWaitorId.empty())
	{
		return m_strWaitorId;
	}
	auto it = find_if(MainLogic::s_currentWaitors.begin(), MainLogic::s_currentWaitors.end(),
		[](pair<const string &, Waitor> obj)
	{
		return obj.second.IsIdle();
	});
	if (it != MainLogic::s_currentWaitors.end())
	{
		it->second.SetTableNum(m_nTableNum);
		m_strWaitorId = it->first;
	}
	else
	{
		m_strWaitorId = "";
	}
	return m_strWaitorId;
}

bool Order::IsServed()
{
	return !m_strWaitorId.empty();
}

void Order::LoadInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 5;
	const string strTableName = "Orders";
	//The schema
	/*
	TABLE Orders
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	IDCUSTOMER NTEXT NOT NULL
	IDWAITOR NTEXT NOT NULL
	NOTABLE INT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_strCustomerId = strResults[2];
		m_strWaitorId = strResults[3];
		m_nTableNum = stoi(strResults[4]);
	}
	strResults.clear();
	//Load another database
	MyDataBase dishDB("OrderFood.db");
	//The schema
	/*
	TABLE 'o' + m_strId
	ID NTEXT PRIMARY KEY NOT NULL
	AMOUNT INT NOT NULL
	*/
	constexpr int nLengthData = 2;
	string strSubName = "o" + m_strId;
	//If no table matches
	if (!dishDB.IsTableExist(strSubName))
	{
		return;
	}
	while (!dishDB.IsEnd())
	{
		dishDB.QuerySelection(strSubName, strResults);
		if (strResults.size() == nLengthData)
		{
			m_mapOrderFood.emplace(MainLogic::s_currentMenu[strResults[0]], stoi(strResults[1]));
		}
		strResults.clear();
	}
	dishDB.EndQuery();
}

void Order::SaveInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strResults;
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),MainLogic::ToSql(m_strCustomerId),MainLogic::ToSql(m_strWaitorId),to_string(m_nTableNum) };
	constexpr int nLength = 5;
	const string strTableName = "Orders";
	//The schema
	/*
	TABLE Orders
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	IDCUSTOMER NTEXT NOT NULL
	IDWAITOR NTEXT NOT NULL
	NOTABLE INT NOT NULL
	*/
	vector<string> strTerms{ "ID NTEXT","NAME NTEXT","IDCUSTOMER NTEXT","IDWAITOR NTEXT","NOTABLE INT" };
	vector<string> strOptions(nLength, "NOT NULL");
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
	strResults.clear();
	strTerms.clear();
	strOptions.clear();
	strVals.clear();
	//Load another database
	MyDataBase dishDB("OrderFood.db");
	//The schema
	/*
	TABLE 'o' + m_strId
	ID NTEXT PRIMARY KEY NOT NULL
	AMOUNT INT NOT NULL
	*/
	constexpr int nLengthData = 2;
	string strSubName = "o" + m_strId;
	strTerms = { "ID NTEXT","AMOUNT INT" };
	strOptions = vector<string>(nLengthData, "NOT NULL");
	//If no table matches
	dishDB.DeleteTable(strSubName);
	dishDB.CreateTable(strSubName, strTerms, strOptions);
	for (auto it = m_mapOrderFood.begin(); it != m_mapOrderFood.end(); ++it)
	{
		strVals = { MainLogic::ToSql(it->first.GetId()),to_string(it->second) };
		dishDB.InsertValue(strSubName, strVals);
	}
}

void Order::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Orders";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
	MyDataBase subDB("OrderFood.db");
	string strSubName = "o" + m_strId;
	subDB.DeleteTable(strSubName);
}

Customer::Customer(const string & strId, const string & strName, const string & strPassword, const string & strPhone)
	:People(strId, strName, strPassword, strPhone)
{
	m_nState = CSSTATE::Absent;
	m_nTableNum = -1;
	m_itNow = MainLogic::s_currentOrders.end();
}

void Customer::SetState(const int nState)
{
	m_nState = nState;
}

int Customer::GetState() const
{
	return m_nState;
}

int Customer::GetTableNum() const
{
	return m_nTableNum;
}

const map<string, Order>::iterator Customer::GetCurrrentOrder() const
{
	return m_itNow;
}

string Customer::MakeOrder()
{
	if (m_nState != CSSTATE::Eat)
	{
		m_nState = CSSTATE::Eat;
		m_itNow->second.SetCustomerId(m_strId);
	}
	return m_itNow->second.Appoint();
}

void Customer::Finish()
{
	m_nState = CSSTATE::Absent;
	MainLogic::s_currentWaitors[m_itNow->second.GetWaitorId()].Liberate();
	m_itNow = MainLogic::s_currentOrders.end();
	m_statusComment.clear();
	m_waitorComment.clear();
}

void Customer::GetSeat(const int nTable,const string &strName)
{
	if (m_nState == CSSTATE::Make)
	{
		m_itNow->second.SetTableNum(nTable);
		m_nTableNum = nTable;
	}
	else
	{
		m_nState = CSSTATE::Make;
		m_nTableNum = nTable;
		size_t nRec = 0;
		if (!MainLogic::s_currentOrders.empty())
		{
			nRec = stoi(MainLogic::s_currentOrders.rbegin()->first.substr(1, string::npos));
		}
		string theId = IdGenerator(ID_ORDER, nRec);
		m_itNow = MainLogic::s_currentOrders.emplace(theId, Order(theId, strName)).first;
		m_itNow->second.SetTableNum(nTable);
	}
}

void Customer::LoadInfo(MyDataBase &theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength =4;
	const string strTableName = "Customer";
	//The schema
	/*
	TABLE Customer
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_strPassword = strResults[2];
		m_strPhone = strResults[3];
	}
	strResults.clear();
}

void Customer::SaveInfo(MyDataBase &theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strResults;
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),MainLogic::ToSql(m_strPassword),MainLogic::ToSql(m_strPhone) };
	constexpr int nLength = 4;
	const string strTableName = "Customer";
	//The schema
	/*
	TABLE Customer
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	vector<string> strTerms{ "ID NTEXT","NAME NTEXT","PASSWORD NTEXT","PHONE NTEXT" };
	vector<string> strOptions(nLength, "NOT NULL");
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
	strResults.clear();
	strTerms.clear();
	strOptions.clear();
	strVals.clear();
}

vector<string> Customer::CollectComment() const
{
	vector<string> strResults;
	for (auto &c : MainLogic::s_currentComments)
	{
		if (c.second.GetUserId() == m_strId)
		{
			strResults.push_back(c.first);
		}
	}
	return strResults;
}

void Customer::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Customer";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
}


void Cook::Pick(const pair<Cuisine, Order*> theDishByOrder)
{
	m_deqTodo.push_back(theDishByOrder);
}

bool Cook::IsIdle()
{
	return m_deqTodo.empty();
}

void Cook::DoCooking(deque<pair<Cuisine, Order*>>::iterator itCuisine)
{
	auto theDish = itCuisine->first;
	auto &theWaitor = MainLogic::s_currentWaitors[itCuisine->second->GetWaitorId()];
	if (IsIdle())
	{
		return;
	}
	//Get the first stuff in todo list.
	auto it = m_mapWorkDone.find(theDish);
	if (it != m_mapWorkDone.end())
	{
		++(it->second);
	}
	else
	{
		m_mapWorkDone.emplace(theDish, 1);
	}
	theWaitor.m_deqReady.emplace_back(*itCuisine);
	m_deqTodo.erase(itCuisine);
}

Cook::Cook(const string & strId, const string & strName, const string & strPassword, const string & strPhone)
	:People(strId, strName, strPassword, strPhone)
{
}

deque<pair<Cuisine, Order*>> Cook::GetToDoList() const
{
	return m_deqTodo;
}

map<Cuisine, int> Cook::GetWorkDone() const
{
	return m_mapWorkDone;
}

void Cook::LoadInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 4;
	const string strTableName = "Cook";
	//The schema
	/*
	TABLE Customer
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_strPassword = strResults[2];
		m_strPhone = strResults[3];
	}
	strResults.clear();
	//Load another database
	MyDataBase workDB("CookWork.db");
	//The schema
	/*
	TABLE 'w' + m_strId
	ID NTEXT PRIMARY KEY NOT NULL
	AMOUNT INT NOT NULL
	*/
	constexpr int nLengthData = 2;
	string strSubName = "w" + m_strId;
	//If no table matches
	if (!workDB.IsTableExist(strSubName))
	{
		return;
	}
	while (!workDB.IsEnd())
	{
		workDB.QuerySelection(strSubName, strResults);
		if (strResults.size() == nLengthData)
		{
			m_mapWorkDone.emplace(MainLogic::s_currentMenu[strResults[0]], stoi(strResults[1]));
		}
		strResults.clear();
	}
	workDB.EndQuery();
}

void Cook::SaveInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strResults;
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),MainLogic::ToSql(m_strPassword),MainLogic::ToSql(m_strPhone) };
	constexpr int nLength = 4;
	const string strTableName = "Cook";
	//The schema
	/*
	TABLE Cook
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	vector<string> strTerms{ "ID NTEXT","NAME NTEXT","PASSWORD NTEXT","PHONE NTEXT" };
	vector<string> strOptions(nLength, "NOT NULL");
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		theDB.CreateTable(strTableName, strTerms, strOptions);

	}
	else
	{
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
	strResults.clear();
	strTerms.clear();
	strOptions.clear();
	strVals.clear();
	//Load another database
	MyDataBase workDB("CookWork.db");
	//The schema
	/*
	TABLE 'w' + m_strId
	ID NTEXT PRIMARY KEY NOT NULL
	AMOUNT INT NOT NULL
	*/
	constexpr int nLengthData = 2;
	string strSubName = "w" + m_strId;
	strTerms = { "ID NTEXT","AMOUNT INT" };
	strOptions = vector<string>(nLengthData, "NOT NULL");
	//If no table matches
	workDB.DeleteTable(strSubName);
	workDB.CreateTable(strSubName, strTerms, strOptions);
	for (auto p : m_mapWorkDone)
	{
		strVals = { MainLogic::ToSql(p.first.GetId()),to_string(p.second) };
		workDB.InsertValue(strSubName, strVals);
	}
}

vector<string> Cook::CollectComment() const
{
	vector<string> strResults;
	for (auto &c : MainLogic::s_currentComments)
	{
		if (c.second.GetDishId() == m_strId)
		{
			strResults.push_back(c.first);
		}
	}
	return strResults;
}

void Cook::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Cook";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
	MyDataBase subDB("CookWork.db");
	string strSubName = "w" + m_strId;
	subDB.DeleteTable(strSubName);
}

Waitor::Waitor(const string & strId, const string & strName, const string & strPassword, const string & strPhone)
	:People(strId, strName, strPassword, strPhone),m_arrServDone{0}
{
	m_nTableNum = -1;
}


void Waitor::SetTableNum(const int &nTableNum)
{
	m_nTableNum = nTableNum;
}

int Waitor::GetTableNum() const
{
	return m_nTableNum;
}

array<int, nService> Waitor::GetServDone() const
{
	return m_arrServDone;
}


void Waitor::ServePlate(deque<pair<Cuisine, Order*>>::iterator itCuisine)
{
	auto &target = itCuisine->second->m_mapFoodToDo;
	if (target[itCuisine->first] > 1)
	{
		--target[itCuisine->first];
	}
	else
	{
		target.erase(itCuisine->first);
	}
	m_deqReady.erase(itCuisine);
	++m_arrServDone[SRVS::Plate];
}

void Waitor::DoDemand(deque<int>::iterator itDemand)
{
	++m_arrServDone[*itDemand];
	m_deqTodo.erase(itDemand);
}
void Waitor::Liberate()
{
	m_nTableNum = -1;
	m_deqReady.clear();
	m_deqTodo.clear();
}

bool Waitor::IsIdle()
{
	return m_nTableNum == -1;
}

void Waitor::LoadInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 4;
	const string strTableName = "Waitor";
	//The schema
	/*
	TABLE Waitor
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_strPassword = strResults[2];
		m_strPhone = strResults[3];
	}
	strResults.clear();
	//Load another database
	MyDataBase servDB("Service.db");
	//The schema
	/*
	TABLE 's' + m_strId
	ID int PRIMARY KEY NOT NULL
	AMOUNT INT NOT NULL
	*/
	constexpr int nLengthData = 2;
	string strSubName = "s" + m_strId;
	//If no table matches
	if (!servDB.IsTableExist(strSubName))
	{
		return;
	}
	while (!servDB.IsEnd())
	{
		servDB.QuerySelection(strSubName, strResults);
		if (strResults.size() == nLengthData)
		{
			m_arrServDone[stoi(strResults[0])] = stoi(strResults[1]);
		}
		strResults.clear();
	}
	servDB.EndQuery();
}

void Waitor::SaveInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strResults;
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),MainLogic::ToSql(m_strPassword),MainLogic::ToSql(m_strPhone) };
	constexpr int nLength = 4;
	const string strTableName = "Waitor";
	//The schema
	/*
	TABLE Waitor
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	*/
	vector<string> strTerms{ "ID NTEXT","NAME NTEXT","PASSWORD NTEXT","PHONE NTEXT" };
	vector<string> strOptions(nLength, "NOT NULL");
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
	strResults.clear();
	strTerms.clear();
	strOptions.clear();
	strVals.clear();
	//Load another database
	MyDataBase servDB("Service.db");
	//The schema
	/*
	TABLE 's' + m_strId
	ID NTEXT PRIMARY KEY NOT NULL
	*/
	string strSubName = "s" + m_strId;
	constexpr int nLengthData = 2;
	strTerms = { "ID NTEXT","AMOUNT INT" };
	strOptions = vector<string>(nLengthData, "NOT NULL");
	//If no table matches
	servDB.DeleteTable(strSubName);
	servDB.CreateTable(strSubName, strTerms, strOptions);
	for (int i = 0; i < nService; ++i)
	{
		strVals = { to_string(i),to_string(m_arrServDone[i]) };
		servDB.InsertValue(strSubName, strVals);
	}
}

vector<string> Waitor::CollectComment() const
{
	vector<string> strResults;
	for (auto &c : MainLogic::s_currentComments)
	{
		if (c.second.GetDishId() == m_strId)
		{
			strResults.push_back(c.first);
		}
	}
	return strResults;
}

void Waitor::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Waitor";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
	MyDataBase subDB("Service.db");
	string strSubName = "s" + m_strId;
	subDB.DeleteTable(strSubName);
}

tuple<vector<string>, int> Manager::CheckComment(const People & personWhoever)
{
	auto &&rComment = personWhoever.CollectComment();
	size_t sum = 0;
	for (auto t : rComment)
	{
		sum += MainLogic::s_currentComments[t].m_nStar;
	}
	if (rComment.size() != 0)
	{
		sum /= rComment.size();
	}
	return make_tuple(rComment, sum);
}

Manager::Manager(const string & strId, const string & strName, const string & strPassword, const string & strPhone)
	:People(strId, strName, strPassword, strPhone)
{

}

tuple<vector<string>, map<Cuisine, int>, int> Manager::CheckCook(const Cook & cookWhoever)
{
	auto res = CheckComment(cookWhoever);
	auto done = cookWhoever.GetWorkDone();
	return make_tuple(get<0>(res), done, get<1>(res));
}

tuple<vector<string>, array<int, nService>, int> Manager::CheckWaitor(const Waitor & waitorWhoever)
{
	auto res = CheckComment(waitorWhoever);
	auto done = waitorWhoever.GetServDone();
	return make_tuple(get<0>(res), done, get<1>(res));
}

void Manager::LoadInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 4;
	const string strTableName = "Manager";
	//The schema
	/*
	TABLE Manager
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_strPassword = strResults[2];
		m_strPhone = strResults[3];
	}
	strResults.clear();
}

void Manager::SaveInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strResults;
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),MainLogic::ToSql(m_strPassword),MainLogic::ToSql(m_strPhone) };
	constexpr int nLength = 4;
	const string strTableName = "Manager";
	//The schema
	/*
	TABLE Manager
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	vector<string> strTerms{ "ID NTEXT","NAME NTEXT","PASSWORD NTEXT","PHONE NTEXT" };
	vector<string> strOptions(nLength, "NOT NULL");
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
}

vector<string> Manager::CollectComment() const
{
	vector<string> strResults;
	for (auto &c : MainLogic::s_currentComments)
	{
		if (c.second.GetDishId() == m_strId)
		{
			strResults.push_back(c.first);
		}
	}
	return strResults;
}

void Manager::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Manager";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
}

Maintainer::Maintainer(const string & strId, const string & strName, const string & strPassword, const string &strPhone)
	:People(strId, strName, strPassword, strPhone)
{

}

void Maintainer::LoadInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!(theDB.IsReady() || theDB.IsProcess()))
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	constexpr int nLength = 4;
	const string strTableName = "Maintainer";
	//The schema
	/*
	TABLE Maintainer
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		return;
	}
	vector<string> strResults;
	theDB.QuerySelection(strTableName, strResults);
	//If the result is correct in form
	if (strResults.size() == nLength)
	{
		m_strId = strResults[0];
		m_strName = strResults[1];
		m_strPassword = strResults[2];
		m_strPhone = strResults[3];
	}
	strResults.clear();
}

void Maintainer::SaveInfo(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	vector<string> strResults;
	vector<string> strVals{ MainLogic::ToSql(m_strId),MainLogic::ToSql(m_strName),MainLogic::ToSql(m_strPassword),MainLogic::ToSql(m_strPhone) };
	constexpr int nLength = 4;
	const string strTableName = "Maintainer";
	//The schema
	/*
	TABLE Maintainer
	ID NTEXT PRIMARY KEY NOT NULL
	NAME NTEXT NOT NULL
	PASSWORD NTEXT NOT NULL
	PHONE NTEXT NOT NULL
	*/
	vector<string> strTerms{ "ID NTEXT","NAME NTEXT","PASSWORD NTEXT","PHONE NTEXT" };
	vector<string> strOptions(nLength, "NOT NULL");
	//Check the table is exist
	if (!theDB.IsTableExist(strTableName))
	{
		theDB.CreateTable(strTableName, strTerms, strOptions);
	}
	else
	{
		string strCondition = "ID = '" + m_strId + "'";
		theDB.DeleteValue(strTableName, strCondition);
	}
	theDB.InsertValue(strTableName, strVals);
}

vector<string> Maintainer::CollectComment() const
{
	//The maintainer always remains silent.
	return vector<string>();
}

void Maintainer::DeleteMe(MyDataBase & theDB)
{
	//Check the status of DataBase
	if (!theDB.IsReady())
	{
		throw runtime_error(theDB.GetErrorMessage());
	}
	if (theDB.m_strFileName != "Main.db")
	{
		//Wrong database
		throw invalid_argument(theDB.m_strFileName);
	}
	const string strTableName = "Maintainer";
	const string strCondition = "ID = '" + m_strId + "'";
	theDB.DeleteValue(strTableName, strCondition);
}

string IdGenerator(int nChar, size_t nRecord, int nDigits)
{
	string strRecord(std::to_string(nRecord + 1));
	size_t nCompensation = nDigits - 1 - strRecord.size();
	return std::to_string(nChar) + string(nCompensation, '0') + strRecord;
}