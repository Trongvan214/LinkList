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
        while (curr != NULL && curr->return_structure().upc_code != searchUPC)
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
            //decrease node count
            len--;
        }
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
	while (curr != NULL && curr->return_structure().upc_code != searchUPC)
    {
        curr = curr->return_next();
    }
    //data found case
	if(curr != NULL)
    {
        return curr->return_structure();
    }
    //in case when item not found
    item cant_find;
    cant_find.description = "Error404";
    return cant_find; 
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
void Link_list::traverse_list()
{
    curr = head;
	while(curr != NULL)
    {
        //process curr data
        curr = curr->return_next();
    }
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

