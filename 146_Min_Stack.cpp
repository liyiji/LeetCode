/*
 * Min Stack
 * Total Accepted: 4819 Total Submissions: 31323
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *     push(x) -- Push element x onto stack.
 *     pop() -- Removes the element on top of the stack.
 *     top() -- Get the top element.
 *     getMin() -- Retrieve the minimum element in the stack.
 *
 */
// Tips: Do NOT use std::vector. This will cause Memory Limit Exceeded. Use std::stack instead.
class MinStack
{
public:
    stack<int> datas, mins;

    void push(int x)
    {
        datas.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }

    void pop()
    {
        if (mins.top() >= datas.top())
            mins.pop();
        datas.pop();
    }

    int top()
    {
        return datas.top();
    }

    int getMin()
    {
        return mins.top();
    }
};
