#include "menu_option.h"
#include "input_validation.h"
#include <iostream>
#include <memory>

using namespace std;
using namespace movie_namespace;

void display_menu() {
	cout << endl << "Menu: " << endl;
	cout << "1. Create a movie" << endl;
	cout << "2. Display movie" << endl;
	cout << "3. Exit" << endl;
}

bool handle_menu_option(int choice, unique_ptr<Movie>& movie) {
	switch (choice) {
		case CREATE_MOVIE:
			movie = create_movie();
		break;

		case DISPLAY_MOVIE:
			display_movie(movie);
		break;

		case EXIT:
			log_action("Exiting program...");
		return false;

		default:
			cout << "Invalid choice" << endl;
		break;
	}
	return true;
}


void run_menu_loop(unique_ptr<Movie>& movie) {
	while (true) {
		display_menu();
		int choice = input_validation<int>("Enter your choice: ", 1, 3);
		if (!handle_menu_option(choice, movie)) {
			break;
		}
	}
}