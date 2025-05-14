struct Node{
	Node * links[2];
	bool flag = false;

	bool containsKey(int bit){
		return links[bit]!=NULL;
	}

	void put(int bit , Node * node){
		links[bit]=node;
	}

	Node * get(int bit){
		return links[bit];
	}

};

class Trie{
private:
	Node * root;
public:
	Trie(){
		root = new Node();
	}

	void insert(int num){
		Node * node = root;
		for(int i=31;i>=0;i--){
			int bit = (num>>i)&1;
			if(!node->containsKey(bit)){
				node->put(bit,new Node());
			}
			node = node->get(bit);
		}

	}

	int getMax(int x){
		Node * node = root;
		int maxAns = 0;
		for(int i=31;i>=0;i--){
			int bit = (x>>i)&1;
			if(node->containsKey(1-bit)){
				maxAns+=(1<<i);
				node = node->get(1-bit);
			}
			else{
				node = node->get(bit);
			}
		}
		return maxAns;
	}


};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
    	int n = q.size();
    	sort(nums.begin(),nums.end());
    	vector<pair<int,pair<int,int>>> vp;
    	for(int i=0;i<q.size();i++){
    		int x = q[i][0];
    		int y = q[i][1];
    		vp.push_back({y,{x,i}});
    	}
    	sort(vp.begin(),vp.end());
    	vector<int>ans(n,0);
    	int j=0;
    	Trie trie;

    	for(int i=0;i<vp.size();i++){
    		int xi = vp[i].second.first;
    		int idx = vp[i].second.second;
    		int ai = vp[i].first;
    		while(j<nums.size() && ai>=nums[j]){
    			trie.insert(nums[j]);
    			j++;
    		} 
    		if(j == 0 ){
    			ans[idx]=-1;
    		}
    		else{
    			ans[idx]=trie.getMax(xi);
    		}
    }
    	return ans;


        
    }
};
