#include <iostream>

#include "link_list.hpp"
#include "node.hpp"

Link_list::Link_list()
{
    tail = NULL;
    curr = NULL;
    prev = NULL;
    head = NULL;
    len = 0;
}
void Link_list::insert_node(item new_item)
{
    //make a new dynamic memory is past in data for new item
    Node *ptr = new Node(new_item);
    //setting next to NULL
    ptr->change_pointer(NULL);
    curr = head;
    //when empty list
	if(curr == NULL)
    {
		head = ptr;
    }
    //when non-empty list
	else	
    {
        //go to the last node
        while (curr->return_next() != NULL)
        {
            curr = curr->return_next();
        }
        //set last node next to new node
        curr->change_pointer(ptr);
    }
    //tail pointer point to last node
    tail = ptr;
    //increase count 
    len++;
}
void Link_list::delete_node(int searchUPC)
{
    prev = NULL;
	curr = head;
    //there are nodes
    if(curr != NULL)
    {
        //loop until UPCcode found or end of nodes
        while (curr != NULL && !curr->compare_UPC(searchUPC))
        {
            prev = curr;
            curr = curr->return_next();
        }
        //first node case
        if(prev == NULL)
        {
            //Deleting first node
            delete curr;
            head = curr->return_next();
        }
        else
        {
            delete curr;
            //connect prev node to curr next
            prev->change_pointer(curr->return_next());
        }
        //decrease node count
        len--;
    }
    else 
    {
        cout << "sometime is wrong no node" << endl;
    }
}
item Link_list::retrieve_node(int searchUPC)
{
    curr = head;
    //loop until last node or data found 
    while (curr != NULL && !curr->compare_UPC(searchUPC))
    {
        curr = curr->return_next();
    }
    //data found case
	if(curr != NULL)
    {
        return curr->return_structure();
    }
    else
    {
        //in case when item not found
        item error;
        error.description = "Error404";
        return error; 
    }
}

bool Link_list::is_empty()
{
    if(list_count() == 0 || head == NULL)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int Link_list::list_count()
{
    return len;
}
item Link_list::traverse_list()
{
    curr = head;
    int lowestUPC;
    //loop through all nodes
	while(curr != NULL)
    {
        prev = curr;
        //if 1 node
        if(list_count() == 1)
        {
            lowestUPC = curr->return_UPC_code();
        }
        //if 0 node
        else if(list_count() == 0)
        {
            cout << "This case is impossible" << endl;
        }
        //if more than 1
        else 
        {
            Node* next = curr->return_next();
            if(curr->return_UPC_code() > next->return_UPC_code())
            {
                lowestUPC = next->return_UPC_code();
            }
            else 
            {
                lowestUPC = curr->return_UPC_code();
            }
        }
        curr = curr->return_next();
    }
    //return node with the lowest UPC value;
    return retrieve_node(lowestUPC); 

}
/*void Link_list::destroy_list()
{
    curr = head;
	next = head;
	while (curr != NULL)
    {
        curr = curr->next;
		delete next;
		next = curr;
    }	
	head = NULL;
	count = 0;
}*/


