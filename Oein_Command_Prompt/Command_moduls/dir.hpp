#pragma once

#include "include_module.hpp"

void make_dir(vector<string> commands, string* directory) {
	string path = *directory + commands[1];
	wstring path_w = L"";

	path_w.assign(path.begin(), path.end());

	int _errno_ = _wmkdir(path_w.c_str());

	if (_errno_ == 0) cout << GSBLC(language_code, "Success");
	else cout << GSBLC(language_code, "OE");

	return;
}

void remove_dir(vector<string> commands, string* directory) {
	string path = *directory + commands[1];
	wstring path_w = L"";

	path_w.assign(path.begin(), path.end());

	int _errno_ = _wrmdir(path_w.c_str());

	if (_errno_ == 0) cout << GSBLC(language_code, "Success");
	else cout << GSBLC(language_code, "OE");

	return;
}