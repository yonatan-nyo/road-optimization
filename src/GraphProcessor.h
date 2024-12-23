#ifndef GRAPH_PROCESSOR_H
#define GRAPH_PROCESSOR_H

#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

class GraphProcessor {
private:
    map<Node *, map<Node *, double>> allCosts;

    void dijkstra(Node *startNode);

public:
    vector<tuple<Node *, Node *, double, double>> getMostWorthedRoad(vector<Node> &nodes);
};

#endif
