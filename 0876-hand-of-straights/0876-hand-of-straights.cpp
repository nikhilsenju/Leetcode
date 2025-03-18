class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {
        multiset<int> mt;
        for(auto i:hand){
            mt.insert(i);
        }
        while(!mt.empty()){
            auto it = *(mt.begin());
            cout<<it<<" ";
            mt.erase(mt.begin());
            int k = n-1;
            while(k--){
                if(mt.find(it+1)==mt.end()){
                    return false;
                }
                mt.erase(mt.find(it+1));
                it = it+1;
            }
        }
        return true;

        
    }
};