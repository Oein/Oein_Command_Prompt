#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

char d = ' ';

bool space(char c)
{
	return c == d;
}

bool not_space(char c)
{
	return c != d;
}

std::vector<std::string> split(const std::string& str , char word)
{
	d = word;

	typedef std::string::const_iterator iter;
	std::vector<std::string> ret;

	iter it_b = str.begin();

	while (it_b != str.end())
	{
		it_b = find_if(it_b, str.end(), not_space);

		iter it_e = find_if(it_b, str.end(), space);

		if (it_b != str.end())
		{
			ret.push_back(std::string(it_b, it_e));
		}

		it_b = it_e;
	}

	return ret;
}