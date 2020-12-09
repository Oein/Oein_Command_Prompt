#include <iostream>
#include "Command.hpp"

using namespace std;

int main() {
	on_start();

	while (true)
	{
		try {
			string input;
			cout << get_dir() << ">";
			getline(cin, input);

			input_command(input);

			cout << '\n';
		}
		catch (int expn) {
			cout << "[ERROR] : " << expn << '\n';
		}
	}
}