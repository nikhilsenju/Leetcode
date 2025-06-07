class Solution {
public:
    struct Node{
        char ch;
        int idx;
        Node(char ch, int idx):ch(ch),idx(idx){}
        bool operator>(const Node& other)const{
            if(ch!=other.ch){
                return ch>other.ch;
            }
            return idx<other.idx;
        }

    };
    string clearStars(string s) {
        int n = s.size();
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    auto it = pq.top();
                    pq.pop();
                    int idx = it.idx;
                    s[idx]='.';
                }
                s[i]='.';
            }
            else{
            pq.push(Node(s[i],i));
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};