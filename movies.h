#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <set>
#include <iostream>

class Movie{
    private:
    std::string movieName;
    double rating;    
    public:
    Movie(std::string str, double rating);
    std::string getMovieName() const{
        return movieName;
    }
    double getMovieRating() const{
        return rating;
    }

    bool operator<(const Movie& other) const;
};

class MovieSet{
    private:
    std::set<Movie> movies;

    public:

    void insertMovie(Movie m);
    // int size();
    // void removeMovie(Movie eraseMe);
    void printMovie() const;
};


#endif 