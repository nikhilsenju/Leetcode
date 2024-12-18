#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> 

class Solution {
public:
    int countRangeSum(vector<int>& nums, int l, int u) { 
        ordered_set os;
        os.insert(0);
        long long sum =0;
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int hi = os.order_of_key(sum-l+1);
            int lo = os.order_of_key(sum-u);
            ans+=(hi-lo);
            os.insert(sum);
        }
        return ans;     
    }
};