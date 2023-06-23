class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Better Solution by Doing Hashing
        /*
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
        */
        
        int count1=0;
        int count2=0;
        int element1=INT_MIN;
        int element2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(count1==0 && element2!=nums[i])
            {
                count1=1;
                element1=nums[i];
            }
            else if(count2==0 && element1!=nums[i])
            {
                count2=1;
                element2=nums[i];
            }
            else if(element1==nums[i]) count1++;
            else if(element2==nums[i]) count2++;
            else
            {
                count1--,count2--;
            }
        }
        vector<int> ls;
        count1=0;
        count2=0;
        int mini=(int)(n/3)+1;
        for(int i=0;i<n;i++)
        {
            if(element1==nums[i]) count1++;
            if(element2==nums[i]) count2++;
        }
        if(count1>=mini) ls.push_back(element1);
        if(count2>=mini) ls.push_back(element2);
        return ls;
    }
};