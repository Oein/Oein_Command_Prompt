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

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
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