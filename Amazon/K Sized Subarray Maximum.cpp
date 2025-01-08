//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int findMax(vector<int> arr,int l,int r){
    int ans = INT_MIN;
    for(int i=l;i<=r;i++){
        ans = max(ans,arr[i]);
    }
    return ans;
}

    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        int l =0;
        int r = k-1;
        int maxElement =INT_MIN;
        for(int i{0};i<k;i++){
            maxElement = max(maxElement,arr[i]);
        }
        ans.push_back(maxElement);
        while(r<n-1){
            if(arr[l]==maxElement)
                maxElement = findMax(arr,l+1,r);
            l++;
            r++;
            maxElement = max(maxElement,arr[r]);
            ans.push_back(maxElement);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends