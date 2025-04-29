class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k)
{
    long long i,j,n,count,ans;
    n=nums.size();
    i=0;
    j=0;
    count=0;
    ans=0;
    int maxi=*max_element(nums.begin(),nums.end());
    while(j<n){
        if(nums[j]==maxi){
            count++;
        }
        if(count<k){
            j++;

        }
        else{
            while(count==k){
                if(nums[i]==maxi){
                    count--;
                }
                i++;

            }
            
            j++;

        }
        ans+=i;
    }
    return ans;

}
};