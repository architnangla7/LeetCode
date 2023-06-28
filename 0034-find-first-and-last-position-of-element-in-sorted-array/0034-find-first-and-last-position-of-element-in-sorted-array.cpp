class Solution {
public:
    int lowerBound(vector<int> &arr, int x){
    int n=arr.size();
	int low=0;
	int high=n-1;
	int ans=n;
	while(low<=high)
	{
		int mid=(low+(high-low)/2);
		if(arr[mid]>=x)
		{
			ans=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return ans;
}
    int upperBound(vector<int> &arr, int x){
	int n=arr.size();
    int low=0;
	int high=n-1;
	int ans=n;
	while(low<=high)
	{
		int mid=(low+(high-low)/2);
		if(arr[mid]>x)
		{
			ans=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return ans;
}	
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerBound(nums,target);
        if(lb==n || nums[lb]!=target)
        {
            return {-1,-1};
        }
        return {lb,upperBound(nums,target)-1};
    }
};