#ifndef __LINKLIST__
#define __LINKLIST__

#include <string>
#include <fstream>

#include "node.hpp"

class Link_list {
    //head pointer, and tail pointer + extra useful pointer 
    Node *head, *prev, *curr, *tail;
    int len; 
    public: 
        Link_list(void);
        void insert_node(item data);
        void delete_node(int searchUPC);
        void traverse_list();
        item retrieve_node(int UPCsearch);
        bool is_empty();
        int list_count();
        void destroy_list();
        void put_in_file();
        bool duplicate_check(item data);
};
#endif
