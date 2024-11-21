#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

void MovieSet2::insertMovie2(const std::string& movieName2, double rating2) {
    movies2[movieName2] = rating2; 
}

void MovieSet2::printMoviesByPrefix2(const std::vector<std::string>& prefixes2) const {
    std::vector<std::pair<std::string, double>> bestMovies2;
    bool firstOutput = true;  
    for (const auto& prefix2 : prefixes2) {
        std::vector<std::pair<std::string, double>> matchingMovies2;

        for (const auto& [name2, rating2] : movies2) {
            if (name2.substr(0, prefix2.size()) == prefix2) {
                matchingMovies2.emplace_back(name2, rating2);
            }
        }
        if (!firstOutput) {
            std::cout << "\n"; 
        }

        firstOutput = false; 

        if (matchingMovies2.empty()) {
            std::cout << "No movies found with prefix " << prefix2 << "\n";
            bestMovies2.emplace_back(prefix2, -1.0);
        } 
        else {
            std::sort(matchingMovies2.begin(), matchingMovies2.end(),
                      [](const auto& a, const auto& b) {
                          return a.second != b.second ? a.second > b.second : a.first < b.first;
                      });

            for (const auto& [name2, rating2] : matchingMovies2) {
                std::cout << name2 << ", " << std::fixed << std::setprecision(1) << rating2 << "\n";
            }

            bestMovies2.emplace_back(matchingMovies2.front().first, matchingMovies2.front().second);
        }

    }

    for (const auto& [prefix2, bestRating2] : bestMovies2) {
        if (bestRating2 == -1.0) {
            std::cout << "No movies found with prefix " << prefix2 << "\n";
        } else {
            std::cout << "Best movie with prefix " << prefix2 << " is: "
                      << prefix2 << " with rating "
                      << std::fixed << std::setprecision(1) << bestRating2 << "\n";
        }
    }
}
