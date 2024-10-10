#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10

class Stack
{
protected:
    int top;
    int arr[MAXSIZE];

public:
    Stack()
    {
        top = -1;
    }
    void push(int data);
    void pop();
    bool isEmpty();
    int size();
    int Top();
};

void Stack::push(int data)
{
    if (top == MAXSIZE - 1)
    {
        throw out_of_range("Stack overflow: Cannot push into a full stack");
    }
    top++;
    arr[top] = data;
}

void Stack::pop()
{
    if (top == -1)
    {
        throw out_of_range("Stack underflow: Cannot pop from an empty stack");
        return;
    }
    arr[top] = -1;
    top--;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack::size()
{
    return (top + 1);
}

int Stack::Top()
{
    if (top == -1)
    {
        throw out_of_range("Stack underflow: Cannot pop from an empty stack");
        return -1;
    }
    return arr[top];
}

// The problem with the above implementation is the fixed size of the stack.
// This means that once the stack is full, no more elements can be added without resizing.
// We can solve this problem in two ways:

// 1. Incremental resizing:
//    - When the stack gets full, increase its size by 1.
//    - This approach has a time complexity of O(n^2) for pushing n elements.
//      This is because in the worst case, we may need to copy the entire stack each time we add an element,
//      resulting in a series of operations that take 1 + 2 + 3 + ... + n = O(n^2) time.

// 2. Doubling the size:
//    - When the stack gets full, double the size of the array.
//    - This approach has a time complexity of O(n) for pushing n elements.
//      The time complexity is more efficient because the number of operations involved
//      when doubling the size follows a geometric progression: 1 + 2 + 4 + ... + n/4 + n/2 + n.
//      The sum of this series is O(n), making it a more optimal solution for dynamic resizing.

struct DynArrayStack
{
    int capacity; // size
    int top;      // top of the stack
    int *array;   // pointer to top of the stack
};
class DynStack
{
public:
    DynArrayStack *stack = new DynArrayStack();
    DynStack()
    {
        stack->top = -1;
        stack->capacity = 1;
        stack->array = new int[stack->capacity];
    }
    void push(int data);
    void pop();
    bool isEmpty();
    int size();
    int Top();
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(2);
    stack.push(-2);
    cout << "stack size = " << stack.size() << '\n';
    cout << "is stack empty : " << stack.isEmpty() << '\n';
    cout << stack.Top() << '\n';
    stack.pop();
    cout << stack.Top() << '\n';
    return 0;
}
