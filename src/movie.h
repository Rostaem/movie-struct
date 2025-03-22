#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <memory> // For smart pointers
#include <sstream>
using namespace std;

/**
 * Namespace to encapsulate movie-related functionality.
 */
namespace movie_namespace {

	/**
	 * Struct for representing a date.
	 */
	struct Date {
		int day;   ///< Day of the month (1-31)
		int month; ///< Month of the year (1-12)
		int year;  ///< Year (e.g., 2025)
	};

	/**
	 * Struct for representing a movie.
	 */
	struct Movie {
		string title;      ///< Movie title
		Date release_date; ///< Release date (nested struct)
		bool is_popular;   ///< Indicates if the movie is popular
		string director;   ///< Director's name
	};

	// Function Prototypes
	unique_ptr<Movie> create_movie();
	void display_movie(const unique_ptr<Movie>& movie);
	ostream& operator<<(ostream& os, const Movie& movie);
	string format_date(const Date& date);
	void log_action(const string& message);

} // namespace movie_namespace

#endif