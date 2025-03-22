#include "src/movie.h"
#include "utils/input_validation.h"
#include <iostream>
#include <string>
using namespace std;
using namespace movie_namespace;

int main() {
	unique_ptr<Movie> movie = nullptr;

	while (true) {
		// Display menu
		cout << "\nMenu:\n";
		cout << "1. Create a Movie\n";
		cout << "2. Display Movie\n";
		cout << "3. Exit\n";

		// Get menu choice
		int choice = input_validation<int>("Enter your choice: ", 1, 3);

		if (choice == 1) {
			// Create a new movie
			movie = create_movie();
		} else if (choice == 2) {
			// Display the movie
			display_movie(movie);
		} else if (choice == 3) {
			log_action("Exiting program.");
			break;
		}
	}

	return 0;
}