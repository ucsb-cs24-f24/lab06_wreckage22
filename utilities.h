#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <unordered_map>
#include <vector>

class MovieSet2 {
private:
    std::unordered_map<std::string, double> movies2;

public:
    void insertMovie2(const std::string& movieName2, double rating2);
    void printMoviesByPrefix2(const std::vector<std::string>& prefixes2) const;
};

#endif


