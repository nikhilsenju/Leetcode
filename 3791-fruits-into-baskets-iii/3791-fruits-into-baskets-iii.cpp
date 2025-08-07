
struct node{
    // int mn;
    int mx;
    // int sum;
    // int gcd;
    node(){
        // mn =  1e9;
        mx = -1e9;
        // gcd = 0;
        // sum = 0;
    }
};

node merge(node a , node b){
    node ans;
    ans.mx = max(a.mx , b.mx);
    // ans.mn = min(a.mn , b.mn);
    // ans.sum = a.sum + b.sum;
    // ans.gcd = __gcd(a.gcd,b.gcd);
    return ans;
}
node t[4*200020];

void build(int id , int l , int r,vector<int>&v){
    if(l==r){
        t[id].mx = v[l];
        // t[id].sum = v[l];
        // t[id].gcd= v[l];
        // t[id].mn = v[l];
        return; 
    }
    int mid = (l+r)/2;
    build(2*id , l , mid ,v);
    build(2*id+1, mid +1 , r, v);
    t[id]=merge(t[2*id],t[2*id+1]);
}

void update(int id ,int l ,int r, int pos ,int val){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        // t[id].sum = val;
        t[id].mx = val;
        // t[id].mn = val;
        // t[id].gcd = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[2*id],t[2*id+1]);
}

node query(int id ,int l ,int r, int lq ,int rq){
    if(l>rq || lq>r){
        return node();
    }
    if(lq<=l  &&  r<=rq){
        return t[id]; 
    }
    int mid  = (l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = b.size();
        build(1,0,n-1,b);
        int unplaced = 0;
        for(auto i:f){
            int ele  = i;
            int maxi = query(1,0,n-1,0,n-1).mx;
            if(ele>maxi){
                unplaced++;
                continue;
            }
            int lo = 0;
            int hi = n-1;
            int ans = 0;
            while(hi>=lo){
                int mid = (hi+lo)>>1;
                int left = query(1,0,n-1,lo,mid).mx;
                int right = query(1,0,n-1,mid+1,hi).mx;
                if(left>=ele){
                    ans = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            update(1,0,n-1,ans,0);
        }
        return unplaced;

    }
};