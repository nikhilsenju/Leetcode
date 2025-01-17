class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        vector<int> v;
        v.push_back(1);
        int c=1;
        for(int i=0;i<d.size()-1;i++){
            c^=d[i];
            v.push_back(c);

        }
        vector<int> tmp;
        for(int i=0;i<v.size()-1;i++){
            tmp.push_back(v[i]^v[i+1]);
        }
        tmp.push_back(v.back()^v[0]);
        return tmp==d;


        
    }
};