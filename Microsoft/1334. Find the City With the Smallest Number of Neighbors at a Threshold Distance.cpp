class Solution {
public:
    //  Floyd-Warshall algorithm
    void floydWarshall(int n, vector<vector<int>>& dist) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> dist(n, vector<int>(n, 10001));
        
        for (int i = 0; i < n; i++)  dist[i][i] = 0;
        
        for (const auto& i : edges) 
        {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        
        floydWarshall(n, dist);
        
        int minReachableCities = n, ans = -1;

        for (int i = 0; i < n; i++) 
        {
            int count = 0;
            for (int j = 0; j < n; j++) 
            {
                if (dist[i][j] <= distanceThreshold) count++;
            }
            if (count <= minReachableCities)
            {
                minReachableCities = count;
                ans = i;
            }
        }
        
        return ans;
    }
};
