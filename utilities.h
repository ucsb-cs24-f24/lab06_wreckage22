#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <set>
#include <iostream>
#include <vector>

class Movie2{
    private:
    std::string movieName2;
    double rating2;    
    public:
    Movie2(std::string str, double rating);

    std::string getMovieName2() const{
        return movieName2;
    }
    double getMovieRating2() const{
        return rating2;
    }
    std::string getSubstr(int zero, int prefSize) const{
        return movieName2.substr(0, prefSize);
    }

    bool operator<(const Movie2& other) const;
};

class MovieSet2
{
    private:
    std::set<Movie2> movies2;

    public:

    void insertMovie2(Movie2 m);
    void printMovie2(std::vector<std::string> prefixes) const;
};



#endif 