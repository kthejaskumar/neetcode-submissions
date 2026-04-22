class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone: stones){
            pq.push(stone);
        }
        int x;
        while(pq.size()>1){
            x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x>y || y>x){
                int val = abs(x-y);
                pq.push(val);
            }
        }
        pq.push(0);
        return pq.top();
    }
};
