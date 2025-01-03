// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

class Solution {
public: 
    vector<vector<int>> rects;
    int i=0;
    int x,y;
    Solution(vector<vector<int>>& rects) 
    {
        this->rects=rects;
        x=rects[i][0];
        y=rects[i][1];
    }
    
    vector<int> pick() {
        vector<int>ans={x,y};
        x++;
        if(x>rects[i][2])
        {
            x=rects[i][0];
            y++;
        }
        if(y>rects[i][3])
        {
            if(i<rects.size()-1)i++;
            else  i=0;
            x=rects[i][0];
            y=rects[i][1];
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */