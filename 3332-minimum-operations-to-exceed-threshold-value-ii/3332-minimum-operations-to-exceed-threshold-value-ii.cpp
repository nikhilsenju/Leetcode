typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<ll> mt(nums.begin(),nums.end());
        ll op = 0;
        while(mt.size()>=2){
            ll first = *(mt.begin());
            if(first>=k){
                break;
            }
            mt.erase(mt.begin());
            ll second = *(mt.begin());
            mt.erase(mt.begin());
            mt.insert(min(first,second)*2+max(first,second));
            op++;

        }
        return op;
        
    }
};