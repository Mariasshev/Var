#include "Var.h"
#include <iostream>
#include <string>
using namespace std;

Var::Var()
{
	check = -1;	
	typeInt = 0;
	typeDouble = 0;
	typeChar = nullptr;
	typeStr = ' ';
}

Var::Var(int tInt)
{
	check = 0;
	typeInt = tInt;
}

Var::Var(double tDoub)
{
	check = 1;
	typeDouble = tDoub;
}

Var::Var(string tStr)
{
	check = 2;
	typeStr = tStr;
}

Var::Var(char* ch)
{
	check = 2;
	typeChar = ch;
	string str(typeChar, sizeof(typeChar));
}

void Var::Show()
{
	switch (check) {
	case 0:
		cout << typeInt;
		break;
	case 1:
		cout << typeDouble;
		break;
	case 2:
		cout << typeStr;
		break;
	}
}

void Var::SetStr(string str)
{
	typeStr = str;
}

string Var::GetStr()const
{
	return typeStr;
}

int Var::GetSize()const
{
	return typeStr.length();
}

int Var::GetCheck()const
{
	return check;
}

int Var::GetInt() const
{
	return typeInt;
}

double Var::GetDouble() const
{
	return typeDouble;
}

int Var::toInt()const
{
	switch (check) {
	case 0:
		return typeInt;
		break;
	case 1:
		return (int)typeDouble;
		break;
	case 2:
		return atoi(typeStr.c_str());
		break;
	}
}

double Var::toDouble()const
{
	switch (check) {
	case 0:
		return (double)typeInt;
		break;
	case 1:
		return typeDouble;
		break;
	case 2:
		return atof(typeStr.c_str());
		break;
	}
}

string Var::toString()const
{
	switch (check) {
	case 0:
		return to_string(typeInt);
		break;
	case 1:
		return to_string(typeDouble);
		break;
	case 2:
		return string(typeStr);
		break;
	}
	return string(toChar());
}


char* Var::toChar() const
{
	char* tmpStr = new char[30];
	switch (check)
	{
	case 0:
		return itoa(typeInt, tmpStr, 10);
	case 1:
		sprintf(tmpStr, "%lf", typeDouble);
		return tmpStr;
	case 2:
		strcpy(tmpStr, (typeStr).c_str());
		return tmpStr;
	}
	return NULL;
}


Var::Var(const int& number)
{
	typeInt = number;
}

Var::Var(const double& number)
{
	typeDouble = number;
}

Var::Var(const string& str)
{
	typeStr = str;
}

Var& Var::operator=(const Var& obj)
{
	if (this != &obj) {
		switch (check) {
		case 0:
			typeInt = 0;
			break;
		case 1:
			typeDouble = 0;
			break;
		case 2:
			typeStr = ' ';
			break;
		}

		switch (obj.check) {
		case 0:
			typeInt = obj.typeInt;
			break;
		case 1:
			typeDouble = obj.typeDouble;
			break;
		case 2:
			typeStr = obj.typeStr;
			break;
		}
		this->check = obj.check;
	}
	return *this;
}

Var& Var::operator=(const int& number)
{
	switch (check) {
	case 0:
		typeInt = 0;
		break;
	case 1:
		typeDouble = 0;
		break;
	case 2:
		typeStr = ' ';
		break;
	}
	typeInt = number;
	check = 0;
	return *this;
}

Var& Var::operator=(const double& number)
{
	switch (check) {
	case 0:
		typeInt = 0;
		break;
	case 1:
		typeDouble = 0;
		break;
	case 2:
		typeStr = ' ';
		break;
	}
	typeDouble = number;
	check = 1;
	return *this;
}

Var& Var::operator=(const string& str)
{
	switch (check) {
	case 0:
		typeInt = 0;
		break;
	case 1:
		typeDouble = 0;
		break;
	case 2:
		typeStr = ' ';
		break;
	}
	typeStr = str;
	check = 2;
	return *this;
}

