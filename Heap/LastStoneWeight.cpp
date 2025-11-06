class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>H;
        for(int i = 0; i<stones.size();i++){
            H.push(stones[i]);
        }
        while(H.size() > 1){
            int weight = H.top();
            H.pop();
            weight -=H.top();
            H.pop();
            if(weight){
                H.push(weight);
            }
        }
        return H.empty()?0: H.top();
    }
};