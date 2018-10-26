#pragma once
#include "tVector.h"

template <typename T>
class tQueue
{
    tVector<T> vec;                       // contains the data for a queue

public:
    tQueue();                             // default initializes the queue
    tQueue(size_t count, const T& value); // constructs a queue with the given number of elements 
                                          // each element is initialized by copying the given value

    void push(const T& value);            // adds an element to the top of the Queue
    void pop();                           // drops the top-most element of the Queue

    T& front();                           // returns the front-most element
    T& back();                            // returns the back-most element

    size_t size() const;                  // returns current number of elements
};