/*
**ProjectBackend,h
**This file defines all classes used in the backend.
**Usage of DataBases:
**Main.db - Overall information and indecies
**OrderFood.db - Food list in every order
**CookWork.db - Work done by every cook
**Service.db - Service by every waitor
*/

#pragma once

#ifndef PROJECTBACKEND_H

#define PROJECTBACKEND_H

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
	string m_strPhone;			//The phone number to login
	string m_strPassword;		//The password
public:
	//Constructors
	People(const string & strId = "", const string & strName = "", const string & strPassword = "", const string & strPhone = "");
	//Properties
	virtual void SetPassword(const string & strPassword);
	virtual string GetPassword() const;
	virtual void SetPhone(const string & strPhone);
	virtual string GetPhone() const;
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
**enum CCG
**CuisineCateGory describes the kind of each cuisine.
*/
enum CCG
{
	STPL = 0,
	MEAT = 1,
	VEGE = 2,
	DESS = 3,
	BEVE = 4,
	SOUP = 5,
	SEAF = 6,
	SETM = 7
};

constexpr int nCategory = 8;

/*
**class Cuisine
**The class defines a cuisine.
*/
class Cuisine :public Object
{
protected:
	double m_dPrice;	//Its price
	int m_nCate;		//Its category
public:
	//Constructors
	Cuisine(const string & strId = "", const string & strName = "",
		const double dPrice = 0.0, const int nCate = 0);
	//Properties
	virtual void SetPrice(const double dPrice);
	virtual double GetPrice() const;
	virtual void SetCate(const int nCate);
	virtual int GetCate() const;
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
private:
	bool bAssigned;						//Just assigned once
protected:
	map<Cuisine, int> m_mapOrderFood;	//Food Ordered
	string m_strCustomerId;				//Customer's Id
	string m_strWaitorId;				//Waitor's Id
	int m_nTableNum;					//The table number
public:
	map<Cuisine, double> m_mapBill;				//Bill's subtotal
	map<Cuisine, int> m_mapFoodToDo;			//Food in service
	//Constructors
	Order(const string & strId = "", const string & strName = "", 
		const string & strCustomerId = "", const string & strWaitorId = "");
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
	virtual void Adjust(const Cuisine theDish, int nAmount);	//Add Some dishes to the order		
	virtual double CheckOut();										//Payment
	virtual void Assign();										//Assign the task to a cook
	virtual void Consume(const Cuisine theDish);				//A dish served
	virtual string Appoint();									//Bind an idle waitor if no one serves
	virtual bool IsServed();									//Check if there is a waitor serving
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
		const string & strPassword = "", const string & strPhone = "");
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
	Cook(const string  & strId = "",const string & strName = "",
		const string & strPassword = "",const string & strPhone = "");
	//Properties
	virtual deque<pair<Cuisine, Order*>> GetToDoList() const;
	virtual map<Cuisine, int> GetWorkDone() const;
	//Behaviours
	virtual void Pick(const pair<Cuisine, Order*> theDishByOrder);				//Pick one todo
	virtual bool IsIdle();														//Get the state
	virtual void DoCooking(deque<pair<Cuisine, Order*>>::iterator itCuisine);	//Cook a portion of cuisine
	//Interfaces
	virtual void LoadInfo(MyDataBase &theDB);
	virtual void SaveInfo(MyDataBase &theDB);
	virtual vector<string> CollectComment() const;
	virtual void DeleteMe(MyDataBase &theDB);
};

constexpr int nService = 4;		//Assign the types of services.

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
	Waitor(const string & strId = "", const string & strName = "",
		const string & strPassword = "", const string & strPhone = "");
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
	Manager(const string & strId = "", const string & strName = "", 
		const string & strPassword = "", const string & strPhone = "");
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
	Maintainer(const string & strId = "", const string & strName = "", 
		const string & strPassword = "", const string & strPhone = "");
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
**This class cannot be derived.
*/
class MainLogic final
{
private:
	//Internal Actions
	MainLogic();										//Constructor
	~MainLogic();										//Destructor
	static MainLogic * m_pInstance;						//The unqiue instance of the app
public:
	//External Actions
	static MainLogic * GetInstance();					//Get or create the instance of MainLogic
	static void DestroyInstance();						//Destroy the instance of MainLogic
	static string ToSql(const string & str);			//Wrap a string by adding a pair of ''
	void Initialise();									//Loading all data
	void Finalise();									//Saving all data
	People * FindExist(const string &strName);			//Find someone exists
	People * pUser;										//The controller who is using this app
	MyDataBase MainDB;									//Main Database
	//Data Units
	vector<char> arrSeatVacance;						//The seat vacancies  0 = no 1 = yes replacing vector<bool>
	static map<string, Cuisine> s_currentMenu;			//1st
	static map<string, Order> s_currentOrders;			//2nd
	static map<string, Customer> s_currentCustomers;	//3rd
	static map<string, Comment> s_currentComments;		//4th
	static map<string, Cook> s_currentCooks;			//5th
	static map<string, Waitor> s_currentWaitors;		//6th
	static map<string, Manager> s_currentManagers;		//7th
	static map<string, Maintainer> s_currentMaintainers;//8th
};

// Id regulations
enum IDGENERATOR
{
	ID_COMMENT,
	ID_CUISINE,
	ID_ORDER,
	ID_CUSTOMER,
	ID_COOK,
	ID_WAITOR,
	ID_MANAGER,
	ID_MAINTAINER
};
/*
**enum CharSel
**It denote the character of People.
*/
enum CharSel { CH_CUSTOMER, CH_MAINTAINER, CH_COOK, CH_WAITOR, CH_MANAGER };
/*
**Function: Id Generator
**This functions returns the new id of an object based on the nRecord.
**Parametres:
**nChar: the character in CharSel
**nRecord: the last one in map
**nDigits: the length of the new id
*/
string IdGenerator(int nChar, size_t nRecord, int nDigits = 6);

#endif 
