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
		return typeStr;
		break;
	}
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

const Var Var::operator+(const Var& obj)
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

const Var& Var::operator-(const Var& obj)
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

const Var& Var::operator*(const Var& obj)
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

const Var& Var::operator/(const Var& obj)
{
	switch (check) {
	case 0:
		typeInt /= obj.toInt();
		return *this;
		break;
	case 1:
		typeDouble /= obj.toDouble();
		return *this;
		break;
	case 2:
		typeStr /= obj.toString();
		return *this;
		break;
	}
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

const string operator+(const string& leftStr, const string& rightStr)
{
	string rez;
	for (int i = 0; i < strlen(leftStr.typeStr); i++) {

	}
	return string();
}
