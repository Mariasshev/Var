#pragma once
#include <iostream>
#include <string>
using namespace std;

class Var {
	int typeInt;
	double typeDouble;
	char* typeChar;
	string typeStr;
	int check;				//to check type of data 
public:
	Var();
	Var(int tInt);
	Var(double tDoub);
	Var(string tStr);
	Var(char* ch);

	void Show();
	void SetStr(string str);
	string GetStr()const;
	int GetSize()const;
	int GetCheck()const;
	int GetInt()const;
	double GetDouble()const;


	//converting
	int toInt()const;
	double toDouble()const;
	char* toChar() const;
	string toString()const;

	//copy constructor
	Var(const int& number);
	Var(const double& number);
	Var(const string& str);

	//=
	Var& operator = (const Var& obj);
	Var& operator = (const int& number);
	Var& operator = (const double& number);
	Var& operator = (const string& str);

	//operators
	const Var operator+(const Var& obj);		//+
	const Var& operator-(const Var& obj);		//-
	const Var& operator*(const Var& obj);		//*
	const Var& operator/(const Var& obj);		//   /

	Var& operator+=(const Var& obj);		//+=
	Var& operator-=(const Var& obj);		//-=
	Var& operator*=(const Var& obj);		//*=
	Var& operator/=(const Var& obj);		// /=


	bool operator>(const Var& obj);			//>
	bool operator<(const Var& obj);			//<
	bool operator ==(const Var& obj);		//==
	bool operator >=(const Var& obj);		//=>
	bool operator <=(const Var& obj);		//<=
	bool operator !=(const Var& obj);		//!=
};


Var operator+(const Var obj1, const Var obj2);
Var operator*(const Var obj1, const Var obj2);
Var operator/(const Var obj1, const Var obj2);
Var operator*=(const Var obj1, const Var obj2);
Var operator/=(const Var obj1, const Var obj2);