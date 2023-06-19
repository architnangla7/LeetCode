class Solution {
public:
    bool isPalindrome(int x) {
        int duplicate=x;
        long long int ans=0;
        while(x>0)
        {
            int lastdigit=x%10;
            x=x/10;
            ans=(ans*10)+lastdigit;
        }
        if(ans==duplicate)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};