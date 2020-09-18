#pragma once

#include "include_module.hpp"

void vfile(vector<string> commands , string* directory) {
	if (commands.size() < 2) return;
	ifstream in(*directory + replace_all(commands[1], "@", " "));
	if (in.is_open()) {
		cout << GSBLC(language_code, "RS") << "\n\n";
		string s;
		in >> s;
		cout << s;
	}
	else {
		cout << GSBLC(language_code, "OE") << '\n';
	}
}