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

	//converting
	int toInt()const;
	double toDouble()const;
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

	string operator *=(const string& obj);
	string operator /=(const string& obj);

	bool operator>(const Var& obj);			//>
	bool operator<(const Var& obj);			//<
	bool operator ==(const Var& obj);		//==
	bool operator >=(const Var& obj);		//=>
	bool operator <=(const Var& obj);		//<=
	bool operator !=(const Var& obj);		//!=
};

//
const string operator + (const string& leftStr, const string& rightStr);
const string operator * (const string& leftStr, const string& rightStr);
const string operator / (const string& leftStr, const string& rightStr);
