class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ls;
        int n=nums.size();
        map<int,int> mpp;
        int mini=(int)(n/3)+1;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==mini){
                ls.push_back(nums[i]);
            }
        }
        return ls;
    }
};