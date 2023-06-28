class Solution {
public:
    int insertposition(vector<int> &nums,int x)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==x)
            {
                return mid;
            }
            else if(nums[mid]>x)
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
    int searchInsert(vector<int>& nums, int target) {
        return insertposition(nums,target);
    }
};