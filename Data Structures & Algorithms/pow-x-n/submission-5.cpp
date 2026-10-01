class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        bool neg = false;
        if(n<0){
            neg = true;
            n = n*-1;
        }
        double ans = power(x,n);
        return (neg?1/ans:ans);
    }

    double power(double x, int n){
        if(n==1){
            return x;
        }
        double val = myPow(x,n/2);
        if(n%2){
            return val * val * x;
        }else{
            return val * val;
        }
    }
};
