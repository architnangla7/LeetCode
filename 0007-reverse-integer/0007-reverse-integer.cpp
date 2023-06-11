class Solution {
public:
    int answer=0;
    int reverse(int x) {
        while(x!=0)
        {
            int digit=x%10;
            if((answer>INT_MAX/10)||(answer<INT_MIN/10))
            {
                return 0;
            }
            answer=(answer*10)+digit;
            x=x/10;
        }
        return answer;
    }
};