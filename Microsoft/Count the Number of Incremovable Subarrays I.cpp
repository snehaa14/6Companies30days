//https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/

class Solution {
public:
    bool check(vector<int> tmp){
        for(int i=1;i<tmp.size();i++){
            if(tmp[i] <= tmp[i-1]) return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                vector<int> temp;
                for(int k=0;k<i;k++)   temp.push_back(nums[k]);
                for(int k=j+1;k<n;k++)  temp.push_back(nums[k]);
                if(check(temp)) ans++;
            }
        }
        return ans;
    }
};