#pragma once

#include <iostream>
#include <string>

using namespace std;

string replace_all(
	__in const string& message,
	__in const string& pattern,
	__in const string& replace
) {
	string result = message;
	string::size_type pos = 0;
	string::size_type offset = 0;
	while ((pos = result.find(pattern, offset)) != string::npos)
	{
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
		offset = pos + replace.size();
	}
	return result;
}