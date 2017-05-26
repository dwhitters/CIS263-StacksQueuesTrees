#ifndef __H_FUNCTIONS_
#define __H_FUNCTIONS_

#include <string>
#include <stack>
#include <queue>

bool balanced(std::string expression){

    /**
        Create stack that is half the size of the parameter string.
        (Rounded up)
    */
    std::stack<char> stack;

    for( char x : expression )
    {
        if(stack.empty())
        {
            stack.push(x);
        }
        else if(stack.top() == x)
        {
            stack.pop();
        }
        else if(x == '\0')
        {}
        else
        {
            stack.push(x);
        }
    }

    return stack.empty();
}

template <typename T>
bool palindrome(std::stack<T> v){

    bool odd_palindrome = (1 == (v.size() % 2));
    size_t init_stack_size = v.size();
    std::stack<T> test;
    std::queue<T> queue;

    for(size_t i = 0; i < init_stack_size / 2; i++)
    {
        test.push(v.top());
        v.pop();
    }

    printf("V Top: %c", v.top());

    // If the palindrome has an odd size, remove the middle element.
    if(odd_palindrome)
    {
        v.pop();
    }

    printf("V Top: %c", v.top());

    while(!v.empty())
    {
        queue.push(v.top());
        v.pop();
    }

    for(size_t i = 0; i < test.size(); i++)
    {
        if(test.top() != queue.front())
        {
            break;
        }

        queue.pop();
        test.pop();
    }

    return test.empty();
}

#endif
