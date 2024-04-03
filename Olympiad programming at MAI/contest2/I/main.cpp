#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>> &prev, int a, vector<int> &path, vector<vector<int>> &paths) {
    path.push_back(v);
    if (v == a)
        paths.push_back(vector<int>(path.rbegin(), path.rend()));
    else
        for (int u : prev[v]) dfs(u, prev, a, path, paths);
    path.pop_back();
}

vector<vector<int>> shortestPaths(int n, int a, int b, vector<vector<pair<int, int>>> &graph, int &total_min_length) {
    vector<int> dist(n, INT_MAX);
    vector<vector<int>> prev(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sub;

    dist[a] = 0;
    sub.push({0, a});

    while (!sub.empty()) {
        int v = sub.top().second;
        int d_v = sub.top().first;
        sub.pop();

        if (d_v != dist[v]) continue;

        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                sub.push({dist[to], to});
                prev[to].clear();
                prev[to].push_back(v);
            } else if (dist[v] + len == dist[to]) {
                prev[to].push_back(v);
            }
        }
    }

    vector<int> path;
    vector<vector<int>> paths;
    dfs(b, prev, a, path, paths);

    total_min_length = 0;
    for (auto &p : paths) {
        for (int i = 0; i < p.size() - 1; ++i) {
            for (auto &edge : graph[p[i]]) {
                if (edge.first == p[i + 1]) {
                    total_min_length += edge.second;
                    break;
                }
            }
        }
    }

    return paths;
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a; --b;
    vector<vector<pair<int, int>>> graph(n);
    int total_length = 0;
    while (m--) {
        int i1, i2, l;
        cin >> i1 >> i2 >> l;
        --i1; --i2;
        graph[i1].push_back({i2, l});
        graph[i2].push_back({i1, l});
        total_length += l;
    }

    int total_min_length;
    vector<vector<int>> paths = shortestPaths(n, a, b, graph, total_min_length);

    cout << total_length - total_min_length << endl;

    return 0;
}
