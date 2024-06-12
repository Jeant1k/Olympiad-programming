#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

class Graph {
public:
    Graph(int n) : adj(n), dist(n, vector<int>(3, INT_MAX)) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int findRitualPlace(int a, int b, int c) {

        conutShortestPaths(a, 0);
        conutShortestPaths(b, 1);
        conutShortestPaths(c, 2);

        for (int i = 0; i < dist.size(); ++i)
            if (dist[i][0] == dist[i][1] && dist[i][1] == dist[i][2])
                return i;

        return -1;

    }

private:
    void conutShortestPaths(int start, int src) {

        queue<int> queue;
        queue.push(start);
        dist[start][src] = 0;

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();

            for (int i : adj[node]) {
                if (dist[i][src] == INT_MAX) {
                    queue.push(i);
                    dist[i][src] = dist[node][src] + 1;
                }
            }
        }

    }

    vector<vector<int>> adj;
    vector<vector<int>> dist;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    cin >> a >> b >> c;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u - 1, v - 1);
    }

    int place = graph.findRitualPlace(a - 1, b - 1, c - 1);

    if (place == -1)  cout << place << endl;
    else cout << place + 1 << endl;

    return 0;

}
