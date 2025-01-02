// https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sortedNums = nums;
        int n = nums.size();
        int largeIndex = (n - 1); 
        int smallIndex = (n - 1) / 2; 
        for (int i = 0; i < n; i++) 
        {
            if (i % 2 == 0)   nums[i] = sortedNums[smallIndex--];  //small at even
            else  nums[i] = sortedNums[largeIndex--]; 
        }
    }
};
