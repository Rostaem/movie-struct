#include "utils/menu_option.h"
#include "utils/input_validation.h"
#include <iostream>
#include <memory>

using namespace std;
using namespace movie_namespace;

int main() {
	unique_ptr<Movie> movie = nullptr;
	run_menu_loop(movie);
	return 0;
}