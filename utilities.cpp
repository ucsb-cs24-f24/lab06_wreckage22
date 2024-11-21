#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>

void MovieSet2::insertMovie2(const std::string& movieName2, double rating2) {
    movies2[movieName2] = rating2; 
}

bool customComparator(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
    if (a.second != b.second) {
        return a.second > b.second;  
    }
    return a.first < b.first; 
}

void MovieSet2::printMoviesByPrefix2(const std::vector<std::string>& prefixes2) const {
    std::vector<std::string> LastPrint;


    for (size_t i = 0; i < prefixes2.size(); ++i) {
        const auto& prefix2 = prefixes2[i];
        std::vector<std::pair<std::string, double>> matchingMovies2;

        for (const auto& [name2, rating2] : movies2) {
            if (name2.substr(0, prefix2.size()) == prefix2) {
                matchingMovies2.emplace_back(name2, rating2);
            }
        }

        if (matchingMovies2.empty()) {
            std::cout << "No movies found with prefix " << prefix2 << "\n";
        } else {
            std::sort(matchingMovies2.begin(), matchingMovies2.end(), customComparator);

            for (const auto& [name2, rating2] : matchingMovies2) {
                std::cout << name2 << ", " << std::fixed << std::setprecision(1) << rating2 << "\n";

                if(name2 == matchingMovies2[matchingMovies2.size()-1].first) {
                    std::cout << "\n";
                }
            }

            const auto& bestMovie = matchingMovies2.front();

            std::stringstream ss;
            ss << std::fixed << std::setprecision(1) << bestMovie.second;
            std::string ratingStr = ss.str();

            LastPrint.push_back("Best movie with prefix " + prefix2 + " is: " + bestMovie.first + " with rating " + ratingStr);

        }
    }

    for(int i = 0; i < LastPrint.size() -1; i++){
        std::cout << LastPrint[i] << "\n";
    }
    std::cout << LastPrint[LastPrint.size() -1] ;

    for (const auto& line : LastPrint) {
        std::cout << line << "\n";
    }
}
