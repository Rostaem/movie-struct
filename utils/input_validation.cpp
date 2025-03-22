#include "input_validation.h"

/*
 * ensuring string is not empty
 */
string validate_string_input(const string& prompt) {
	string input;
	while (true) {
		cout << prompt;
		getline(cin, input);
		if (!input.empty()) {
			return input;
		} else {
			cout << "Invalid input. please enter a string." << endl;
		}
	}
}