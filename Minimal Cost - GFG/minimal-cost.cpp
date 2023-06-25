//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    //Memoization
    /* 
    int f(int ind,vector<int> &height,vector<int> &dp,int k)
    {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int minsteps=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(ind-j>=0)
            {
                int jump=f(ind-j,height,dp,k)+abs(height[ind]-height[ind-j]);
                minsteps=min(jump,minsteps);
            }
        }
        return minsteps;
    }
    */
    int minimizeCost(vector<int>& height, int n, int k) {
        //Memoization
        /*
        vector<int> dp(n,-1);
        return f(n-1,height,dp,k);
        */
        
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int minsteps=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0){
                int jump=dp[i-j]+abs(height[i]-height[i-j]);
                minsteps=min(jump,minsteps);
                }
            }
             dp[i]=minsteps;
        }
        return dp[n-1];
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends