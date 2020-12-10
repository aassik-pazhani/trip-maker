#pragma once

#include<vector>
#include<string>
using std::string;
using std::vector;
using std::pair;

/**
 * Gets the coordinates of the airports from the test file.
 * @param airports_file - name of the text file
 * @return a vector of the coordinates in a pair of doubles
 */
vector<pair<double, double>> getCoordinates(string airports_file);

/**
 * Converts the degrees to radians.
 * @param degree - the coordinates in degrees
 * @return the radian value in double
 */
double toRad(double degree);

/**
 * Computes the distance between two geological locations (airports).
 * @param sloc - location of source airport
 * @param dloc - location of destination airport
 * @return the distance between the source and destination in double
 */
double getDistance(pair<double, double> sloc, pair<double, double> dloc);