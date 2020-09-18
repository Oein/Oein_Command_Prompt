#pragma once

#include "include_module.hpp"

void playmusic(vector<string> commands , string* directory) {
	if (commands.size() < 2) return;

	string fn = *directory;
	LPCWSTR sw;

	for (int i = 1; i < commands.size(); i++) {
		fn = fn + commands[i];
	}

	fn = fn.substr(0, fn.size());

	wstring stemp = wstring(fn.begin(), fn.end());
	sw = stemp.c_str();

	PlaySound(sw, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void stopmusic() {
	PlaySound(NULL, NULL, SND_ASYNC);
}