#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> 

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_set os;
        long long ans=0;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            int x = os.order_of_key(nums1[i]-nums2[i]+diff+1);
            ans+=x;
            os.insert(nums1[i]-nums2[i]);
        }
        return ans;


        
    }
};