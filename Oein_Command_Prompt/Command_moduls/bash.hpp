#pragma once

#include "include_module.hpp"
#include "../Command.hpp"

void input_command(string command_string);

void bash(vector<string> commands , string* directory) {
	if (commands.size() < 2) return;
	ifstream in(*directory + commands[1]);

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