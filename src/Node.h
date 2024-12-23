#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;

class Node {
public:
    char code;
    double latitude;
    double longitude;
    vector<pair<Node *, double>> neighborsOut;

    Node(char code, double latitude, double longitude);
    void addNeighbor(Node *neighbor, double cost);
    double getGeographicalDistanceKM(Node *other);
};

#endif
