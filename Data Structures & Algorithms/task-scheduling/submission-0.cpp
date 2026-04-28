class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);

        for(auto s : tasks){
            count[s - 'A']++;
        }

        priority_queue<int> maxHeap;

        for(int cnt : count){
            if(cnt>0){
                maxHeap.push(cnt);
            }
        }

        queue<pair<int,int>> que;
        int time=0;
        while(!maxHeap.empty() || !que.empty()){
            time++;
            if(maxHeap.empty()){
                time = que.front().second;
            }
            else{
                int cnt = maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0){
                    que.push({cnt,time+n});
                }
            }

            if(!que.empty() && que.front().second == time){
                maxHeap.push(que.front().first);
                que.pop();
            }
        }
        return time;
    }
    
};
