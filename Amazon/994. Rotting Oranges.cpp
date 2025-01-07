class Solution {
public:


    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& grid, int& totalfresh, int& count)
     {
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        
        while (!q.empty() && totalfresh != 0) {
            int size = q.size();
            while (size--) 
            {
                int val_i = q.front().first;
                int val_j = q.front().second;
                q.pop();
                
                for (auto d : dirs) {
                    int newx = val_i + d.first;
                    int newy = val_j + d.second;

                    if (newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        totalfresh--;
                        q.push({newx, newy});
                    }
                }
            }
            count++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // 0->empty, 1->fresh orange, 2->rotten orange
        queue<pair<int,int>> q;
        int totalfresh = 0;

        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if (grid[i][j] == 1) totalfresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        if (totalfresh == 0) return 0;

        int count = 0;
        bfs(q, grid, totalfresh, count);
        return totalfresh == 0 ? count : -1;
    }
};
