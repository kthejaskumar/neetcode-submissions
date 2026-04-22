class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt=1;
        int largest=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int num1 = nums[i];
            if(num1==nums[i+1]) continue;
            num1=num1+1;
            if(num1==nums[i+1]){
                cnt++;
                largest = max(largest,cnt);
            }
            else{
                cnt=1;
            }
        }
        return largest;
    }
};
