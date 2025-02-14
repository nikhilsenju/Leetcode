class ProductOfNumbers {
public:
    vector<int> preprod;
    vector<int> prezero;
    int cz;
    int prod;
    ProductOfNumbers() {
        prod = 1;
        cz = 0;
        prezero.push_back(cz);
        preprod.push_back(prod);
    }
    
    void add(int num) {
        if(num==0){
            prod=1;
            cz++;
        }
        else{
            prod = prod * num;
        }
        preprod.push_back(prod);
        prezero.push_back(cz);
    }
    
    int getProduct(int k) {
        int n = prezero.size();
        if(prezero[n-1]-prezero[n-k-1]>0){
            return 0;
        }
        return preprod[n-1]/preprod[n-k-1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */