class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // multi-source BFS from thieves
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();

            for(int k=0; k<4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni>=0 && nj>=0 && ni<n && nj<n && dist[ni][nj] == INT_MAX) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }

        // max-heap: {safeness, {i, j}}
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], {0, 0}});
        best[0][0] = dist[0][0];

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int safe = top.first;
            int i = top.second.first;
            int j = top.second.second;

            if(i == n-1 && j == n-1) return safe;

            for(int k=0; k<4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni>=0 && nj>=0 && ni<n && nj<n) {
                    int newSafe = min(safe, dist[ni][nj]);

                    if(newSafe > best[ni][nj]) {
                        best[ni][nj] = newSafe;
                        pq.push({newSafe, {ni,nj}});
                    }
                }
            }
        }

        return 0;
    }
};
