class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long long n1 = nums1.size();
        long long n2 = nums2.size();
        if(n1>n2){
            swap(nums1,nums2);
            swap(n1,n2);
        }
        long long lo = 0;
        long long hi = nums1.size();
        long long left = (n1+n2+1)/2;
        long long n = n1+n2;
        while(hi>=lo){
            long long mid = (hi+lo)>>1;
            long long mid1 = mid;
            long long mid2 = left - mid1;
            long long l1 = INT_MIN;
            long long l2 = INT_MIN;
            long long r1 = INT_MAX;
            long long r2 = INT_MAX;
            if(mid1-1>=0){
                l1 = nums1[mid1-1];
            }
            if(mid2-1>=0){
                l2 = nums2[mid2-1];
            }
            if(mid1<n1){
                r1 = nums1[mid1];
            }
            if(mid2<n2){
                r2 = nums2[mid2];
            }
            if(l1<=r2 && l2<=r1){
                if(n%2){
                    return double(max(l1,l2));
                }
                return (double)((max(l1,l2)+min(r1,r2))/2.0);
            }
            else if(l1>r2){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return 0;
    }
};