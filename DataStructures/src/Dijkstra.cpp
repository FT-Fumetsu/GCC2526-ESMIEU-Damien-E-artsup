#include "Dijkstra.hpp"
#include <queue>
#include <limits>
#include <algorithm>

DijkstraResult Dijkstra::shortestPath(
    const WeightedGraph& graph,
    int source,
    int target
) {
    const int n = graph.getVertexCount();
    const auto& edges = graph.getEdges();

    // ============================
    // PHASE 0 : LISTE D'ADJACENCE
    // ============================
    std::vector<std::vector<std::pair<int, double>>> adj(n);

    for (const auto& e : edges) {
        std::pair<int, double> edge_uv(e.v, e.weight);
        std::pair<int, double> edge_vu(e.u, e.weight);

        adj[e.u].push_back(edge_uv);
        adj[e.v].push_back(edge_vu);
    }

    // ============================
    // PHASE 1 : INITIALISATION
    // ============================
    std::vector<double> distance(n, std::numeric_limits<double>::infinity());
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    distance[source] = 0.0;

    using Node = std::pair<double, int>;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({0.0, source});

    // ============================
    // PHASE 2 : EXPLORATION
    // ============================
    while (!pq.empty()) {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        // Arrêt anticipé
        if (u == target)
            break;

        // ============================
        // PHASE 3 : RELAXATION
        // ============================
        for (const auto& [v, weight] : adj[u]) {
            if (visited[v])
                continue;

            double newDist = distance[u] + weight;

            if (newDist < distance[v]) {
                distance[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
            }
        }
    }

    // ============================
    // PHASE 4 : RECONSTRUCTION
    // ============================
    DijkstraResult result;
    result.distance = distance[target];

    if (distance[target] == std::numeric_limits<double>::infinity()) {
        return result; // chemin vide = pas de solution
    }

    for (int v = target; v != -1; v = parent[v]) {
        result.path.push_back(v);
    }

    std::reverse(result.path.begin(), result.path.end());
    return result;
}
