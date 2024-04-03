#ifndef Double_Linked_List_hpp
#define Double_Linked_List_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


template <typename type>
class DoubleLinkedList {
private:
    
    // Stucture of the node
    struct List_Node {
        
        //Data to be stored in the node
        int data;
        
        //Pointer for the next node
        List_Node* next;
        
        //Pointer for previous node
        List_Node* prev;
        
        //Constructor of node
        List_Node(const int& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    //Pointer to first node
    List_Node* head;
    
    //Pointer to last node
    List_Node* tail;
    
    //Number of items in list
    size_t num_items;
    
public:
    
    //Constructor
    DoubleLinkedList();
    
    //Deconstructor
    ~DoubleLinkedList();
    
    //Function to insert node at end of list
    void append(int value);
    
    //Function to print list
    void printList();
    
    //Function for simple print
    void simplePrint();
    
    //Function to return size
    size_t size();
    
    void insertionSort();
};

#endif /* Double_Linked_List_hpp */
