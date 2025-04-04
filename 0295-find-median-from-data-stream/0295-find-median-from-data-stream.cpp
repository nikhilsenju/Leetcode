
class MedianFinder {
public:
    priority_queue<int> lower;
    priority_queue<int,vector<int>,greater<int>> upper;
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        lower.push(num);
        if(lower.size()-upper.size()>1){
            upper.push(lower.top());
            lower.pop();

        }
        else if(lower.size()-upper.size()==1){
            if(!upper.empty()){
                int up = upper.top();
                int low = lower.top();
                if(low>up){
                    upper.pop();
                    upper.push(low);
                    lower.pop();
                    lower.push(up);
                }
            }
        }
        
    }
    
    double findMedian() {
        if(lower.size()==upper.size()){
            return double(lower.top()+upper.top())/2.000;
        }
  
            return (double)lower.top();
     
        
    }
};