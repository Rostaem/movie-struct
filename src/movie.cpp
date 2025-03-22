#include "movie.h"
#include "../utils/input_validation.h"
#include <iomanip>
#include <memory>
#include <sstream>

namespace movie_namespace {

    string format_date(const Date& date) {
        ostringstream oss;
        oss << setw(2) << setfill('0') << date.day << "/"
            << setw(2) << setfill('0') << date.month << "/"
            << date.year;
        return oss.str();
    }

    /*
     * experimenting with logs
     */
    void log_action(const string& message) {
        cout << "[LOG]: " << message << endl;
    }


    unique_ptr<Movie> create_movie() {
        auto new_movie = make_unique<Movie>();

        new_movie->title = validate_string_input("Enter the movie title: ");
        new_movie->release_date.day = input_validation<int>("Enter the release day (1-31): ", 1, 31);
        new_movie->release_date.month = input_validation<int>("Enter the release month (1-12): ", 1, 12);
        new_movie->release_date.year = input_validation<int>("Enter the release year (1800-2025): ", 1800, 2025);

        int popularity_input = input_validation<int>("ss/was the movie popular? (1 = Yes, 0 = No): ", 0, 1);
        new_movie->is_popular = (popularity_input == 1);

        new_movie->director = validate_string_input("Enter the director's name: ");

        log_action("Created a new movie: " + new_movie->title);
        return new_movie;
    }

    void display_movie(const unique_ptr<Movie>& movie) {
        if (movie) {
            cout << *movie;
            log_action("Displayed movie details...");
        } else {
            cout << "There are no movies to display." << endl;
        }
    }

    /*
     * Overload
     */
    ostream& operator<<(ostream& os, const Movie& movie) {
        os << endl << "Movie Details:" << endl;
        os << "Title: " << movie.title << endl;
        os << "Release Date: " << format_date(movie.release_date) << endl;
        os << "Popularity: " << (movie.is_popular ? "Yes" : "No") << endl;
        os << "Director: " << movie.director << endl;
        return os;
    }
}