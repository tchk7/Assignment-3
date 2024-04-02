#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>


//Node for linked list
template <typename type>
struct Node {
    
    //Data in node
    type data;
    
    //Next node pointer
    Node* next;
    
    //Node constructor
    Node(type value) : data(value), next(nullptr) {}
};

//Queue class
template <typename type>
class Queue {
    
public:
    //Constructor
    Queue();
    
    //Deconstructor
    ~Queue();
    
    //Add item to queue
    void push(type item);
    
    //Remove item from queue
    type pop();
    
    //Get item at front of queue
    type front();
    
    //Get size of queue
    const size_t size();
    
    //Check if queue is empty
    const bool empty();
    
    //Move item to rear of queue
    void move_to_rear();
    
private:
    
    //Node at front of queue
    Node<type>* head;
    
    //Node at end of queue
    Node<type>* tail;
    
    //Number of items in queue
    int count;
};

#endif /* Queue_hpp */
