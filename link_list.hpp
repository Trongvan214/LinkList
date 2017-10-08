#ifndef __LINKLIST__
#define __LINKLIST__
#include <string>
#include "node.hpp"

class Link_list {
    //head pointer, and tail pointer + extra useful pointer 
    Node *head, *prev, *curr, *tail;
    int len; 
    public: 
        Link_list(void);
        void insert_node(item data);
        void delete_node(int searchUPC);
        int* traverse_list(int arr[], int SIZE);
        item retrieve_node(int UPCsearch);
        bool is_empty();
        int list_count();
        //void destroy_list();
};

#endif
