#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;

class Node {
public:
    char code;
    double latitude;
    double longitude;
    vector<pair<Node *, unsigned int>> neighborsOut;

    Node(char code, double latitude, double longitude);
    void addNeighbor(Node *neighbor, unsigned int cost);
    double getGeographicalDistanceKM(Node *other);
};

#endif
