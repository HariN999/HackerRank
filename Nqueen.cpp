#include <bits/stdc++.h>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Distance from queen to board edges in all 8 directions
    int up = n - r_q;
    int down = r_q - 1;
    int left = c_q - 1;
    int right = n - c_q;
    int upLeft = min(up, left);
    int upRight = min(up, right);
    int downLeft = min(down, left);
    int downRight = min(down, right);

    // Store the closest obstacle in each direction
    map<pair<int, int>, int> obstacleMap;
    for (auto& obs : obstacles) {
        int r = obs[0], c = obs[1];
        if (c == c_q) { // Same column (up/down)
            if (r > r_q) up = min(up, r - r_q - 1);
            else down = min(down, r_q - r - 1);
        } else if (r == r_q) { // Same row (left/right)
            if (c > c_q) right = min(right, c - c_q - 1);
            else left = min(left, c_q - c - 1);
        } else if (abs(r - r_q) == abs(c - c_q)) { // Diagonal
            if (r > r_q && c < c_q) upLeft = min(upLeft, r - r_q - 1);
            else if (r > r_q && c > c_q) upRight = min(upRight, r - r_q - 1);
            else if (r < r_q && c < c_q) downLeft = min(downLeft, r_q - r - 1);
            else if (r < r_q && c > c_q) downRight = min(downRight, r_q - r - 1);
        }
    }

    // Sum up all the squares the queen can attack
    return up + down + left + right + upLeft + upRight + downLeft + downRight;
}

int main() {
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    return 0;
}
