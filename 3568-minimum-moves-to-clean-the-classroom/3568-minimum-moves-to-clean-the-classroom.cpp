class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        int cnt = 0;

        // Store ID of each litter
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    litterId[i][j] = cnt++;
                }
                else if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        // bestenergy[x][y][mask] = maximum energy
        // with which we have reached (x,y) having mask
        vector<vector<vector<int>>> bestenergy(
            m, vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        int fullmask = (1 << cnt) - 1;

        // {x, y, remainingEnergy, mask, steps}
        queue<vector<int>> q;

        q.push({sx, sy, energy, 0, 0});

        bestenergy[sx][sy][0] = energy;

        vector<pair<int, int>> dirn = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it[0];
            int y = it[1];
            int remenergy = it[2];
            int mask = it[3];
            int steps = it[4];

            if (mask == fullmask)
                return steps;

            for (auto dir : dirn) {
                int dx = dir.first + x;
                int dy = dir.second + y;

                // Outside grid
                if (dx < 0 || dy < 0 || dx >= m || dy >= n)
                    continue;

                // Obstacle
                if (classroom[dx][dy] == 'X')
                    continue;

                // No energy to make a move
                if (remenergy == 0)
                    continue;

                int newEnergy = remenergy - 1;
                int newMask = mask;

                // If we reach litter, collect it
                if (classroom[dx][dy] == 'L') {
                    int id = litterId[dx][dy];
                    newMask = newMask | (1 << id);
                }

                // If we reach reset area, restore energy
                if (classroom[dx][dy] == 'R') {
                    newEnergy = energy;
                }

                // Only visit if we have MORE energy than before
                if (newEnergy > bestenergy[dx][dy][newMask]) {
                    bestenergy[dx][dy][newMask] = newEnergy;

                    q.push({
                        dx,
                        dy,
                        newEnergy,
                        newMask,
                        steps + 1
                    });
                }
            }
        }

        return -1;
    }
};