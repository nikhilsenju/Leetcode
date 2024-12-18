struct node{
    int mn;
    int mx;
    int sum;
    int gcd;
    node(){
        mn =  1e9;
        mx = -1e9;
        gcd = 0;
        sum = 0;
    }
};

node merge(node a , node b){
    node ans;
    ans.mx = max(a.mx , b.mx);
    ans.mn = min(a.mn , b.mn);
    ans.sum = a.sum + b.sum;
    ans.gcd = __gcd(a.gcd,b.gcd);
    return ans;
}
node t[4*200020];

void build(int id , int l , int r,vector<int>&v){
    if(l==r){
        t[id].mx = v[l];
        t[id].sum = v[l];
        t[id].gcd= v[l];
        t[id].mn = v[l];
        return; 
    }
    int mid = (l+r)/2;
    build(2*id , l , mid ,v);
    build(2*id+1, mid +1 , r, v);
    t[id]=merge(t[2*id],t[2*id+1]);
}

void up(int id ,int l ,int r, int pos ,int val){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        t[id].sum = val;
        t[id].mx = val;
        t[id].mn = val;
        t[id].gcd = val;
        return;
    }
    int mid = (l+r)/2;
    up(2*id,l,mid,pos,val);
    up(2*id+1,mid+1,r,pos,val);
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



class NumArray {
public:
	int n ;
    NumArray(vector<int>& nums) {
    	n = nums.size();
    	build(1,0,n-1,nums);
    }
    
    void update(int index, int val) {
    	up(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
    	node ans = query(1,0,n-1,left,right);
    	return ans.sum;
        
    }
};

