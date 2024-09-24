class Solution {
public:
    typedef long long ll;
 int longestCommonPrefix(vector<int>& a, vector<int>& b) {
 	map<string,ll> mp;
 	for(auto i:a){
 		string s;
 		string tmp=to_string(i);
 		for(auto j:tmp){
 			s.push_back(j);
 			mp[s]=s.size();

 		}

 	}
 	ll mini=0;
 	for(auto i:b){
 		string s;
 		string tmp=to_string(i);
 		for(auto j:tmp){
 			s.push_back(j);
 			if(mp.find(s)!=mp.end()){
 				mini=max(mini,mp[s]);
 			}

 		}
 	}
 	return mini;


        
 }

};