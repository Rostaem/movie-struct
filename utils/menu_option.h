#ifndef MENU_OPTION_H
#define MENU_OPTION_H
#include "../src/movie.h"
#include <memory>
using namespace std;

enum menu_option {
	CREATE_MOVIE = 1,
	DISPLAY_MOVIE = 2,
	EXIT = 3
};

void display_menu();
bool handle_menu_option(int choice,unique_ptr<movie_namespace::Movie>& movie);
void run_menu_loop(unique_ptr<movie_namespace::Movie>& movie);

#endif