https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int countAtMostK(vector<int>& nums, int k) {
        int l = 0, oddCount = 0, ans = 0,r = 0;

        while (r < nums.size()) 
        {
            if (nums[r] % 2 != 0)   oddCount++;  
            while (oddCount > k) 
            {
                if (nums[l] % 2 != 0)  oddCount--; 
                l++;  
            }
            ans += (r - l + 1);  
            r++; 
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }
};