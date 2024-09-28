class MyCircularDeque {
public:
	int MaxSize;
	deque<int> v;
    MyCircularDeque(int k) {
    	MaxSize=k;
    }
    
    bool insertFront(int value) {
    	if(v.size()>=MaxSize){
    		return false;
    	}
    	v.push_front(value);
    	return true;
    	

        
    }
    
    bool insertLast(int value) {
    	if(v.size()>=MaxSize){
    		return false;
    	}
    	v.push_back(value);
    	return true;

    
        
    }
    
    bool deleteFront() {
    	if(v.size()!=0){
    		v.pop_front();

    		return true;
    	}
    	return false;


        
    }
    
    bool deleteLast() {
    	if(v.size()!=0){
    		v.pop_back();
    		return true;
    	}
        return false;
        
    }
    
    int getFront() {
    	if(v.size()==0){
    		return -1;
    	}
    	return v.front();
        
    }
    
    int getRear() {
        if(v.size()==0){
        	return -1;
        }
        return v.back();
    }
    
    bool isEmpty() {
    	return v.size()==0;
        
    }
    
    bool isFull() {
    	return v.size()==MaxSize;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */