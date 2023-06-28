class Solution {
public:
    //By using concept of lower bound and upperbound
    /*
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
*/
    
    int firstoccurence(vector<int> &nums,int target)
    {
        int n=nums.size();
        int first=-1;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return first;
    }
    int lastoccurence(vector<int> &nums,int target)
    {
        int n=nums.size();
        int last=-1;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        int n=nums.size();
        int lb=lowerBound(nums,target);
        if(lb==n || nums[lb]!=target)
        {
            return {-1,-1};
        }
        return {lb,upperBound(nums,target)-1};
        */
        int first=firstoccurence(nums,target);
        if(first==-1) return {-1,-1};
        int last=lastoccurence(nums,target);
        return {first,last};
    }
};