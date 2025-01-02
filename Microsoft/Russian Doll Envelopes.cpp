//https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }

int solve(vector<vector<int>>& envelopes,int prev,int i)
    {
        if(i==envelopes.size())return 0;

        int take=INT_MIN;
        if(prev==-1 ||(envelopes[prev][0]<envelopes[i][0] && envelopes[prev][1]<envelopes[i][1]))
        take=1+solve(envelopes,i,i+1);
        int nottake=0+solve(envelopes,prev,i+1);
        return max(take,nottake);
        
    }

    int solve(vector<vector<int>>& envelopes,int prev,int i,vector<vector<int>>& dp)
    {
        if(i==envelopes.size())return 0;

        if(dp[prev+1][i]!=-1)return dp[prev+1][i];

        int take=INT_MIN;
        if(prev==-1 ||(envelopes[prev][0]<envelopes[i][0] && envelopes[prev][1]<envelopes[i][1]))
        take=1+solve(envelopes,i,i+1,dp);
        int nottake=0+solve(envelopes,prev,i+1,dp);
        return dp[prev+1][i]= max(take,nottake);
    }


    int solveUsingBinarySearch(vector<vector<int>>&nums)
     {
        vector<int>ans;
        ans.push_back(nums[0][1]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][1]>ans.back())ans.push_back(nums[i][1]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
                ans[index]=nums[i][1];
            }
        }
        return ans.size();
     }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
         int n=envelopes.size();
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), comp);
    //    vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        return solveUsingBinarySearch(envelopes);
    }
};