#include "movie.h"
#include "../utils/input_validation.h" // Adjust the path
#include <iomanip> // For formatting dates

namespace movie_namespace {

	string format_date(const Date& date) {
		ostringstream oss;
		oss << setw(2) << setfill('0') << date.day << "/"
			<< setw(2) << setfill('0') << date.month << "/"
			<< date.year;
		return oss.str();
	}

	void log_action(const string& message) {
		cout << "[LOG]: " << message << endl;
	}

	unique_ptr<Movie> create_movie() {
		auto new_movie = make_unique<Movie>();

		new_movie->title = validate_string_input("Enter movie title: ");
		new_movie->release_date.day = input_validation<int>("Enter release day (1-31): ", 1, 31);
		new_movie->release_date.month = input_validation<int>("Enter release month (1-12): ", 1, 12);
		new_movie->release_date.year = input_validation<int>("Enter release year (1900-2025): ", 1900, 2025);
		int popularity_input = input_validation<int>("Is the movie popular? (1 for Yes, 0 for No): ", 0, 1);
		new_movie->is_popular = (popularity_input == 1);
		new_movie->director = validate_string_input("Enter director name: ");

		log_action("Created a new movie: " + new_movie->title);
		return new_movie;
	}

	void display_movie(const unique_ptr<Movie>& movie) {
		if (movie) {
			cout << *movie;
			log_action("Displayed movie details.");
		} else {
			cout << "No movie to display!" << endl;
		}
	}

	ostream& operator<<(ostream& os, const Movie& movie) {
		os << "\nMovie Details:\n";
		os << "Title: " << movie.title << endl;
		os << "Release Date: " << format_date(movie.release_date) << endl;
		os << "Is Popular: " << (movie.is_popular ? "Yes" : "No") << endl;
		os << "Director: " << movie.director << endl;
		return os;
	}

} // namespace movie_namespace