void Var::operator+(const Var obj)
{
	if (check == obj.check) {
		switch (check) {
		case 0:
			typeInt = typeInt + obj.typeInt;
			break;
		case 1:
			typeDouble = typeDouble + obj.typeDouble;
			break;
		case 2:
			typeStr = typeStr + obj.typeStr;
			break;
		}
	}

	//int +
	if (check == 0) {
		switch (obj.check) {
		case 0:
			typeInt = typeInt + obj.typeInt;
			break;
		case 1:
			typeInt = typeInt + obj.typeDouble;
			break;
		case 2:
			typeInt = typeInt + stoi(obj.typeStr);
			break;
		}
	}

	//double +
	if (check == 1) {
		switch (obj.check) {
		case 0:
			typeDouble = typeDouble + obj.typeInt;
			break;
		case 1:
			typeDouble = typeDouble + obj.typeDouble;
			break;
		case 2:
			typeDouble = typeDouble + stod(obj.typeStr);
			break;
		}
	}

	//str +
	if (check == 2) {
		switch (obj.check) {
		case 0:
			typeStr = typeStr + to_string(obj.typeInt);
			break;
		case 1:
			typeStr = typeStr + to_string(obj.typeDouble);
			break;
		}
	}

}

void Var::operator-(const Var obj)
{
	if (check == obj.check) {
		switch (check) {
		case 0:
			typeInt = typeInt - obj.typeInt;
			break;
		case 1:
			typeDouble = typeDouble - obj.typeDouble;
			break;
		case 2:
			typeStr = " ";
			break;
		}
	}

	//int -
	if (check == 0) {
		switch (obj.check) {
		case 0:
			typeInt = typeInt - obj.typeInt;
			break;
		case 1:
			typeInt = typeInt - obj.typeDouble;
			break;
		case 2:
			typeInt = typeInt - stoi(obj.typeStr);
			break;
		}
	}

	//double -
	if (check == 1) {
		switch (obj.check) {
		case 0:
			typeDouble = typeDouble - obj.typeInt;
			break;
		case 1:
			typeDouble = typeDouble - obj.typeDouble;
			break;
		case 2:
			typeDouble = typeDouble - stod(obj.typeStr);
			break;
		}
	}

	//str -
	if (check == 2) {
		switch (obj.check) {
		case 0:
			typeStr = stoi(typeStr) - obj.typeInt;
			break;
		case 1:
			typeStr = stod(typeStr) - obj.typeDouble;
			break;
		}
	}
}

