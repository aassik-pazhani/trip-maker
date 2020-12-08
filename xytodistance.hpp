#include "readFromFile.hpp"
#include<vector>
#include<string>
using std::string;
using std::vector;
using std::pair;
vector<pair<long double, long double>> getCoordinates(string airports_file);
double toRad(long double degree);
double getDistance(pair<long double, long double> sloc, pair<long double, long double> dloc);