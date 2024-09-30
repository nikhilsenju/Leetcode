class CustomStack {
public:
    int MaxSize;
    vector<int> arr;
    int r = 1; // only r is necessary as a pointer for the top of the stack
    CustomStack(int maxSize) {
        MaxSize = maxSize;
        arr.resize(MaxSize + 1, 0);   
    }
    
    void push(int x) {
        if (r <= MaxSize) {  // Ensure we don't exceed the max size
            arr[r] = x;
            r++;
        }
    }
    
    int pop() {
        if (r > 1) { // Ensure there are elements to pop
            r--;
            int ele = arr[r];
            arr[r] = 0;
            return ele;
        }
        return -1; // Stack is empty
    }
    
    void increment(int k, int val) {
        for (int i = 1; i <= min(k, r - 1); i++) { // r - 1 is the number of valid elements
            arr[i] += val;
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
