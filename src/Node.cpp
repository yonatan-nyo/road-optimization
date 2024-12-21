#include "Node.h"
#include <bits/stdc++.h>

Node::Node(char code, double latitude, double longitude)
    : code(code), latitude(latitude), longitude(longitude) {}

void Node::addNeighbor(Node *neighbor, unsigned int cost) {
    neighborsOut.push_back({neighbor, cost});
}

double Node::getGeographicalDistanceKM(Node *other) {
    // using Haversine formula
    const double R = 6371.0; // Radius of Earth in kilometers
    double lat1 = latitude;
    double lon1 = longitude;
    double lat2 = other->latitude;
    double lon2 = other->longitude;

    double latDistance = (lat2 - lat1) * M_PI / 180.0;
    double lonDistance = (lon2 - lon1) * M_PI / 180.0;

    double a = (sin(latDistance / 2) * sin(latDistance / 2));
    a += cos((lat1 * M_PI / 180.0)) * cos((lat2 * M_PI / 180.0)) * sin(lonDistance / 2) * sin(lonDistance / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // return distance in km
    return R * c;
}