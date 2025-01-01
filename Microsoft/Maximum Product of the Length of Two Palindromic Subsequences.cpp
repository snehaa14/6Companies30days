//https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/

class Solution {
public:
    unordered_map<string,int>mp;
    bool ispalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }


    int solve(string &s,int i,string s1,string s2){
        if(i==s.size())
        {
     if(s1.size() && s2.size() && ispalindrome(s1) && ispalindrome(s2)) return s1.size()*s2.size();
            return 0;
        }

        string key=to_string(i)+","+s1+","+s2;

        if(mp.find(key)!=mp.end()) return mp[key];

        int a=solve(s,i+1,s1+s[i],s2);
        int b=solve(s,i+1,s1,s2+s[i]); 
        int c=solve(s,i+1,s1,s2);

        return mp[key]=max(a,max(b,c));
    }

    int maxProduct(string s) {
        return solve(s,0,"","");
    }
};