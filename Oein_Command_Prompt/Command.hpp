#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <mmsystem.h>
#include "dirent.hpp"
#include "String.hpp"
#include "Funtion.hpp"
#include "Beep_piano.hpp"

#pragma comment(lib,"winmm.lib")

using namespace std;

string directory = "/";
string username = "User";
string language_code = "";

map<string, string> vars;
vector<string> variable_list;

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

	if (_errno_ == 0) cout << GSBLC(language_code , "Success");
	else cout << GSBLC(language_code, "OE");

	return;
}

void remove_dir(vector<string> commands) {
	string path = directory + commands[1];
	wstring path_w = L"";

	path_w.assign(path.begin(), path.end());

	int _errno_ = _wrmdir(path_w.c_str());

	if (_errno_ == 0) cout << GSBLC(language_code, "Success");
	else cout << GSBLC(language_code, "OE");

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

void playmusic(vector<string> commands) {
	if (commands.size() < 2) return;

	string fn = directory;
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

void beep(vector<string> commands) {
	if (commands[1] == "1C") 
}

void input_command(string command_string) {
	for (int i = 0; i < variable_list.size(); i++) {
		command_string = replace_all(command_string, "%" + variable_list[i] + "%", get_var_data(variable_list[i]));
	}

	vector<string> commands = split(command_string , ' ');

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
	if (to_low(commands[0]) == "set") { set(commands); }
	if (to_low(commands[0]) == "playsound") { playmusic(commands); }
	if (to_low(commands[0]) == "stopsound") { stopmusic(); }
	if (to_low(commands[0]) == "beep") { beep(commands); }
}

void on_start() {
	init(&username , &language_code);

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