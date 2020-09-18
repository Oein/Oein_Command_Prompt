#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "dirent.hpp"
#include "String.hpp"
#include "Funtion.hpp"

#include "Command_Moudle_Includer.hpp"

using namespace std;

string directory = "/";
string username = "User";
string language_codea = "";
string Version = "17.1";

map<string, string> vars;
vector<string> variable_list;

void dir(vector<string> commands) {
	vector<string> result = get_files_in_folder(directory);

	if (result.size() == 0) return;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}

void set(vector<string> commands) {
	string result = "";

	for (int i = 1; i < commands.size(); i++) {
		result = result + commands[i] + " ";
	}

	result = result.substr(0, result.size());

	vector<string> a = split(result, '=');

	vars.insert(pair<string, string>(a[0], a[1]));
	variable_list.push_back(a[0]);

	return;
}

void cd(vector<string> commands) {
	string dirName = "";

	for (int i = 1; i < commands.size(); i++) {
		dirName = dirName + commands[i];
	}

	dirName = dirName.substr(0, dirName.size());

	if (dirName == "..") {
		if (directory != "/") {
			directory = directory.substr(0, get_last_slash_index(directory));
			directory = directory + "/";
			cout << GSBLC(language_code, "AS");
		}
	}
	else {
		directory = directory + dirName + "/";
		cout << GSBLC(language_code, "AS");
	}
}

string get_var_data(string key) {
	return vars[key];
}

wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void input_command(string command_string) {
	for (int i = 0; i < variable_list.size(); i++) {
		command_string = replace_all(command_string, "%" + variable_list[i] + "%", get_var_data(variable_list[i]));
	}

	vector<string> commands = split(command_string , ' ');

	if (commands.size() < 1) return;

	if (to_low(commands[0]) == "echo") { echo(commands); }
	if (to_low(commands[0]) == "bash") { bash(commands , &directory); }
	if (to_low(commands[0]) == "title") { title(commands); }
	if (to_low(commands[0]) == "dir") { dir(commands); }
	if (to_low(commands[0]) == "ls") { dir(commands); }
	if (to_low(commands[0]) == "timeout") { Sleep(atoi(commands[1].c_str())); }
	if (to_low(commands[0]) == "sleep") { Sleep(atoi(commands[1].c_str())); }
	if (to_low(commands[0]) == "mkdir") { make_dir(commands, &directory); }
	if (to_low(commands[0]) == "rmdir") { remove_dir(commands, &directory); }
	if (to_low(commands[0]) == "cd") { cd(commands); }
	if (to_low(commands[0]) == "set") { set(commands); }
	if (to_low(commands[0]) == "playsound") { playmusic(commands , &directory); }
	if (to_low(commands[0]) == "stopsound") { stopmusic(); }
	if (to_low(commands[0]) == "beep") { beep(commands); }
	if (to_low(commands[0]) == "help") { help(); }
	if (to_low(commands[0]) == "ver") { ver(Version); }
	if (to_low(commands[0]) == "vfile") { vfile(commands, &directory); }
}

void on_start() {
	init(&username , &language_codea);
	language_code = language_codea;

	ifstream in("var_list.ocp");

	char buf[1000];

	while (in) {
		in.getline(buf, 1000);
		
		variable_list.push_back(buf);
	}

	variable_list.push_back("username");
	variable_list.push_back("lang");

	cout << "Hello, " << username << "!\n";
}

string get_dir() {
	return directory;
}