#include "Queue.hpp"

#include <iostream>

using namespace std;

//Constructor
template <typename type>
Queue<type>::Queue() : head(nullptr), tail(nullptr), count(0) {}

//Deconstructor
template <typename type>
Queue<type>::~Queue() {
    
    //Check if queue is empty
    while (!empty()) {
        
        //Remove item from queue
        pop();
    }
}

//Add item to queue
template <typename type>
void Queue<type>::push(type item) {
    
    //Create new node
    Node<type>* newNode = new Node<type> (item);
    
    //Check if queue is empty
    if (empty()) {
        
        //New node is head and tail
        head = tail = newNode;
    }
    else {
        
        //Tail points to new node
        tail->next = newNode;
        
        //New node now tail
        tail = newNode;
    }
    
    //Update count
    count++;
}

template <typename type>
type Queue<type>::pop() {
    
    //Check if queue is empty
    if (empty()) {
        
        //Throw error
        throw out_of_range("Queue is empty");
    }
    
    //Create temp node
    Node<type>* temp = head;
    
    //Store data of node to be removed
    type data = head->data;
    
    //New head of queue
    head = head->next;
    
    //Delete temp node
    delete temp;
    
    //Update count
    count--;
    
    //Check if removed node was only node
    if (empty()) {
        
        //Tail is null
        tail = nullptr;
    }
    
    //Return data of removed node
    return data;
}

template <typename type>
type Queue<type>::front() {
    
    //Check if queue is empty
    if (empty()) {
        
        //Throw error
        throw out_of_range("Queue is empty");
    }
    
    //Return head data
    return head->data;
}

template <typename type>
const size_t Queue<type>::size() {
    
    //Return count
    return count;
}

template <typename type>
const bool Queue<type>::empty() {
    
    //Return count
    return count == 0;
}

template <typename type>
void Queue<type>::move_to_rear(){
    
    //Check if queue is empty
    if (empty()) {
        
        //Throw error
        throw out_of_range("Queue is empty");
    }
    //Check if queue has more than one node
    else if (size() > 1) {
        
        //Push the popped node
        push(pop());
    }

}
