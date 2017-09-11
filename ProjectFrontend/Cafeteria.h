/*
**Cafeteria,h
**This file defines all classes used in the backend.
**Usage of DataBases:
**Main.db - Overall information and indecies
**OrderFood.db - Food list in every order
**CookWork.db - Work done by every cook
**Menu.db - Food code list in every order
**Service.db - Service by every waitor
*/

#pragma once
#ifndef CAFETERIA_H

#define CAFETERIA_H

#include "MySQLite.h"
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <deque>
#include <array>
#include <tuple>
#include <algorithm>

using std::string;
using std::map;
using std::vector;
using std::deque;
using std::array;
using std::pair;
using std::tuple;

/*
**class Object
**The base class of all the other classes
*/
class Object
{
protected:
	string m_strName;	//Its name
	string m_strId;		//Its ID
public:
	//Constructors
	Object(const string & strId = "", const string & strName = "");
	//Properties
	virtual void SetName(const string & strName);
	virtual string GetName() const;
	virtual void SetId(const string & strId);
	virtual string GetId() const;
	//Operators
	virtual bool operator == (const Object &obj) const;
	virtual bool operator < (const Object &obj) const;
	virtual bool operator > (const Object &obj) const;
	virtual bool operator != (const Object &obj) const;
	//Destructor
	virtual ~Object();
	//Interfaces
	virtual void LoadInfo(MyDataBase &) = 0;
	virtual void SaveInfo(MyDataBase &) = 0;
	virtual void DeleteMe(MyDataBase &) = 0;
};

/*
**class People
**The class is the basis of all types of people.
*/
class People :public Object
{
protected:
	string m_strPassword;		//The password
public:
	//Constructors
	People(const string & strId = "", const string & strName = "", const string & strPassword = "");
	//Properties
	virtual void SetPassword(const string & strPassword);
	virtual string GetPassword() const;
	//Destructor
	virtual ~People();
	//Interfaces
	virtual void LoadInfo(MyDataBase &) = 0;
	virtual void SaveInfo(MyDataBase &) = 0;
	virtual vector<string> CollectComment() const = 0;
	virtual void DeleteMe(MyDataBase &) = 0;
};

