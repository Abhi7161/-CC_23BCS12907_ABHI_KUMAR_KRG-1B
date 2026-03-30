#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights,
                      int src, int dst, int k) {

    vector<vector<pair<int, int>>> graph(n);

    for (auto &flight : flights) {
        graph[flight[0]].push_back({flight[1], flight[2]});
    }

    queue<vector<int>> q;
    q.push({src, 0, 0});

    vector<int> minCost(n, INT_MAX);
    minCost[src] = 0;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int city = curr[0];
        int cost = curr[1];
        int stops = curr[2];

        if (stops > k) continue;

        for (auto neighbour : graph[city]) {
            int next = neighbour.first;
            int price = neighbour.second;

            if (cost + price < minCost[next]) {
                minCost[next] = cost + price;
                q.push({next, cost + price, stops + 1});
            }
        }
    }

    return (minCost[dst] == INT_MAX) ? -1 : minCost[dst];
}

int main() {
    int n, m;
    cout << "Enter number of cities and flights: ";
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    cout << "Enter flights (from to price):\n";
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cout << "Enter source, destination and max stops: ";
    cin >> src >> dst >> k;

    int result = findCheapestPrice(n, flights, src, dst, k);

    cout << "Cheapest Price: " << result;

    return 0;
}