//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int noofstudents(int A[],int N,int pages)
    {
        int students=1;
        long long pagesStudent=0;
        for(int i=0;i<N;i++)
        {
            if(pagesStudent+A[i]<=pages)
            {
                pagesStudent+=A[i];
            }
            else
            {
                students+=1;
                pagesStudent=A[i];
            }
        }
        return students;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int low=*max_element(A,A+N);
        int high=accumulate(A,A+N,0);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int students=noofstudents(A,N,mid);
            if(students>M)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
          return low;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends