// Student name: 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[0] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile(argv[1]);
 
    if (movieFile.fail()) {
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies

    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating    
    MovieSet ourMovieSet;
    MovieSet2 ourMovieSet2;

    while (getline(movieFile, line) && parseLine(line, movieName, movieRating)) {
        if(argc == 2){
           ourMovieSet.insertMovie(Movie(movieName, movieRating)); 
        }
        else{
            ourMovieSet2.insertMovie2(movieName, movieRating);
        }
    }

    movieFile.close();
        
    if (argc == 2) {
        ourMovieSet.printMovie();//print all the movies in ascending alphabetical order of movie names
        return 0;
    }

    ifstream prefixFile(argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline(prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }

    if(argc == 3){
        ourMovieSet2.printMoviesByPrefix2(prefixes);
    }

    return 0;
}


/*
Varibles
Let
    n = Number of movies in the dataset.
    m = Number of prefixes to data structure.
    k = Maximum number of movies matching a prefix.
    l = Maximum length of a movie name.

Part 3a: Analyze time complexity
    1. Prefix Search: O(m * n * l) for m prefixes.
    2. Sorting Movies by Rating (.sort): O(m * k * log(k)).
    3. Selecting the Best Movie: O(m).
    // O(m*n*l + m*k*log(k) + m) = O(m*n*l + m*k*log(k))

    Total Time Complexity: O(m*n*l + m*k*log(k))

    Run Time Test:
    input_20_random.csv         15ms
    input_100_random.csv        46ms
    input_1000_random.csv       258ms
    input_76920_random.csv      24.871s

Part 3B Space Complexity 
    1. Prefix Search: O(n * l) for m prefixes.
    2. Sorting Movies by Rating (.sort): O(m⋅l).
    3. Selecting the Best Movie: O(m⋅k⋅l).
    // O(n⋅l+m⋅l+m⋅k⋅l) = O(l*n)

    Total Space Complexity: O(l*n)

Part 3c: Trade-Offs
    #1: Though we where aiming for a better time complexity, our space throughout 
    our code was not as best as we wanted, do to some dficiculties that we felt the need to add more storage.
    Despite this our overall space complexity stayed at a reasonable level.
    Our plan and thought was that if we developed a good time complexity it could translate to better 
    space complexity. So our space complexity was not much of a priority. We did try to come up with a 
    data structure that would allow us sufficient freedom to not have to make too many lists from our already big list.
    Time complexity seemed like it would be the most challenging part of this lab because if we did not use an adequate 
    data structure, we would have to traverse the given list of movies much more than we would like to which would drastically
    increase the time.

*/



/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }

    return true;
}


