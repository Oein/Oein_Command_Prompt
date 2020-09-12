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

	if (commands[0] == "bash") {
		if (commands.size() < 2) return;
		ifstream in(directory + commands[1]);

		if (in.is_open() == true) {
			char buffer[10000];

			while (in) {
				in.getline(buffer, 10000);
				input_command(buffer);
			}
		}
		else {
			cout << "Oops! Error! \nThere is no file!";
		}
	}
}

void on_start() {
	init(&username);
	cout << "Hello, " << username << "!\n";
}

string get_dir() {
	return directory;
}