#include "GraphProcessor.h"
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<Node> nodes = {
        {'A', -6.427195, 107.445184},
        {'B', -6.623177, 107.412072},
        {'C', -6.789701, 107.443070},
        {'D', -6.947776, 107.552972},
        {'E', -6.935887, 107.753051},
        {'F', -6.809289, 107.946789},
        {'G', -6.684056, 108.114460}};

    nodes[0].addNeighbor(&nodes[1], 10);
    nodes[1].addNeighbor(&nodes[0], 10);
    nodes[1].addNeighbor(&nodes[2], 10);
    nodes[2].addNeighbor(&nodes[1], 10);
    nodes[2].addNeighbor(&nodes[3], 10);
    nodes[3].addNeighbor(&nodes[2], 10);
    nodes[3].addNeighbor(&nodes[4], 10);
    nodes[4].addNeighbor(&nodes[3], 10);
    nodes[4].addNeighbor(&nodes[5], 10);
    nodes[5].addNeighbor(&nodes[4], 10);
    nodes[5].addNeighbor(&nodes[6], 10);
    nodes[6].addNeighbor(&nodes[5], 10);

    GraphProcessor processor;
    auto costDistancePairs = processor.getMostWorthedRoad(nodes);

    cout << "Route\tCost\tDistance (km)\tCost per km" << endl;
    cout << "-------------------------------------------" << endl;
    for (auto &[src, dest, cost, dist] : costDistancePairs) {
        cout << src->code << " -> " << dest->code
             << "\t" << cost
             << "\t" << fixed << setprecision(2) << dist
             << "\t\t" << (cost / dist) << endl;
    }

    return 0;
}
