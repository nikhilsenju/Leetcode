#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set1                                                           \
    tree<long long, null_type, less_equal<long long>, rb_tree_tag,             \
         tree_order_statistics_node_update>

#define ordered_set2                                                          \
    tree<long long, null_type, greater_equal<long long>, rb_tree_tag,             \
         tree_order_statistics_node_update>
#define MOD 1000000007
class Solution {
public:
    int createSortedArray(vector<int>& v) {
        ordered_set1 os1;
        ordered_set2 os2;
        int n = v.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x = os1.order_of_key(v[i]);
            int y = os2.order_of_key(v[i]);
            sum=(sum+min(x,y))%MOD;
            sum%=MOD;
            os1.insert(v[i]);
            os2.insert(v[i]);
            
        }
        return sum;
    }
};