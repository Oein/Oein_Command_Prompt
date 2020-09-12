#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "dirent.hpp"
#include "String.hpp"
#include "Funtion.hpp"

using namespace std;

string directory = "/";
string username = "User";

void input_command(string command_string);

void echo(vector<string> commands) {
	if (commands.size() < 2) return;
	string out = "";

	for (int i = 1; i < commands.size(); i++) {
		out = out + commands[i] + " ";
	}

	cout << out << '\n';
}

void title(vector<string> commands) {
	if (commands.size() < 2) return;
	string out = "";

	for (int i = 1; i < commands.size(); i++) {
		out = out + commands[i] + " ";
	}

	string a = "title " + out;

	system(a.c_str());
}

void bash(vector<string> commands){
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

void dir(vector<string> commands) {
	vector<string> result = get_files_in_folder(directory);

	if (result.size() == 0) return;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}

void make_dir(vector<string> commands) {
	string path = directory + commands[1];
	wstring path_w = L"";

	path_w.assign(path.begin(), path.end());

	int _errno_ = _wmkdir(path_w.c_str());

	if (_errno_ == 0) cout << "Success!";
	else cout << "Oops! Error!";

	return;
}

void remove_dir(vector<string> commands) {
	string path = directory + commands[1];
	wstring path_w = L"";

	path_w.assign(path.begin(), path.end());

	int _errno_ = _wrmdir(path_w.c_str());

	if (_errno_ == 0) cout << "Success!";
	else cout << "Oops! Error!";

	return;
}

void cd(vector<string> commands) {
	string dirName = "";

	for (int i = 1; i < commands.size(); i++) {
		dirName = dirName + commands[i];
	}

	dirName = dirName.substr(0, dirName.size());

	directory = directory + dirName + "/";
}

void input_command(string command_string) {
	command_string = replace_all(command_string, "%username%", username);

	vector<string> commands = split(command_string);

	if (commands.size() < 1) return;

	if (to_low(commands[0]) == "echo") { echo(commands); }
	if (to_low(commands[0]) == "bash") { bash(commands); }
	if (to_low(commands[0]) == "title") { title(commands); }
	if (to_low(commands[0]) == "dir") { dir(commands); }
	if (to_low(commands[0]) == "ls") { dir(commands); }
	if (to_low(commands[0]) == "timeout") { Sleep(atoi(commands[1].c_str())); }
	if (to_low(commands[0]) == "sleep") { Sleep(atoi(commands[1].c_str())); }
	if (to_low(commands[0]) == "mkdir") { make_dir(commands); }
	if (to_low(commands[0]) == "rmdir") { remove_dir(commands); }
	if (to_low(commands[0]) == "cd") { cd(commands); }
}

void on_start() {
	init(&username);
	cout << "Hello, " << username << "!\n";
}

string get_dir() {
	return directory;
}