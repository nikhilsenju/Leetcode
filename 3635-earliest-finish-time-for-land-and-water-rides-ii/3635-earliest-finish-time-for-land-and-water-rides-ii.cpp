class Solution {
public:
    int solve(vector<int>&st1,vector<int>&d1,vector<int>&st2,vector<int>&d2){
        int fin1 = INT_MAX;
        for(int i = 0;i<st1.size();i++){
            fin1 = min(fin1,st1[i]+d1[i]);
        }
        int fin2 = INT_MAX;
        for(int i=0;i<st2.size();i++){
            fin2 = min(fin2,max(fin1,st2[i])+d2[i]);
        }
        return fin2;
    }
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int wl = solve(wst,wd,lst,ld);
        int lw = solve(lst,ld,wst,wd);
        return min(wl,lw);
    }
};