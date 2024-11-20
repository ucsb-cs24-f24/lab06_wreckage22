#include "movies.h"   

Movie::Movie(std::string movieName, double rating){
    this->movieName = movieName;
    this->rating = rating;
}

bool Movie::operator<(const Movie& other) const{
    return movieName < other.movieName;
}

void MovieSet::insertMovie(Movie m){
    movies.insert(m);
}

void MovieSet::printMovie() const{
        for(const auto& movie : movies){
        std::cout << movie.getMovieName() << ", " << movie.getMovieRating() << std::endl;
    }
}
