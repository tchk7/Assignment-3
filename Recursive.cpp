#include <vector>
#include <iostream>

using namespace std;

template <typename type>
int linear_search(vector<type>& items, type& target, int pos_first, int last_occur) {
    
    if (pos_first == items.size()) {
        
        cout << target << " last occured at position: " << last_occur << endl;
        
        return last_occur;
    }
    
    if (target == items[pos_first]) {
        
        last_occur = pos_first;
        
        cout << target << " appeared at position: " << last_occur << endl;
    }
    return linear_search(items, target, pos_first + 1, last_occur);
}
