//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
     int solve(vector<int>& prices,int i,bool buy,int limit)
    {
        if(i>=prices.size())return 0;
        if(limit==0)return 0;
        int ans1=0,ans2=0;
        if(buy)
        {
            int take= -prices[i]+solve(prices,i+1,!buy,limit);
            int nottake=0+solve(prices,i+1,buy,limit);
             ans1=max(take,nottake);
        }
        else{
            int take=prices[i]+solve(prices,i+1,!buy,limit-1);
            int nottake=0+solve(prices,i+1,buy,limit);
            ans2=max(take,nottake);
        }
        return max(ans1,ans2);
    }

     int solveUsingMemo(vector<int>& prices,int i,bool buy,int limit,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size())return 0;
        if(limit==0)return 0;

        if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];

        int ans1=0,ans2=0;
        if(buy)
        {
            int take= -prices[i]+solveUsingMemo(prices,i+1,!buy,limit,dp);
            int nottake=0+solveUsingMemo(prices,i+1,buy,limit,dp);
             ans1=max(take,nottake);
        }
        else{
            int take=prices[i]+solveUsingMemo(prices,i+1,!buy,limit-1,dp);
            int nottake=0+solveUsingMemo(prices,i+1,buy,limit,dp);
            ans2=max(take,nottake);
        }
        return dp[i][buy][limit]=max(ans1,ans2);
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solveUsingMemo(prices,0,true,k,dp);
    }
};