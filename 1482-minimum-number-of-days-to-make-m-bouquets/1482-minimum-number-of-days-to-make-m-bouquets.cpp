class Solution {
public:
    int possible(vector<int> &bloomDay,int day,int m,int k)
    {
        int count=0;
        int noofB=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                count++;
            }
            else
            {
                noofB+=(count/k);
                count=0;
            }
        }
        noofB+=(count/k);
        return noofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long value=m*1LL*k*1LL;
        if(value>bloomDay.size()) return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};