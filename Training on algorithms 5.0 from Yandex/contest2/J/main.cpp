#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y, char c, vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = c;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '#') {
                q.push({nx, ny});
                grid[nx][ny] = c;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int rectangles = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '#') {
                if (rectangles == 2) {
                    cout << "NO\n";
                    return 0;
                }
                bfs(i, j, 'a' + rectangles, grid);
                ++rectangles;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    if (rectangles != 2) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') {
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '.') {
                            grid[i][j] = grid[nx][ny];
                        }
                    }
                }
            }
        }

        cout << "YES\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
