#include "xytodistance.hpp"
#include "readFromFile.hpp"
#include<iostream>
#include<vector>
#include<cmath>

using std::vector;
using std::string;
using std::stold;
using std::pair;

#define pi 3.14159265358979323846

vector<pair<long double, long double>> getCoordinates(string airports_file) {
    vector<string> airports = file_to_vector(airports_file);
    vector<pair<long double, long double>> latlong;
    long double lat, lont;
    for (string airport : airports) {
        size_t pos = airport.find(",");
        size_t pos1;
        for (size_t i = 0; i < 6; i++) {
            pos = airport.find(",", pos + 1);
            if (i == 5) {
                pos1 = airport.find(",", pos + 1);
                lat = stold(airport.substr(pos + 1, pos1 - 1));
            }
            pos = airport.find(",", pos1 + 1);
            lont = stold(airport.substr(pos1 + 1, pos - 1));
        }
        latlong.push_back(pair<long double, long double> (lat, lont));
    }
    return latlong;
}

double toRad(long double degree) {
    return degree/180 * pi;
}
double getDistance(pair<long double, long double> sloc, pair<long double, long double> dloc) {
    double distance;
    distance = sin(toRad(sloc.first)) * sin(toRad(dloc.first)) + cos(toRad(sloc.first)) * cos(toRad(dloc.first)) * cos(toRad(sloc.second - dloc.second));
    distance = acos(distance);
    distance = 6371 * distance;
    return distance;
}