class NumberContainers {
public:
    map<int,int> mp;
    map<int,set<int>> mpc;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(mp.find(index)!=mp.end()){
            int old  = mp[index];
            auto &st = mpc[old];
            st.erase(index);
            mp[index]=number;
            mpc[number].insert(index);
        }
        else{
            mp[index]=number;
            mpc[number].insert(index);
        }
        
    }
    
    int find(int number) {
        if(mpc.find(number)==mpc.end()){
            return -1;
        }
        auto &st=mpc[number];
        if(st.size()==0){
            mpc.erase(number);
            return -1;
        }
        return *(st.begin());
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */