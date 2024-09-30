class CustomStack {
public:
    vector<int> arr;      // Stack storage
    vector<int> inc;      // Lazy increment storage
    int MaxSize;
    int r;                // Top of the stack pointer

    CustomStack(int maxSize) {
        MaxSize = maxSize;
        arr.resize(MaxSize, 0);    // Initialize with maxSize capacity
        inc.resize(MaxSize, 0);    // Initialize lazy increment array
        r = 0;                     // Stack starts empty
    }
    
    void push(int x) {
        if (r < MaxSize) {          // Ensure we don't exceed the max size
            arr[r] = x;
            r++;
        }
    }
    
    int pop() {
        if (r > 0) {
            r--;
            int result = arr[r] + inc[r];  // Apply any lazy increments
            if (r > 0) {
                inc[r - 1] += inc[r];      // Pass down the increment to the next element
            }
            inc[r] = 0;                    // Reset increment for popped element
            return result;
        }
        return -1; // Stack is empty
    }
    
    void increment(int k, int val) {
        int limit = min(k, r);        // Only apply increment to available elements
        if (limit > 0) {
            inc[limit - 1] += val;    // Apply increment lazily to the last element in range
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
