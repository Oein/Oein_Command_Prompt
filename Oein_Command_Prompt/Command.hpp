#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "String.hpp"
#include "Funtion.hpp"

using namespace std;

string directory = "/";
string username = "User";

void input_command(string command_string) {
	command_string = replace_all(command_string, "%username%", username);

	vector<string> commands = split(command_string);

	if (commands.size() < 1) return;

	if (commands[0] == "echo") {
		if (commands.size() < 2) return;
		string out = "";

		for (int i = 1; i < commands.size(); i++) {
			out = out + commands[i] + " ";
		}

		cout << out;
	}
}

void on_start() {
	init(&username);
	cout << "Hello, " << username << "!\n";
}

string get_dir() {
	return directory;
}