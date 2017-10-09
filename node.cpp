#include <iostream>
#include "node.hpp"

using namespace std;

Node::Node()
{
    data.upc_code = 0;
    data.quantity= 0;
    data.aisle = 0;
    data.cost = 0;
    data.description = "";
    next = NULL;
}

Node::Node(item new_data)
{
    data = new_data;
    next = NULL;
}
void Node::change_pointer(Node* next_ptr)
{
    //change pointer
    next = next_ptr;
}

Node* Node::return_next()
{
    //return the pointer
    return next;
}

int Node::return_UPC_code()
{
    //return the UPC code
    return data.upc_code;
}

item Node::return_structure()
{
    //return the structure (data)
    return data;
}

bool Node::compare_UPC(int given_UPC)
{
   return data.upc_code == given_UPC;
}

float Node::process_data()
{
    return data.cost*data.quantity;
}
