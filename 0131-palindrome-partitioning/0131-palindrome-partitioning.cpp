class Solution {
public:
    bool isPalindrome(string &curr){
        int i=0;
        int j=curr.size()-1;
        while(j>=i){
            if(curr[i]!=curr[j]){
                return false;
            }
            else{
                i++;
                j--;
            }

        }
        return true;

    }
    void count(int ind , string s , vector<string>&path,vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = ind ; i < s.size() ; i++){
            string curr = s.substr(ind,i-ind+1);
            if(isPalindrome(curr)){
                path.push_back(curr);
                count(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> path;
        vector<vector<string>> ans;
        count(0,s,path,ans);
        return ans;
    }
};