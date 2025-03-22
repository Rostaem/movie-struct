#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
T input_validation(const string& prompt, T min, T max) {
	T value;
	string input;
	while (true) {
		cout << prompt;
		getline(cin, input);

		stringstream ss(input);

		if (ss >> value && ss.eof() && value >= min && value <= max) {
			return value;
		} else {
			cout << "Invalid input. Please enter a number between " << min << " and " << max << endl;
		}
	}
}

string validate_string_input(const string& prompt);

#endif