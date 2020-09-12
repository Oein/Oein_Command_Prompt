#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

typedef wstring str_t;

HWND myconsole = GetConsoleWindow();
HDC mydc = GetDC(myconsole);

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

void init(string * username) {
	ifstream in("username.ocp");

	if (in.is_open() == true) {
		string s = "";
		in >> s;
		*username = s;
	}
	else {
		while (true)
		{
			ofstream out("username.ocp");

			if (out.is_open() == true) {
				out << "User";
				out.close();
				break;
			}
		}
	}

	in.close();

	return;
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