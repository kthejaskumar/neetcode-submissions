class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = sumofsquares(n);

        while(slow!=fast){
            fast = sumofsquares(fast);
            fast = sumofsquares(fast);
            slow = sumofsquares(slow);
        }

        return fast == 1;
    }

    int sumofsquares(int n){
        int output=0;
        while(n>0){
            int digit = n%10;
            digit = digit * digit;
            output+=digit;
            n = n/10;
        }
        return output;
    }
};