/*
**class Comment
**The class defines a piece of comment.
*/
class Comment :public Object
{
protected:
	string m_strUserId;		//Who
	string m_strDishId;		//What
	string m_strDate;		//When
public:
	int m_nStar;			//Stars
	string m_strContent;	//Content
							//Constructors
	Comment(const string & strId = "", const string & strName = "",
		const string & strUserId = "", const string & strDishId = "", const string & strDate = "");
	//Properties
	virtual void SetUserId(const string & strUserId);
	virtual string GetUserId() const;
	virtual void SetDishId(const string & strDishId);
	virtual string GetDishId() const;
	virtual void SetDate(const string & strDate);
	virtual string GetDate() const;
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**class Cuisine
**The class defines a cuisine.
*/
class Cuisine :public Object
{
protected:
	int m_nPrice;	//Its price
public:
	//Constructors
	Cuisine(const string & strId = "", const string & strName = "",
		const int nPrice = 0);
	//Properties
	virtual void SetPrice(const int nPrice);
	virtual int GetPrice() const;
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**class Order
**This class defines an order.
*/
class Order :public Object
{
protected:
	map<Cuisine, int> m_mapOrderFood;	//Food Ordered
	string m_strCustomerId;				//Customer's Id
	string m_strWaitorId;				//Waitor's Id
	int m_nTableNum;					//The table number
public:
	map<Cuisine, int> m_mapBill;				//Bill's subtotal
	map<Cuisine, int> m_mapFoodToDo;	//Food in service
	//Constructors
	Order(const string & strId = "", const string & strName = "", const string & strCustomerId = "", const string & strWaitorId = "");
	//Properties
	virtual void SetCustomerId(const string & strCustomerId);
	virtual string GetCustomerId() const;
	virtual void SetWaitorId(const string & strWaitorId);
	virtual string GetWaitorId() const;
	virtual map<Cuisine, int> GetFoodMap() const;
	virtual void SetFoodMap(const map<Cuisine, int> &mapOrderFood);
	virtual void SetTableNum(const int &nTableNum);
	virtual int GetTableNum() const;
	//Behaviours
	virtual void Adjust(const Cuisine theDish, int nAmount);		//Add Some dishes to the order		
	virtual int CheckOut();										//Payment
	virtual void Assign();										//Assign the task to a cook
	virtual void Consume(const Cuisine theDish);				//A dish served
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**class Customer
**The class describes a customer.
*/
class Customer :public People
{
protected:
	int m_nState;									//The status of the customer
	int m_nTableNum;								//Table number
public:
	map<string, Order>::iterator m_itNow;			//The iter to current order
	map<string, string> m_statusComment;			//The status of comments made of cuisine
	map<string, string> m_waitorComment;			//Waitor comment status
	//Constructors
	Customer(const string & strId = "", const string & strName = "",
		const string & strPassword = "");
	//Properties
	virtual void SetState(const int nState);
	virtual int GetState() const;
	virtual int GetTableNum() const;
	virtual const map<string, Order>::iterator GetCurrrentOrder() const;
	//Behaviours
	virtual string MakeOrder();										//Submit the order
	virtual void Finish();											//Finish and leave
	virtual void GetSeat(const int nTable, const string & strName); //Begin order making
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual vector<string> CollectComment() const;
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**enum CSSTATE
**It describes the customer's state.
*/
enum CSSTATE
{
	Absent = 0,
	Make = 1,
	Eat = 2
};

/*
**class Cook
**The class defines a cook.
*/
class Cook :public People
{
protected:
	map<Cuisine, int> m_mapWorkDone;				//Dishes done
public:
	deque<pair<Cuisine, Order*>> m_deqTodo;			//The one to do
	//Constructors
	Cook(string strId = "", string strName = "", string strPassword = "");
	//Properties
	virtual deque<pair<Cuisine, Order*>> GetToDoList() const;
	virtual map<Cuisine, int> GetWorkDone() const;
	//Behaviours
	virtual void Pick(const pair<Cuisine, Order*> theDishByOrder);		//Pick one todo
	virtual bool IsIdle();												//Get the state
	virtual void DoCooking(deque<pair<Cuisine, Order*>>::iterator itCuisine);											//Cook a portion of cuisine
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual vector<string> CollectComment() const;
	virtual void DeleteMe(MyDataBase &theDB);
};

constexpr int nService = 4;		//Appoint the types of services.

/*
**class Waitor
**The class defines a waitor.
*/
class Waitor :public People
{
protected:
	array<int, nService> m_arrServDone;
	int m_nTableNum;
public:
	deque<pair<Cuisine, Order*>> m_deqReady;
	deque<int> m_deqTodo;
	//Constructors
	Waitor(const string & strId = "", const string & strName = "", const string & strPassword = "");
	//Properties
	virtual void SetTableNum(const int & nTableNum);
	virtual int GetTableNum() const;
	virtual array<int, nService> GetServDone() const;
	//Behaviours
	virtual void Liberate();
	virtual void ServePlate(deque<pair<Cuisine, Order*>>::iterator itCuisine);
	virtual void DoDemand(deque<int>::iterator itDemand);
	virtual bool IsIdle();
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual vector<string> CollectComment() const;
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**enum SRVS
**It describes the service of waitors.
*/
enum SRVS
{
	Plate = 0,
	Water = 1,
	Package = 2,
	Hasten = 3
};

/*
**class Manager
**The class defines a manager
*/
class Manager :public People
{
private:
	//Behaviours
	virtual tuple<vector<string>, int> CheckComment(const People & personWhoever);
public:
	//Constructors
	Manager(const string & strId = "", const string & strName = "", const string & strPassword = "");
	//Behaviours
	virtual tuple<vector<string>, map<Cuisine, int>, int> CheckCook(const Cook & cookWhoever);
	virtual tuple<vector<string>, array<int, nService>, int> CheckWaitor(const Waitor & waitorWhoever);
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual vector<string> CollectComment() const;
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**class Maintainer
**The class defines a maintainer of this system.
*/
class Maintainer :public People
{
public:
	//Constructors
	Maintainer(const string & strId = "", const string & strName = "", const string & strPassword = "");
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual vector<string> CollectComment() const;
	virtual void DeleteMe(MyDataBase &theDB);
};

/*
**class MainLogic
**It wrap the main procedure of the backend.
**It is designed as a single instance class.
*/
class MainLogic final
{
private:
	//Internal Actions
	MainLogic();
	~MainLogic();
	static MainLogic *m_pInstance;						//The unqiue instance of the app
public:
	//External Actions
	static MainLogic* GetInstance();
	static void DestroyInstance();
	static string ToSql(const string & str);
	static map<string, Cuisine> s_currentMenu;			//1st
	static map<string, Order> s_currentOrders;			//2nd
	static map<string, Customer> s_currentCustomers;	//3rd
	static map<string, Comment> s_currentComments;		//4th
	static map<string, Cook> s_currentCooks;			//5th
	static map<string, Waitor> s_currentWaitors;		//6th
	static map<string, Manager> s_currentManagers;		//7th
	static map<string, Maintainer> s_currentMaintainers;//8th
	void Initialise();
	void Finalise();
	People * FindExist(const string &strName);			//Find someone exists
	People *pUser;										//The controller who is using this app
	MyDataBase MainDB;									//Main Database
	vector<char> arrSeatVacance;						//The seat vacancies  0 = no 1 = yes without using vector<bool>
};

#endif 
