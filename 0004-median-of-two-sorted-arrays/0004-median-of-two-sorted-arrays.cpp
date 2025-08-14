class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int tot = n1+n2;
        int left = (tot+1)/2;
        int lo = 0;
        int hi = n1;
        while(hi>=lo){
            int mid1 = (lo+hi)>>1;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1<n1){
                r1 = nums1[mid1];
            }
            if(mid2<n2){
                r2 = nums2[mid2];
            }
            if(mid1-1>=0){
                l1 = nums1[mid1-1];
            }
            if(mid2-1>=0){
                l2 = nums2[mid2-1];
            }
            if(l1<=r2 && l2<=r1){
                if(tot%2){
                    return double(max(l1,l2));
                }
                return double(max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1>r2){
                hi = mid1-1;
            }
            else{
                lo = mid1+1;
            }

        }
        return -1;
    }
};