class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int num1 = 0, num2 = 0, num3 = 0;
        bool check1 = false, check2 = false, check3 = false;
        for(auto num: triplets){
            if(num[0]>target[0] || num[1]>target[1] || num[2]>target[2]) continue;
            if(!check1){
                if(target[0]==num[0]){
                    num1 = num[0];
                    check1 = true;
                }
            }
            if(!check2){
                if(target[1]==num[1]){
                    num2 = num[1];
                    check2 = true;
                }
            }
            if(!check3){
                if(target[2]==num[2]){
                    num3 = num[2];
                    check3 = true;
                }
            }
        }
        // cout<<"num1 "<<num1<<endl;
        // cout<<"num2 "<<num2<<endl;
        // cout<<"num3 "<<num3<<endl;
        if(check1 && check2 && check3) return true;
        else return false;
    }
};
