#ifndef __NODE__
#define __NODE__
#include <string>

using namespace std;

struct item 
{
    int upc_code, quantity, aisle;
    string description;
    float cost;
};

class Node 
{
    item data;
    Node* next;
    public: 
        Node(void);
        Node(item new_data);
        void change_pointer(Node *next_ptr);
        Node* return_next();
        int return_UPC_code();
        item return_structure();
        bool compare_UPC(int given_UPC);
        float process_data(); 
};

#endif
