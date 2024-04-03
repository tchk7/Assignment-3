#include "Double Linked List.hpp"


//Constructor
template <typename type>
DoubleLinkedList<type>::DoubleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

//Deconstructor
template <typename type>
DoubleLinkedList<type>::~DoubleLinkedList() {
    
    //Current node
    List_Node* curr = head;
    
    //Iterate list
    while (curr != nullptr) {
        
        //Tracker node
        List_Node* next = curr->next;
        
        //Delete current
        delete curr;
        
        //Current equals next
        curr = next;
    }
}

//Function to insert node at end of list
template <typename type>
void DoubleLinkedList<type>::append(int value) {
   
    //Create new node
    List_Node* new_node = new List_Node (value);

    //Check if list is empty
    if (head == nullptr && tail == nullptr) {
        
        //New node is tail and head
        head = tail = new_node;
    }
    else {
        
        
        //Set tail to point to new node
        tail->next = new_node;
        
        //New node prev points to tail
        new_node->prev = tail;
        
        //Set new node as tail
        tail = new_node;
        
    }
    
    //Update num_items
    num_items++;
}

//Function to print list
template <typename type>
void DoubleLinkedList<type>::printList() {
    
    //Set current node
    List_Node* curr = head;
    
    int i = 0;
    
    //Iterate through list
    while (curr != nullptr) {
        
        if (curr == head) {
            
            //Print Current, Previous, and Next node
            cout << "Position: " << i << " | " << "Current: " << curr->data << ", Previous: None, Next: " << curr->next->data << endl;
        }
        else if (curr == tail) {
            
            //Print Current, Previous, and Next node
            cout << "Position: " << i << " | " << "Current: " << curr->data << ", Previous: " << curr->prev->data << ", Next: None" << endl;

        }
        else {
            
            //Print Current, Previous, and Next node
            cout << "Position: " << i << " | " << "Current: " << curr->data << ", Previous: " << curr->prev->data << ", Next: " << curr->next->data << endl;
        }
        
        //Go to next node
        curr = curr->next;
        
        //Update i
        i++;
    }
    
    //Print new line
    cout << endl;
    return;
}

//Function for simple print
template <typename type>
void DoubleLinkedList<type>::simplePrint() {
    
    //Set current node
    List_Node* curr = head;
    
    //Iterate through list
    while (curr != nullptr) {
        
        cout << curr->data;
        
        if (curr != tail && curr->next != nullptr) {
            
            cout << ", ";
        }
        curr = curr->next;
    }
    
    cout << endl;
}

//Function to return size
template <typename type>
size_t DoubleLinkedList<type>::size() {
    
    return num_items;
}

template <typename type>
void DoubleLinkedList<type>::insertionSort() {
    
    //Create current node set to second node
    List_Node* curr = head->next;
    
    //Check if list is empty or has one element
    if (head == nullptr || head->next == nullptr) {
        
        return;
    }
    
//    int i = 0;
    //Iterate through next nodes
    while (curr != nullptr) {
        

        //Store current node data
        int key = curr->data;
        
        //Create node tracker for current previous
        List_Node* left = curr->prev;

        while(left != nullptr && left->data > key) {
            

            //Set current node data equal to previous node data
            left->next->data = left->data;
            
            //Travel one node left
            left = left->prev;

        }
        
        //Left is not head
        if (left != nullptr) {
            
            //Left next data equals key
            left->next->data = key;
        }
        //Left is Head
        else {
            //Set head equal to key
            head->data = key;
        }
        
        curr = curr->next;

    }
}
