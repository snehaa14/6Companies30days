// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        //no of bulls -> guess in correct position
        //no of cows -> digits hai but wrong position
        //ans in format xAyB x-> no of bulls and y-> no of cows

        int bulls=0,cows=0;
        unordered_map<char,int>mp;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])bulls++;
            else mp[secret[i]]++;
        }
        for(int i=0;i<guess.size();i++)
        {
            if (secret[i] != guess[i] && mp[guess[i]] > 0) 
            {
                cows++;
                mp[guess[i]]--; 
            }
        }
        string ans=to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};