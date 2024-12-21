#include "GraphProcessor.h"

// Dijkstra's algorithm to compute shortest paths from startNode to all other nodes
void GraphProcessor::dijkstra(Node *startNode) {
    // Priority queue to process nodes by minimum cost (min-heap behavior)
    priority_queue<pair<unsigned int, Node *>, vector<pair<unsigned int, Node *>>, greater<>> pq;
    // Map to store the minimum cost to reach each node
    map<Node *, unsigned int> visitedCosts;

    visitedCosts[startNode] = 0; // Start node cost is 0
    pq.push({0, startNode});     // Push start node to the priority queue

    while (!pq.empty()) {
        unsigned int currentCost = pq.top().first;
        Node *currentNode = pq.top().second;
        pq.pop(); // Extract the node with the smallest cost

        // Skip if a shorter path to currentNode has already been found
        if (currentCost > visitedCosts[currentNode])
            continue;

        // Process each neighboring node
        for (auto &neighbor : currentNode->neighborsOut) {
            Node *neighborNode = neighbor.first;
            unsigned int edgeCost = neighbor.second;
            unsigned int newCost = currentCost + edgeCost;

            // If this path is shorter, update and push to the queue
            if (visitedCosts.find(neighborNode) == visitedCosts.end() || newCost < visitedCosts[neighborNode]) {
                visitedCosts[neighborNode] = newCost;
                pq.push({newCost, neighborNode});
            }
        }
    }

    // Store the computed costs in the global cost map
    for (auto &visited : visitedCosts) {
        if (startNode == visited.first)
            continue;

        allCosts[startNode][visited.first] = visited.second;
    }
}

// Process the entire graph by running Dijkstra for each node
vector<tuple<Node *, Node *, unsigned int, double>> GraphProcessor::getMostWorthedRoad(vector<Node> &nodes) {
    allCosts.clear(); // Clear previous results

    // Run Dijkstra for each node in the graph
    for (Node &node : nodes) {
        dijkstra(&node);
    }

    // Vector to store cost, distance, and node pairs
    vector<tuple<Node *, Node *, unsigned int, double>> costDistancePairs;

    // Calculate cost and distance between all pairs of nodes
    for (auto &source : allCosts) {
        for (auto &destination : source.second) {
            unsigned int cost = destination.second;
            double distance = source.first->getGeographicalDistanceKM(destination.first);
            costDistancePairs.push_back({source.first, destination.first, cost, distance});
        }
    }

    // Sort the pairs by cost per km in descending order
    sort(costDistancePairs.begin(), costDistancePairs.end(), [](const auto &a, const auto &b) {
        double costPerKmA = (get<2>(a) / get<3>(a));
        double costPerKmB = (get<2>(b) / get<3>(b));
        return costPerKmA > costPerKmB;
    });

    return costDistancePairs; // Return the sorted results
}
