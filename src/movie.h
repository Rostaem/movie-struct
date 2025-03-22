#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <memory>
#include <ostream>

using namespace std;

namespace movie_namespace {

	struct Date {
		int day;
		int month;
		int year;
	};

	struct Movie {
		string title;
		Date release_date;
		bool is_popular;
		string director;
	};

	string format_date(const Date& date);
	void log_action(const string& message);
	unique_ptr<Movie> create_movie();
	void display_movie(const unique_ptr<Movie>& movie);

	ostream& operator<<(ostream& os, const Movie& movie);

}

#endif