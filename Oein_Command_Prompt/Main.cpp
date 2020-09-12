#include <iostream>
#include "String.hpp"
#include "Funtion.hpp"

using namespace std;

string directory = "/";
string userName = "User";

int main() {
	init(&userName);
	cout << userName;
}