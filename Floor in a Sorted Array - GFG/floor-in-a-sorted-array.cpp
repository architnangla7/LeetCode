//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int lowerbound(vector<long long> arr,long long n,long long target)
    {
        int m=arr.size();
        int low=0;
        long long int high=n-1;
        int ans=-1;
        while(low<=high)
        {
            long long int mid=(low+(high-low)/2);
            if(arr[mid] == target)
            {
                return mid;
            }
            else if(arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
    int findFloor(vector<long long> v, long long n, long long x){
        
        return lowerbound(v,n,x);
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends