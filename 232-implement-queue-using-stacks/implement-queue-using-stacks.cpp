class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    int peekel=-1;


    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekel=x;
        }
        input.push(x);
    }
    
    int pop() {
        //amotisez O(1)

        if(output.empty()){
            //input -> output stack //o(n)
            while(!input.empty()){ 
                output.push(input.top());
                input.pop();

            }
        }
        int val = output.top();//o(1)
        output.pop();
        return val;

        
    }
    
    int peek() {
        if(output.empty()){
            return peekel;
        }
        else return output.top();
        
    }
    
    bool empty() {

        if(input.empty() && output.empty()){
            return true;
        }else return false; 
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */