class ProductOfNumbers {
public:
    vector<int> preprod;
    vector<int> prezero;
    int cz;
    int prod;

    ProductOfNumbers() {
        prod = 1;
        cz = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            prod = 1;
            cz++;
        } else {
            prod *= num;
        }
        preprod.push_back(prod);
        prezero.push_back(cz);
    }
    
    int getProduct(int k) {
        int n = prezero.size();
        if (k > n) return 0;  // Fix: Prevent out-of-bounds access
        if (prezero[n - 1] - (n - k - 1 >= 0 ? prezero[n - k - 1] : 0) > 0) {
            return 0;
        }
        return (n - k - 1 >= 0) ? preprod[n - 1] / preprod[n - k - 1] : preprod[n - 1];
    }
};
