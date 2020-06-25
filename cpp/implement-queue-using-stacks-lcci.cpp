class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        tail_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = peek();

        head_.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek()
    {
        if (head_.empty())
        {
            while (!tail_.empty())
            {
                head_.push(tail_.top());
                tail_.pop();
            }
        }

        return head_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return tail_.empty() && head_.empty();
    }

private:
    stack<int> tail_;
    stack<int> head_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
