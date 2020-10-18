#pragma once

#include "Command_Moudle_Includer.hpp"

void start(vector<string> commands , string dir) {
	string file = "";
	for (int i = 1; i < commands.size(); i++) {
		file = file + commands[i] + " ";
	}

	file = file.substr(0, file.size());
	file = dir + file;
	system(file.c_str());
}