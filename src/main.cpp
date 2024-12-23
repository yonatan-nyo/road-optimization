#include "GraphProcessor.h"
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

void test_halfCircular() {
    printf("\nTest half circular\n");
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
}

void test_halfCircularWithAnAlreadyEfficientPath() {
    printf("\nTest half circular with an already efficient path\n");
    vector<Node> nodes = {
        {'A', -6.427195, 107.445184},
        {'B', -6.623177, 107.412072},
        {'C', -6.789701, 107.443070},
        {'D', -6.947776, 107.552972},
        {'E', -6.935887, 107.753051},
        {'F', -6.809289, 107.946789},
        {'G', -6.684056, 108.114460},
        {'H', -6.775878, 108.276782}};

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
    nodes[6].addNeighbor(&nodes[7], 10);
    nodes[7].addNeighbor(&nodes[6], 10);

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
}

void test_highCost() {
    printf("\nTest high cost\n");
    vector<Node> nodes = {
        {'A', -6.915504325442533, 107.57388333819043},
        {'B', -6.945820946932728, 107.58865421158065},
        {'C', -6.947009794411182, 107.63356565309779}};

    nodes[0].addNeighbor(&nodes[1], 60);
    nodes[1].addNeighbor(&nodes[0], 30);
    nodes[1].addNeighbor(&nodes[2], 10);
    nodes[2].addNeighbor(&nodes[1], 10);

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
}

void test_circling() {
    printf("\nTest circling\n");
    vector<Node> nodes = {
        {'B', -7.515967082213048, 109.06082582797904},
        {'C', -7.407822958022914, 109.08120195798787},
        {'D', -7.418491261194373, 109.1939506938494},
        {'F', -7.539950205861219, 109.17939118630723}};

    nodes[0].addNeighbor(&nodes[1], 10);
    nodes[1].addNeighbor(&nodes[0], 10);
    nodes[1].addNeighbor(&nodes[2], 10);
    nodes[2].addNeighbor(&nodes[1], 10);
    nodes[2].addNeighbor(&nodes[3], 10);
    nodes[3].addNeighbor(&nodes[2], 10);
    nodes[3].addNeighbor(&nodes[0], 10);
    nodes[0].addNeighbor(&nodes[3], 10);

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
}

void test_circlingWithExtraNodesOutside() {
    printf("\nTest circling with extra nodes outside\n");

    // the lower the treshold, more new road candidates will be tested
    // better accuracy, but more time consuming
    const double treshold = 0.75;

    vector<Node> nodes = {
        {'A', -7.6043180760077105, 108.95379141682587},
        {'B', -7.515967082213048, 109.06082582797904},
        {'C', -7.407822958022914, 109.08120195798787},
        {'D', -7.418491261194373, 109.1939506938494},
        {'E', -7.350437857870707, 109.30946575324204},
        {'F', -7.539950205861219, 109.17939118630723}};

    // AB
    nodes[0].addNeighbor(&nodes[1], 10);
    nodes[1].addNeighbor(&nodes[0], 10);

    // BC
    nodes[1].addNeighbor(&nodes[2], 10);
    nodes[2].addNeighbor(&nodes[1], 10);

    // CD
    nodes[2].addNeighbor(&nodes[3], 10);
    nodes[3].addNeighbor(&nodes[2], 10);

    // DE
    nodes[3].addNeighbor(&nodes[4], 10);
    nodes[4].addNeighbor(&nodes[3], 10);

    // DF
    nodes[3].addNeighbor(&nodes[5], 10);
    nodes[5].addNeighbor(&nodes[3], 10);

    // BF
    nodes[1].addNeighbor(&nodes[5], 10);
    nodes[5].addNeighbor(&nodes[1], 10);

    GraphProcessor processor;
    auto costDistancePairs = processor.getMostWorthedRoad(nodes);

    double averageCostPerKM = 0.0;
    double highestCostPerKm = 0.0;
    long long size = costDistancePairs.size();

    cout << "Route\tCost\tDistance (km)\tCost per km" << endl;
    cout << "-------------------------------------------" << endl;
    for (auto &[src, dest, cost, dist] : costDistancePairs) {
        cout << src->code << " -> " << dest->code
             << "\t" << cost
             << "\t" << fixed << setprecision(2) << dist
             << "\t\t" << (cost / dist) << endl;
        averageCostPerKM += ((cost / dist) / size);
        highestCostPerKm = max(highestCostPerKm, (cost / dist));
    }

    // new vector to store the road candidates
    vector<tuple<Node *, Node *, double, double>> roadCandidates;
    for (auto &[src, dest, cost, dist] : costDistancePairs) {
        if ((cost / dist) >= (highestCostPerKm * treshold)) {
            roadCandidates.push_back({src, dest, cost, dist});
        }
    }

    // output the new road candidates
    cout << "\nNew road candidates impact " << endl;
    cout << "Route\tCost\tDistance (km)\tCost per km\tNew Cost" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (auto &[src, dest, cost, dist] : roadCandidates) {
        double newCost = averageCostPerKM * dist;

        cout << src->code << " -> " << dest->code
             << "\t" << cost
             << "\t" << fixed << setprecision(2) << dist
             << "\t\t" << (cost / dist)
             << "\t\t" << newCost << endl;
    }

    //  source, destination, newAverageCostPerKM (after built source->dest)
    vector<tuple<Node *, Node *, double>> newRoadCandidates;

    // simulate the new graph for each new road candidates
    for (auto &[src, dest, cost, dist] : roadCandidates) {
        // make that road
        src->addNeighbor(dest, averageCostPerKM * dist);

        // run the processor again
        auto roadCandidates = processor.getMostWorthedRoad(nodes);

        // debug output all new cost distance
        // cout << "\nAfter adding " << src->code << " -> "
        //      << dest->code << " with cost " << averageCostPerKM * dist << endl;
        // cout << "Route\tCost\tDistance (km)\tCost per km" << endl;
        // cout << "-------------------------------------------" << endl;
        // for (auto &[src, dest, cost, dist] : roadCandidates) {
        //     cout << src->code << " -> " << dest->code
        //          << "\t" << cost
        //          << "\t" << fixed << setprecision(2) << dist
        //          << "\t\t" << (cost / dist) << endl;
        // }

        // calculate new average cost per km
        double newAverageCostPerKM = 0.0;
        for (auto &[src, dest, cost, dist] : roadCandidates) {
            newAverageCostPerKM += ((cost / dist) / size);
        }

        // store the new road candidates
        newRoadCandidates.push_back({src, dest, newAverageCostPerKM});

        // delete that road
        src->neighborsOut.pop_back();
    }

    // sort the new road candidates by new average cost per km
    sort(newRoadCandidates.begin(), newRoadCandidates.end(),
         [](const auto &a, const auto &b) {
             return get<2>(a) < get<2>(b);
         });

    // output the new road candidates
    cout << "\nNew road candidates" << endl;
    cout << "**(the lower new average cost per km the better)" << endl;
    cout << "Route\tNew Average Cost per km" << endl;
    cout << "--------------------------------" << endl;
    for (auto &[src, dest, newAverageCostPerKM] : newRoadCandidates) {
        cout << src->code << " -> " << dest->code
             << "\t" << newAverageCostPerKM << endl;
    }
}

int main() {
    // comment uncomment to test
    // test_halfCircular();
    // test_halfCircularWithAnAlreadyEfficientPath();
    // test_highCost();
    // test_circling();
    test_circlingWithExtraNodesOutside();

    return 0;
}
