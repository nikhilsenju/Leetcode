class Solution {
public:
    int f(int ind , vector<int>&freq,vector<string>&arr){
        if(ind==arr.size()){
            return 0;
        }
        vector<int> tmp(26,0);
        int fl = 0;
        for(auto i:arr[ind]){
            tmp[i-'a']++;
            if(tmp[i-'a']>1){
                fl=1;
                break;
            }
        }
        int notake = f(ind+1,freq,arr);
        if(fl){
            return notake;
        }
        else{
            int ff =0;
            int take = 0;
            for(auto i:arr[ind]){
                if(freq[i-'a']>=1){
                    ff=1;
                    break;
                }
            }
            if(!ff){
                for(auto i:arr[ind]){
                    freq[i-'a']++;
                }
                take = arr[ind].size()+f(ind+1,freq,arr);
                for(auto i:arr[ind]){
                    freq[i-'a']--;
                }
            }
            return max(take,notake);

        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> freq(26,0);
        return f(0,freq,arr);

        
    }
};