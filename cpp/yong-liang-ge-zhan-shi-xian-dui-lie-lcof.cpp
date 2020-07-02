class CQueue
{
public:
    CQueue() { }
    
    void appendTail(int value)
    {
        tail_.push(value);
    }
    
    int deleteHead()
    {
        if (tail_.empty() && head_.empty())
            return -1;

        if (head_.empty())
        {
            while (!tail_.empty())
            {
                head_.push(tail_.top());
                tail_.pop();
            }
        }

        int x = head_.top();

        head_.pop();
        return x;
    }

private:
    stack<int> tail_;
    stack<int> head_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */