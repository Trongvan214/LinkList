/*
Class Linked List
	Data:	head – Pointer to Node that will hold the head pointer of the list
	Len:	number of Nodes in the linked list

Default constructor
	Linked list – will be called when linked list is created
	set all pointers = null (head, prev, curr, tail)
	len = 0

Member function
	insert_node (data)
	input: data to be inserted into linked list (stored in Node)
	output: None
	returns: Nothing

	ptr = allocate a new Node (Put data in node)
	prev =  NULL
	curr = head
	while (curr != NULL and curr->data < data)
		prev = curr
		curr = curr link
	end while
	if prev = NULL
		// Adding before first node or to empty list
		ptr link = head
		head = ptr
	else	
		// Adding in middle or at end
		ptr link = prev link
		prev link = ptr
	len = len + 1

Member function
	delete_node (data)

	input: data to be deleted from list
	output: None
	returns: none


Member function
	retrieve_node (data)

	input: data to be found in list
	output: data
	returns: data 

	curr = head
	while (curr != NULL && curr data != data)
		curr = curr link
	if  curr != NULL
		return curr data
	else
		return 0

Member function
	is_empty
	
	input: None
	output/return:	True if empty, false if not

	if list count = 0		or if head == NULL
		return True
	else	
		return False

Member function 
	list_count

	input: None
	output/Return:	number of items in list

	return list len

Member function
	traverse_list
	input: None
	output: Whatever process list does in Node
	return: None

	curr = head
	while (curr != NULL)
		process curr data
		curr = curr link
	end while

Member function
	destroy_list – deletes all data in list

	input:	None
	output:	Entire list is deleted
	return:	None

	curr = head
	next = head
	while (curr != NULL)
		curr = curr link
		delete next
		next = curr	
	end while
	head = NULL
	count = 0


Create list – make an instance of class linked list
Insert – call class insert node function
Delete – call class delete node function
Retrieve – call class retrieve node function
Traverse – call class traverse list function
Is empty – call class is empty function
Destroy list – call class destroy list function
Number of nodes – call list count function
*/

#include <iostream>
#include <iomanip>

#include "link_list.hpp"
#include "node.hpp"

void print_data(Node* curr, ostream& stream);

//setting up the link list
Link_list::Link_list()
{
    tail = NULL;
    curr = NULL;
    prev = NULL;
    head = NULL;
    len = 0;
}
//put in a new node UPC order
void Link_list::insert_node(item new_item)
{
    if(duplicate_check(new_item))
    {
        cout << "It's a copy" << endl;
    }
    else
    {
        //allocating dynamic memory
        Node *ptr = new Node(new_item);
        prev = NULL;
        curr = head;
        while(curr != NULL && curr->return_UPC_code() < new_item.upc_code)
        {
            prev = curr;
            curr = curr->return_next();
        }
        if(prev == NULL)
        {
            //adding before first node or to empty list
            ptr->change_pointer(head);
            head = ptr;
        }
        else
        {
            //adding in middle or at end
            ptr->change_pointer(ptr->return_next());
            prev->change_pointer(ptr);
        }
        //increase total node
        len++;
        
        }
}
//delete a node
void Link_list::delete_node(int searchUPC)
{
    prev = NULL;
    curr = head;
    while(curr != NULL && !curr->compare_UPC(searchUPC))
    {
            prev = curr;
            curr = curr->return_next();
    }
    if(curr != NULL)
    {
        //first node case
        if(prev == NULL)
        {
            //Deleting first node
            head = curr->return_next();
        }
        else
        {
            //connect prev node to curr next
            prev->change_pointer(curr->return_next());
        }
        delete curr;
        //decrease node count
        len--;
    }
    //set tail point to another
}
//search through all the nodes and return node data with the match UPC code
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
//check if there are nodes or not
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

//return how nodes are in the link list
int Link_list::list_count()
{
    return len;
}

//return ptr to the array of all nodes UPC codes
void Link_list::traverse_list()
{
    curr = head;
	while(curr != NULL)
    {
        print_data(curr,cout);
        curr = curr->return_next();
    }
}

//print out all data given address pointer
void print_data(Node* curr, ostream& stream)
{
    item data = curr->return_structure();
    stream << setprecision(2) << fixed;
    stream << setw(3) << left << data.upc_code << "\t";
    stream << setw(3) << left << data.description << "\t";
    stream << setw(3) << left << data.quantity << "\t";
    stream << "$" << setw(3) << left << data.cost << "\t";
    stream << "Aisle " << setw(3) << left << data.aisle << "\t";
    stream << "Total Cost " << setw(3) << left << curr->process_data() << endl;
}

//destroy everthing
void Link_list::destroy_list()
{
    curr = head;
    prev = head;
    while(curr != NULL)
    {
        curr = curr->return_next();
        delete prev;
        prev = curr;
    }
    head = NULL;
    len = 0;
}

void Link_list::put_in_file()
{
    ofstream write("grocerylist.txt");
    curr = head;
    while(curr != NULL)
    {
        print_data(curr,write);
        curr = curr->return_next();
    }
    write.close();
}

bool Link_list::duplicate_check(item data)
{
    curr = head;
    while(curr != NULL)
    {
        if(data.upc_code == curr->return_UPC_code())
        {
            return true;
        }
        else 
        {
            curr = curr->return_next();
        }
    }
    return false;
}


