#pragma once

#include "include_module.hpp"

using namespace std;

void help() {
	cout << "Commands List\n\necho [Data]\n\tex : echo Hello?\n\n";
	cout << "bash [ File Name ]\n\tex : bash a.obash\n\n";
	cout << "title [ Title ]\n\tex : title OCP\n\n";
	cout << "dir\n\tex : dir\n\n";
	cout << "ls\n\tex : ls\n\n";
	cout << "timeout [ millisecond ]\n\ttimeout 1000\n\n";
	cout << "sleep [ millisecond ]\n\tsleep 1000\n\n";
	cout << "mkdir [ Dir name ]\n\tmkdir A_New_Folder\n\n";
	cout << "rmdir [ Dir name ]\n\trmdir An_Older_Folder\n\n";
	cout << "cd [ Dir name ]\n\tcd A_Folder\n\n";
	cout << "set [Key]=[Value]\n\tex : set a_var=32\n\n";
	cout << "playsound [wav file name]\n\tplausound A_Sample_Wav_File.wav\n\n";
	cout << "stopsound\n\tex : stopsound\n\n";
	cout << "beep [ octave + note in English ] [ millisecond ]\n\tex : 4C 400\n\tOctave : 1C ~ 8B\n\n";
	cout << "help\n\tex : help\n\n";
	cout << "ver\n\tex : ver\n\n";
	cout << "VFile [File Name]\n\tex : VFile A Document.txt\n\n";
	cout << "cls\n\tex : cls\n\n";
	cout << "piano\n\tex : piano\n\n";

	cout << "You can download sample files at here\nhttps://github.com/Oein/Oein_Command_Prompt/tree/master/Samples\n";
}