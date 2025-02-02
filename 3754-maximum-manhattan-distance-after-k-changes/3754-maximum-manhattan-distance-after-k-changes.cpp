class Solution {
public:
    int maxDistance(string ss, int k) {
        int n = 0;
        int w = 0;
        int e = 0;
        int s = 0;
        int maxi = 0;
        for(int i=0;i<ss.size();i++){
            if(ss[i]=='N'){n++;}
            else if(ss[i]=='E'){e++;}
            else if(ss[i]=='S'){s++;}
            else{w++;}
            maxi=max(maxi,max(n,s)+max(e,w)-min(n,s)-min(e,w)+2*min(k,min(n,s)+min(e,w)));


         
        }
        return maxi;
        
    }
};