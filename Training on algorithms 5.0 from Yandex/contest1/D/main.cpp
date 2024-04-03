#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<vector<char>> grid(8, vector<char>(8));
	vector<pair<int, int>> elephant;
	vector<pair<int, int>> rook;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'B')
				elephant.push_back({i, j});
			if (grid[i][j] == 'R')
				rook.push_back({i, j});
		}
	}

	for (auto& e : elephant) {
		int i = e.first - 1, j = e.second + 1;
		while (i >= 0 && j < 8 && (grid[i][j] == '*' || grid[i][j] == '.'))
			grid[i--][j++] = '.';
		i = e.first - 1, j = e.second - 1;
		while (i >= 0 && j >= 0 && (grid[i][j] == '*' || grid[i][j] == '.'))
			grid[i--][j--] = '.';
		i = e.first + 1, j = e.second - 1;
		while (i < 8 && j >= 0 && (grid[i][j] == '*' || grid[i][j] == '.'))
			grid[i++][j--] = '.';
		i = e.first + 1, j = e.second + 1;
		while (i < 8 && j < 8 && (grid[i][j] == '*' || grid[i][j] == '.'))
			grid[i++][j++] = '.';		
	}

	for (auto& r : rook) {
		int i = r.first - 1;
		while (i >= 0 && (grid[i][r.second] == '*' || grid[i][r.second] == '.'))
			grid[i--][r.second] = '.';
		i = r.first + 1;
		while (i < 8 && (grid[i][r.second] == '*' || grid[i][r.second] == '.'))
			grid[i++][r.second] = '.';
		i = r.second - 1;
		while (i >= 0 && (grid[r.first][i] == '*' || grid[r.first][i] == '.'))
			grid[r.first][i--] = '.';
		i = r.second + 1;
		while (i < 8 && (grid[r.first][i] == '*' || grid[r.first][i] == '.'))
			grid[r.first][i++] = '.';
	}

	int count = 0;
	for (auto& row : grid)
		for (char c : row)
			if (c == '*') ++count;

	cout << count << endl;

	return 0;
}
