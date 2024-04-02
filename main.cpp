#include <iostream>
#include "Queue.cpp"
#include <vector>
#include "Recursive.cpp"
#include "Double Linked List.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // Get the current time as a time_t value
    time_t time_value = time(0);

    // Cast time_value to unsigned int
    unsigned int time_value_unsigned = static_cast<unsigned int>(time_value);

    
    srand(time_value_unsigned);
    
    Queue<int> queue;
    
    cout << "Queue size: " << queue.size() << endl;
    
    int i = 0;
    
    while (i < 10) {
        
        queue.push(rand() % 30);
        
        i++;
    }
    
    cout << "Queue size: " << queue.size() << endl;
    cout << "Item at front is: " << queue.front() << endl;
    cout << "Queue size: " << queue.size() << endl;
    
    cout << "Item popped from front of list: " << queue.pop() << endl;
    
    cout << "New item at front to be moved to rear is: " << queue.front() << endl;
    cout << "Queue size: " << queue.size() << endl;
    
    queue.move_to_rear();
    cout << "New item at front is: " << queue.front() << endl;
    cout << "Queue size: " << queue.size() << endl;
    
    
    int j = 0;
    
    vector<int> vector;
    

    
    while (j < 10) {
        
        vector.push_back(rand() % 11);
        
        j++;
    }
    
    cout << "Vector size: " << vector.size() << endl;
    
    
    srand(time_value_unsigned);

    
    int num = rand() % 11;

    int find = vector[num];
    
    cout << "Find: " << find << endl;
    linear_search(vector, find, 0, -1);
    
    DoubleLinkedList<int> list;
    
    
    for (int i = 0; i < vector.size(); i++) {
        
        list.append(vector[i]);
    }
    
    cout << "List before sort: ";
    list.simplePrint();
    list.insertionSort();
    
    cout << "List after sort: ";
    list.simplePrint();

    
    
    return 0;
}
