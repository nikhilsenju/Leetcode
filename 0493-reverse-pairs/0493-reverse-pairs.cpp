#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<long long, null_type, greater_equal   <long long>, rb_tree_tag, tree_order_statistics_node_update> 

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set os;
        int ans=0;
        for(auto i:nums){
            long long y = (long long)2*i;
            int x = os.order_of_key(y);
            ans+=x;
            os.insert(i);
        }
        return ans;
        
    }
};