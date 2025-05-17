class Solution{
public:
	int solve(vector<int>&v,int val){
		int idx = v.size();
		int lo = 0;
		int hi = v.size()-1;	
		while(hi>=lo){
			int mid = (hi+lo)/2;
			if(val<=v[mid]){
				idx = mid;
				hi = mid-1;
			}
			else{
				lo  = mid+1;
			}
		}
		return idx;
	}
	int lengthOfLIS(vector<int>&nums){
		int n = nums.size();
		vector<int> ans;
		ans.push_back(nums[0]);
		for(int i=1;i<n;i++){
			int idx = solve(ans,nums[i]);
			if(idx==ans.size()){
				ans.push_back(nums[i]);
			}
			else{
				ans[idx]=nums[i];
			}
		}
		return ans.size();
	}	
};