/************************************************************************
 * Practice using stacks and queues by creating functions that
 * determine whether a string is balanced based on its beginning and
 * ending bracket symbols, and whether a vector of generic elements
 * is a palindrome.
 *
 * @author David Whitters
 * @date 5/30/17
 ************************************************************************/

#ifndef __H_FUNCTIONS_
#define __H_FUNCTIONS_

#include <string>
#include <vector>
#include <stack>
#include <queue>

/**
    Determines whether a string is balanced, as in, whether every
    symbol used as a bracket has a corresponding symbol matching itself
    to close a sub-expression. The symbols used as brackets are:
    '@', '^', and '%'.

    @param expression The string to be analyzed to ascertain whether it
                      is balanced or not.

    @return bool True when every symbol in the string has a
                 corresponding symbol, False otherwise.
*/
bool balanced(std::string expression){

    std::stack<char> stack;

    /**
        Range-based for loop that iterates over every character in the
        string.
    */
    for( char x : expression )
    {
        // If the current character matches any that are desired...
        if((x == '%') || (x == '@') || (x == '^'))
        {
            if(stack.empty())
            {
                stack.push(x);
            }
            else if(stack.top() == x)
            {
                stack.pop();
            }
            else
            {
                stack.push(x);
            }
        }
    }

    return stack.empty();
}

/**
    This function determines whether a vector containing generic
    elements is a palindrome. In this case, elements are considered
    equal if the result of an "==" comparison between elements is true.

    @param v A vector containing an undetermined amount of generic
             elements.

    @return bool True when the elements in the stack form a palindrome,
                 False otherwise.
*/
template <typename T>
bool palindrome(std::vector<T> v){

    // Determine whether the vector has an odd size.
    bool odd_palindrome = (1 == (v.size() % 2));
    size_t init_vector_size = v.size();
    std::stack<T> test;
    std::queue<T> queue;

    // Push the first half of the passed-in vector into a stack.
    for(size_t i = 0; i < init_vector_size / 2; i++)
    {
        test.push(v.back());
        v.pop_back();
    }

    // If the palindrome has an odd size, remove the middle element.
    if(odd_palindrome)
    {
        v.pop_back();
    }

    // Push the rest of the passed-in stack into a queue.
    while(!v.empty())
    {
        queue.push(v.back());
        v.pop_back();
    }

    /**
        If the front of the queue and the top of the stack don't match
        at any point, the passed in stack is not a palindrome.
    */
    for(size_t i = 0; i < init_vector_size / 2; ++i)
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
