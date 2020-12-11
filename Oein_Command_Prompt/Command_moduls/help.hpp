#pragma once

#include "include_module.hpp"

using namespace std;

map<string , string> Help_Msg;
vector<string> list;

void on_start_help() {
	Help_Msg.insert(pair<string, string>("echo", "echo [Data]\n\tex : echo Hello?\n\n"));
	Help_Msg.insert(pair<string, string>("bash", "bash [ File Name ]\n\tex : bash a.obash\n\n"));
	Help_Msg.insert(pair<string, string>("title", "title [ Title ]\n\tex : title OCP\n\n"));
	Help_Msg.insert(pair<string, string>("dir", "dir\n\tex : dir\n\n"));
	Help_Msg.insert(pair<string, string>("ls", "ls\n\tex : ls\n\n"));
	Help_Msg.insert(pair<string, string>("timeout", "timeout [ millisecond ]\n\ttimeout 1000\n\n"));
	Help_Msg.insert(pair<string, string>("sleep", "sleep [ millisecond ]\n\tsleep 1000\n\n"));
	Help_Msg.insert(pair<string, string>("mkdir", "mkdir[Dir name]\n\tmkdir A_New_Folder\n\n"));
	Help_Msg.insert(pair<string, string>("rmdir", "rmdir [ Dir name ]\n\trmdir An_Older_Folder\n\n"));
	Help_Msg.insert(pair<string, string>("cd", "cd [ Dir name ]\n\tcd A_Folder\n\n"));
	Help_Msg.insert(pair<string, string>("set", "set [Key]=[Value]\n\tex : set a_var=32\n\n"));
	Help_Msg.insert(pair<string, string>("playsound", "playsound [wav file name]\n\tplausound A_Sample_Wav_File.wav\n\n"));
	Help_Msg.insert(pair<string, string>("stopsound", "stopsound\n\tex : stopsound\n\n"));
	Help_Msg.insert(pair<string, string>("beep", "beep [ octave + note in English ] [ millisecond ]\n\tex : 4C 400\n\tOctave : 1C ~ 8B\n\n"));
	Help_Msg.insert(pair<string, string>("help", "help\n\tex : help\n\n"));
	Help_Msg.insert(pair<string, string>("ver", "ver\n\tex : ver\n\n"));
	Help_Msg.insert(pair<string, string>("VFile", "VFile [File Name]\n\tex : VFile A Document.txt\n\n"));
	Help_Msg.insert(pair<string, string>("cat", "cat [File Name]\n\tex : cat A Document.txt\n\n"));
	Help_Msg.insert(pair<string, string>("cls", "cls\n\tex : cls\n\n"));
	Help_Msg.insert(pair<string, string>("piano", "piano\n\tex : piano\n\n"));
	Help_Msg.insert(pair<string, string>("start", "start\n\tex : start A_Promgram.exe\n\n"));
	Help_Msg.insert(pair<string, string>("color", "color\n\tColor\n\t0 = Black\n\t1 = Blue\n\t2=Green\n\t3 = Aqua\n\t4 = Red\n\t5 = Purple\n\t6 = Yellow\n\t7 = White\n\t8 = Gray\n\t9 = Light Blue\n\tA = Light Green\n\tB = Light Aqua\n\tC = Light Red\n\tD = Light Purple\n\tE = Light Yellow\n\tF = Bright White\n\tex : color 17\n\n"));

	list.push_back("echo");
	list.push_back("bash");
	list.push_back("title");
	list.push_back("dir");
	list.push_back("ls");
	list.push_back("timeout");
	list.push_back("sleep");
	list.push_back("mkdir");
	list.push_back("rmdir");
	list.push_back("cd");
	list.push_back("set");
	list.push_back("playsound");
	list.push_back("stopsound");
	list.push_back("beep");
	list.push_back("help");
	list.push_back("ver");
	list.push_back("VFile");
	list.push_back("cat");
	list.push_back("cls");
	list.push_back("piano");
	list.push_back("start");
	list.push_back("color");
}

void help(string cmd="") {
	if (cmd == "") {
		cout << "Commands List\n\n";

		for (int i = 0; i < list.size(); i++) {
			cout << Help_Msg[list[i]];
		}
	}
	else {
		if (Help_Msg.find(cmd) != Help_Msg.end()) {
			cout << Help_Msg[cmd];
		}
	}


	cout << "You can download sample files at here\nhttps://github.com/Oein/Oein_Command_Prompt/tree/master/Samples\n";
}