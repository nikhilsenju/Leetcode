class Solution {
public:
    vector<bool> sieve;
    
    Solution() : sieve(1000001, true) { // Initialize sieve in the constructor
        createsieve();
    }
    
    void createsieve() {
        int Z = 1000000; // Use 1000000 instead of 1000001 to prevent unnecessary checks
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= Z; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= Z; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
    
    vector<int> closestPrimes(int left, int right) {
        int a = -1, b = -1;
        int prev = -1; // Track the previous prime

        for (int i = left; i <= right; i++) {
            if (sieve[i]) { // Check for primes
                if (prev != -1) {
                    if (a == -1 || (i - prev < b - a)) {
                        a = prev;
                        b = i;
                    }
                }
                prev = i;
            }
        }
        return {a, b};
    }
};
