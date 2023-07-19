class Solution {
public:
    int getMinimizedLargestSum(vector<int>&nums,int k){
        int n=nums.size();
        int numSplits=1;
        long long currentSum=0;
        for(int i=0;i<n;i++){
            if(currentSum+nums[i]<=k){
                currentSum+=nums[i];
            }
            else{
                numSplits++;
                currentSum=nums[i];
            }
        }
        return numSplits;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int numSplits=getMinimizedLargestSum(nums,mid);
            if(numSplits>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};