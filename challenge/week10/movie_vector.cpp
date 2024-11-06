#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Movie {
    string name;
    double rating;
};

int main() {

    vector<Movie> movies = {
        {"titanic", 9.9},
        {"gone with the wind", 9.6},
        {"terminator", 9.7}
    };

    for (const auto& movie : movies) {
        cout << movie.name << ": " << movie.rating << endl;
    }

    return 0;
}
