#include "Var.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Var a = 15;
	Var b = "Hello";
	Var c = 7.8;
	Var d = "50";
	b = a + d;
	b.Show(); // Выведет 65
	if (a == b) cout << "Equal"; else cout << “Not Equal\n”;

}