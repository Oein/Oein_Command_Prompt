#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>
#include <map>

using namespace std;

typedef wstring str_t;

HWND myconsole = GetConsoleWindow();
HDC mydc = GetDC(myconsole);

map<string, map<string, string>> Language_map;

string GSBLC(string Language_code, string key);

bool is_dev = false;

void setpx (int x , int y , COLORREF COLOR){
	SetPixel(mydc, x, y, COLOR);

	ReleaseDC(myconsole, mydc);
}

void setfpx(int x, int y, int dx , int dy , COLORREF COLOR) {
	for (int i = x; i < dx; i++) {
		for (int j = y; j < dy; j++) {
			SetPixel(mydc, i, j, COLOR);
		}
	}

	ReleaseDC(myconsole, mydc);
}

void dl_(string msg) {
	if (is_dev == true) {
		cout << msg << '\n';
	}

	return;
}

void init(string * username , string * language_code) {
	ifstream in("dev.ocp");

	if (in.is_open()) {
		is_dev = true;
		dl_("dev mode on");
	}

	in.close();

	map<string, string> KOR;
	map<string, string> ENG;

	dl_("start to add kor lang map");
	KOR.insert(pair<string, string>("Hello", "안녕하세요? "));
	KOR.insert(pair<string, string>("Hello_b", "님?"));
	KOR.insert(pair<string, string>("Success", "성공!"));
	KOR.insert(pair<string, string>("RS", "읽기 성공!"));
	KOR.insert(pair<string, string>("OE", "에러!"));
	KOR.insert(pair<string, string>("AS", "액세스를 성공했습니다!"));
	dl_("complete add kor lang map");

	dl_("start to add eng lang map");
	ENG.insert(pair<string, string>("Hello", "Hello , "));
	ENG.insert(pair<string, string>("Hello_b", "!"));
	ENG.insert(pair<string, string>("Success", "Success!"));
	ENG.insert(pair<string, string>("RS", "Read Success!"));
	ENG.insert(pair<string, string>("OE", "Oops! Error!"));
	ENG.insert(pair<string, string>("AS", "Access succeeded!"));
	dl_("complete add eng lang map");

	dl_("add lang maps in main lang map");
	Language_map.insert(pair<string, map < string, string>>("KOR", KOR));
	Language_map.insert(pair<string, map < string, string>>("ENG", ENG));
	dl_("complete add lang maps in main lang map");

	dl_("open username.ocp");
	in.open("username.ocp");

	if (in.is_open() == true) {
		dl_("Success to read");
		string s = "";
		in >> s;
		*username = s;
		dl_("username seted!");
	}
	else {
		dl_("no username.ocp");
		dl_("make username.ocp");
		while (true)
		{
			ofstream out("username.ocp");

			if (out.is_open() == true) {
				out << "User";
				dl_("make username.ocp");
				out.close();
				break;
			}
		}
	}

	in.close();
	dl_("username.ocp closed");

	in.open("lang.ocp");
	dl_("lang.ocp opened");
	if (in.is_open() == true) {
		string s = "";
		in >> s;
		*language_code = s;
		dl_("lang code seted!");
	}
	else {
		dl_("no lang.ocp");
		dl_("make lang.ocp");
		while (true)
		{
			ofstream out("lang.ocp");

			if (out.is_open() == true) {
				out << "ENG";
				dl_("make lang.ocp");
				out.close();
				break;
			}
		}

		*language_code = "ENG";
	}

	in.close();

	return;
}

string Get_string_by_Language_Code(string Language_code, string key) {
	return Language_map[Language_code][key];
}

string GSBLC(string Language_code, string key) {
	return Get_string_by_Language_Code(Language_code, key);
}

vector<string> get_files_in_folder(string path)
{
	vector<string> result;
	DIR* dir_ptr = NULL;
	struct dirent* file = NULL;

	if ((dir_ptr = opendir(path.c_str())) == NULL) {
		return result;
	}

	while ((file = readdir(dir_ptr)) != NULL) {
		result.push_back(file->d_name);
	} 

	closedir(dir_ptr);

	return result;
}

string to_low(string a) {
	transform(a.begin(), a.end(), a.begin(), tolower);

	return a;
}

string to_high(string a) {
	transform(a.begin(), a.end(), a.begin(), toupper);

	return a;
}

int get_last_slash_index(string stringa) {
	int slash_index = stringa.size();
	int slash_indext = stringa.size();

	for (int i = 0; i < stringa.size(); i++) {
		if (stringa[i] == '/') {
			slash_indext = slash_index;
			slash_index = i;
		}
	}

	return slash_indext == stringa.size() ? slash_index : slash_indext;
}