#pragma once

#include "include_module.hpp"

void title(vector<string> commands) {
	if (commands.size() < 2) return;
	string out = "";

	for (int i = 1; i < commands.size(); i++) {
		out = out + commands[i] + " ";
	}

	string a = "title " + out;

	system(a.c_str());
}