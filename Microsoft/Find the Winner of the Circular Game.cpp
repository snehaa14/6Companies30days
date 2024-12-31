//https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int solve(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++)  ans = (ans + k) % i;

        return ans;
    }
    int findTheWinner(int n, int k) {
        return solve(n,k)+1;  
    }
};