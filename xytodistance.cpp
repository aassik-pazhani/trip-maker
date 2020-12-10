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
        for (size_t i = 0; i < 6; i++) {
            pos = airport.find(",", pos + 1);
            if (i == 4) {
                size_t size = airport.find(",", pos + 1) - pos - 1;
                lat = atof(airport.substr(pos + 1, size).c_str());
            }
            if (i == 5) {
                size_t size = airport.find(",", pos + 1) - pos - 1;
                lont = atof(airport.substr(pos + 1, size).c_str());
            }
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