class Solution {
public:
    int dp[32][32][2];
  
    int solve(int st, int jump, int d, int f, int k)
    {
        if(st > k+1) return 0;

        if(dp[jump][d][f] != -1) return dp[jump][d][f];
        int ans = 0;

        if(st==k) ans++;
        ans += solve(st+(1<<jump),jump+1,d,1,k);

        if(f) ans += solve(st-1,jump,d+1,0,k);
        return dp[jump][d][f] = ans;
    }
    int waysToReachStair(int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(1,0,0,1,k);
    }
};