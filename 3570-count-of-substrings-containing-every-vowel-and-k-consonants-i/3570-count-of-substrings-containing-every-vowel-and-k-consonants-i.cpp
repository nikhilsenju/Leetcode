class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int count = 0;
        int n = word.size();
        for(int i=0;i<=n-(k+5);i++){
            for(int j=k+4;j<n;j++){
                int c=0;
                unordered_map<char , int > mp;
                for(int l=i;l<=j;l++){
                    if(word[l]=='a' || word[l]=='e' || word[l]=='i' || word[l]=='o' || word[l]=='u'){
                        mp[word[l]]++;
                        
                    }
                    else{
                        c++;
                    }

                }
                if(mp.size()>=5 && c==k) {
                    count++;

                }

            }
        }
        return count;
        
    }
};