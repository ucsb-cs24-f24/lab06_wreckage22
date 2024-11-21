#include "utilities.h"
#include <algorithm>

Movie2::Movie2(std::string movieName2, double rating2){
    this->movieName2 = movieName2;
    this->rating2 = rating2;
}

bool Movie2::operator<(const Movie2& other) const{
    if(rating2 != other.rating2){
        return rating2 > other.rating2;
    }
    else{
        return movieName2 < other.movieName2;
    }

}

void MovieSet2::insertMovie2(Movie2 m){
    movies2.insert(m);
}

// void MovieSet2::printMovie2(std::vector<std::string> prefixes) const{
//     std::vector<Movie2> matchingMovies;
//     for(int i = 0; i < prefixes.size(); i++){
//         std::string pref = prefixes[i];
//         int prefSize = prefixes[i].size();
//         for(const auto& movie2 : movies2){
//             std::string moviePref = movie2.getSubstr(0,prefSize);
//             if(moviePref == pref){
//                 std::cout << movie2.getMovieName2() << ", " << movie2.getMovieRating2() << std::endl;
//             }
//         }
//         std::cout << std::endl;
//     }
// }

void MovieSet2::printMovie2(std::vector<std::string> prefixes) const {
    std::vector<std::pair<std::string, Movie2>> bestMovies; 

    for (const auto& pref : prefixes) { 
        std::vector<Movie2> matchingMovies;
        int prefSize = pref.size();

        for (const auto& movie2 : movies2) {
            std::string moviePref = movie2.getSubstr(0, prefSize);
            if (moviePref == pref) {
                matchingMovies.push_back(movie2);
            }
        }

        if (matchingMovies.empty()) {
            bestMovies.emplace_back(pref, Movie2("No movie found", 0.0));
        } else {
            std::sort(matchingMovies.begin(), matchingMovies.end());

            for (const auto& movie : matchingMovies) {
                std::cout << movie.getMovieName2() << ", " << movie.getMovieRating2() << "\n";
            }

            bestMovies.emplace_back(pref, matchingMovies[0]);
        }

        std::cout << std::endl;
    }

    for (const auto& [prefix, bestMovie] : bestMovies) {
        if (bestMovie.getMovieName2() == "No movie found") {
            std::cout << "No movies found with prefix " << prefix << "\n";
        } else {
            std::cout << "Best movie with prefix " << prefix << " is: " 
                      << bestMovie.getMovieName2() << " with rating " 
                      << bestMovie.getMovieRating2() << "\n";
        }
    }
}