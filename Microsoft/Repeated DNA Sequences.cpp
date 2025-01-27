//https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector <string> ans;
        if(s.size() < 10)return ans;
        unordered_map <string,int> mp;
        for(int i=0;i<s.size()-9;i++)
        {
        string t = s.substr(i,10);
        mp[t]++;
        }
        
        for(auto it : mp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};