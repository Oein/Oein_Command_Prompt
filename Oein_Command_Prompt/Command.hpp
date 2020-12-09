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

string directory = "C:/";
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

static constexpr uint32_t const_hash(const char* p) {
	return *p ? static_cast<uint32_t>(*p) + 33 * const_hash(p + 1) : 5381;
}

void input_command(string command_string) {
	for (int i = 0; i < variable_list.size(); i++) {
		command_string = replace_all(command_string, "%" + variable_list[i] + "%", get_var_data(variable_list[i]));
	}

	vector<string> commands = split(command_string, ' ');

	if (commands.size() < 1) return;

	//Dir º¯°æ
	if (command_string.size() == 2) {
		if (command_string[1] == ':') {
			directory = command_string + "/";
		}

		return;
	}

	uint32_t hash = const_hash(commands[0].c_str());

	switch (hash) {
	case const_hash("echo"):
		echo(commands);
		break;

	case const_hash("title"):
		title(commands);
		break;

	case const_hash("bash"):
		bash(commands, &directory);
		break;

	case const_hash("dir"):
		dir(commands);
		break;

	case const_hash("ls"):
		dir(commands);
		break;

	case const_hash("timeout"):
		Sleep(atoi(commands[1].c_str()));
		break;

	case const_hash("sleep"):
		Sleep(atoi(commands[1].c_str()));
		break;

	case const_hash("mkdir"):
		make_dir(commands, &directory);
		break;

	case const_hash("rmdir"):
		remove_dir(commands, &directory);
		break;

	case const_hash("cd"):
		cd(commands);
		break;

	case const_hash("set"):
		set(commands);
		break;

	case const_hash("playsound"):
		playmusic(commands, &directory);
		break;

	case const_hash("stopsound"):
		stopmusic();
		break;

	case const_hash("beep"):
		beep(commands);
		break;

	case const_hash("help"):
		help(commands.size() >= 2 ? commands[1] : "");
		break;

	case const_hash("ver"):
		ver(Version);
		break;

	case const_hash("vfile"):
		vfile(commands, &directory);
		break;

	case const_hash("cat"):
		vfile(commands, &directory);
		break;

	case const_hash("cls"):
		cls();
		break;

	case const_hash("piano"):
		piano();
		break;

	case const_hash("start"):
		start(commands , directory);
		break;

	default: 
		cout << commands[0] << " is not recognized as an internal or external command";
		break;
	}
}

void on_start() {
	on_start_help();
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