void Var::operator*(const Var obj)
{
	return Var();
}

 Var Var::operator+(const Var& obj)
{
	switch (check) {
	case 0:
		return Var(typeInt + obj.toInt());
		break;
	case 1:
		return Var(typeDouble + obj.toDouble());
		break;
	case 2:
		return Var(typeStr + obj.toString());
		break;
	}
	return *this;
}

 Var& Var::operator-(const Var& obj)
{
	switch (check) {
	case 0:
		return Var(typeInt - obj.toInt());
		break;
	case 1:
		return Var(typeDouble - obj.toDouble());
		break;
	case 2:
		return Var(typeStr - obj.toString());
		break;
	}
	return *this;
}

 Var& Var::operator*(const Var obj)
{
	switch (check) {
	case 0:
		return Var(typeInt * obj.toInt());
		break;
	case 1:
		return Var(typeDouble * obj.toDouble());
		break;
	case 2:
		return Var(typeStr * obj.toString());
		break;
	}
	return *this;
}

 Var& Var::operator/(const Var obj)
{
	switch (check) {
	case 0:
		typeInt = typeInt / obj.toInt();
		return *this;
		break;
	case 1:
		typeDouble = typeDouble / obj.toDouble();
		return *this;
		break;
	return *this;
}

Var& Var::operator+=(const Var& obj)
{
	switch (check) {
	case 0:
		typeInt = typeInt + obj.toInt();
		return *this;
		break;
	case 1:
		typeDouble = typeDouble + obj.toDouble();
		return *this;
		break;
	case 2:
		typeStr = typeStr + obj.toString();
		return *this;
		break;
	}
	return *this;
}

Var& Var::operator-=(const Var& obj)
{
	switch (check) {
	case 0:
		typeInt = typeInt - obj.toInt();
		return *this;
		break;
	case 1:
		typeDouble = typeDouble - obj.toDouble();
		return *this;
		break;
	case 2:
		typeStr = typeStr - obj.toString();
		return *this;
		break;
	}
	return *this;
}

Var& Var::operator*=(const Var& obj)
{
	switch (check) {
	case 0:
		typeInt = typeInt * obj.toInt();
		return *this;
		break;
	case 1:
		typeDouble = typeDouble * obj.toDouble();
		return *this;
		break;
	case 2:
		typeStr = typeStr * obj.toString();
		return *this;
		break;
	}
	return *this;
}

Var& Var::operator/=(const Var& obj)
{
	switch (check) {
	case 0:
		typeInt = typeInt / obj.toInt();
		return *this;
		break;
	case 1:
		typeDouble = typeDouble / obj.toDouble();
		return *this;
		break;
	case 2:
		typeStr = typeStr / obj.toString();
		return *this;
		break;
	}
	return *this;
}



bool Var::operator>(const Var& obj)
{
	switch (check) {
	case 0:
		//if (typeInt > obj.toInt()) {return true;}
		return typeInt > obj.toInt();
		break;
	case 1:
		return typeDouble > obj.toDouble();
		break;
	case 2:
		return typeStr > obj.toString();
		break;
	}
	return false;
}

bool Var::operator<(const Var& obj)
{
	switch (check) {
	case 0:
		return typeInt < obj.toInt();
		break;
	case 1:
		return typeDouble < obj.toDouble();
		break;
	case 2:
		return typeStr < obj.toString();
		break;
	}
	return false;
}

bool Var::operator==(const Var& obj)
{
	switch (check) {
	case 0:
		return typeInt == obj.toInt();
		break;
	case 1:
		return typeDouble == obj.toDouble();
		break;
	case 2:
		return typeStr == obj.toString();
		break;
	}
	return false;
}

bool Var::operator>=(const Var& obj)
{
	switch (check) {
	case 0:
		return typeInt >= obj.toInt();
		break;
	case 1:
		return typeDouble >= obj.toDouble();
		break;
	case 2:
		return typeStr >= obj.toString();
		break;
	}
	return false;
}

bool Var::operator<=(const Var& obj)
{
	switch (check) {
	case 0:
		return typeInt <= obj.toInt();
		break;
	case 1:
		return typeDouble <= obj.toDouble();
		break;
	case 2:
		return typeStr <= obj.toString();
		break;
	}
	return false;
}

bool Var::operator!=(const Var& obj)
{
	switch (check) {
	case 0:
		return typeInt != obj.toInt();
		break;
	case 1:
		return typeDouble != obj.toDouble();
		break;
	case 2:
		return typeStr != obj.toString();
		break;
	}
	return false;
}

Var operator+(const Var obj1, const Var obj2)
{
	if (obj1.GetCheck() == obj2.GetCheck()) {
		switch (obj1.GetCheck()) {
		case 0:
			return obj1.GetInt() + obj2.GetInt();
			break;
		case 1:
			return obj1.GetDouble() + obj2.GetDouble();
			break;
		case 2:
			return obj1.GetStr() + obj2.GetStr();
			break;
		}
	}

	if (obj1.GetCheck() == 0) {				//int + 
		switch (obj2.GetCheck()) {
		case 0:
			return obj1.GetInt() + obj2.GetInt();
			break;
		case 1:
			return obj1.GetInt() + obj2.GetDouble();
			break;
		case 2:
			return obj1.GetInt() + stoi(obj2.GetStr());
			break;
		}
	}

	if (obj1.GetCheck() == 1) {				//double + 
		switch (obj2.GetCheck()) {
		case 0:
			return obj1.GetDouble() + obj2.GetInt();
			break;
		case 1:
			return obj1.GetDouble() + obj2.GetDouble();
			break;
		case 2:
			return obj1.GetDouble() + stod(obj2.GetStr());
			break;
		}
	}

	if (obj1.GetCheck() == 2) {				//str + 
		switch (obj2.GetCheck()) {
		case 0:
			return obj1.GetStr() + to_string(obj2.GetInt());
			break;
		case 1:
			return obj1.GetStr() + to_string(obj2.GetDouble());
			break;
		case 2:
			return obj1.GetStr() + obj2.GetStr();
			break;
		}
	}
	
}
