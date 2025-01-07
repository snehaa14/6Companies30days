class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        long long i=0,j=0,maxi=0,sum=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            sum+=nums[j];

            if(j-i+1<k)j++;
            
            else if(j-i+1==k)
            {
                if(mp.size()==k)maxi=max(maxi,sum);
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};