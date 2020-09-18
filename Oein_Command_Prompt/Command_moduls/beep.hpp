#pragma once

#include "include_module.hpp"

using namespace std;

void beep(vector<string> commands) {
	if (to_low(commands[1]) == "1c") Beep(_1C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2c") Beep(_2C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3c") Beep(_3C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4c") Beep(_4C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5c") Beep(_5C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6c") Beep(_6C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7c") Beep(_7C, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8c") Beep(_8C, atoi(commands[2].c_str()));

	if (to_low(commands[1]) == "1d") Beep(_1D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2d") Beep(_2D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3d") Beep(_3D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4d") Beep(_4D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5d") Beep(_5D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6d") Beep(_6D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7d") Beep(_7D, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8d") Beep(_8D, atoi(commands[2].c_str()));

	if (to_low(commands[1]) == "1e") Beep(_1E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2e") Beep(_2E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3e") Beep(_3E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4e") Beep(_4E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5e") Beep(_5E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6e") Beep(_6E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7e") Beep(_7E, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8e") Beep(_8E, atoi(commands[2].c_str()));

	if (to_low(commands[1]) == "1f") Beep(_1F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2f") Beep(_2F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3f") Beep(_3F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4f") Beep(_4F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5f") Beep(_5F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6f") Beep(_6F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7f") Beep(_7F, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8f") Beep(_8F, atoi(commands[2].c_str()));

	if (to_low(commands[1]) == "1g") Beep(_1G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2g") Beep(_2G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3g") Beep(_3G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4g") Beep(_4G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5g") Beep(_5G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6g") Beep(_6G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7g") Beep(_7G, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8g") Beep(_8G, atoi(commands[2].c_str()));

	if (to_low(commands[1]) == "1a") Beep(_1A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2a") Beep(_2A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3a") Beep(_3A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4a") Beep(_4A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5a") Beep(_5A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6a") Beep(_6A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7a") Beep(_7A, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8a") Beep(_8A, atoi(commands[2].c_str()));

	if (to_low(commands[1]) == "1b") Beep(_1B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "2b") Beep(_2B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "3b") Beep(_3B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "4b") Beep(_4B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "5b") Beep(_5B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "6b") Beep(_6B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "7b") Beep(_7B, atoi(commands[2].c_str()));
	if (to_low(commands[1]) == "8b") Beep(_8B, atoi(commands[2].c_str()));
}