class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        set<string> st(wl.begin(),wl.end());
        queue<pair<string,int>> q;
        q.push({bw,1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int level = it.second;
            if(word==ew){
                return level;
            }
            for(int i=0;i<word.size();i++){
                string tmp=word;
                for(char c = 'a';c<='z';c++){
                    tmp[i]=c;
                    if(st.count(tmp)){
                        q.push({tmp,level+1});
                        st.erase(tmp);
                    }   
                }
            }
        }
        return 0;
        
    }
};