//Author: Trong Van
//Student ID: x454v285
//Programming Number: 4

//Description: making a link list for  grocery list

/*
Class Linked List
	Data:	head – Pointer to Node that will hold the head pointer of the list
	Len:	number of Nodes in the linked list

Default constructor
	Linked list – will be called when linked list is created
	head = NULL
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
	returns: True if deleted, false if not in list

	prev = NULL
	curr = head
	while (curr != NULL and curr data != data)
		prev = curr
		curr = curr link
	end while
	
    if curr != NULL
        if  prev = NULL
            // Deleting first node
            head = curr link
        else
            // Deleting other nodes
            Prev link = curr link
        free Node
        len = len - 1
        return True
    end if
    return False

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
#include <string>
#include <fstream>
#include <iomanip>

#include "link_list.hpp"
#include "node.hpp"

void printMenu();
void program();
void ask_info(item *new_item);
//have default choice value
void search_list(Link_list *list,bool delete_node = false);
void print_item(item data, string end_how = "\n");
void sort_and_print(Link_list list);
//void putInFile();

using namespace std;

int main() 
{
    //
    ifstream read("grocerylist.txt");
    //if grocerylist.txt exists read it
    if(read.good())
    {
        
    }
    else
    {
        printMenu();
        Link_list grocery_list;
        int user_input;
        do
        {
            cout << "Enter Menu Choices (1-5)" << endl;
            cin >> user_input;
            if(user_input == 1)
            {
                item new_item;
                //ask item details
                ask_info(&new_item);
                //add a new item (node)
                grocery_list.insert_node(new_item);
            }
            else if(user_input == 2)
            {
                //search for UPC code
                //past in true for delete node case 
                search_list(&grocery_list,true);
            }
            else if(user_input == 3)
            {
                search_list(&grocery_list);
            }
            else if(user_input == 4)
            {
                //print out all items
                sort_and_print(grocery_list);
            }
        } while(user_input != 5);
        //putInFile();
    } 
}
//this function that print out infomation how to use program
void printMenu()
{
    cout << "1) Add a grocery item" << endl;
    cout << "2) Delete an item" << endl;
    cout << "3) Retrieve an item" << endl;
    cout << "4) Print out all of the items" << endl;
    cout << "5) exit the program" << endl;
}

//this function write ask the users for data about the item
void ask_info(item *new_item)
{
    cout << "Enter UPC code: ";
    cin >> new_item->upc_code;
    cin.ignore();
    cout << "Enter description: ";
    getline(cin,new_item->description);
    cout << "Enter quantity: ";
    cin >> new_item->quantity;
    cout << "Enter cost: ";
    cin >> new_item->cost;
    cout << "Enter aisle ";
    cin >> new_item->aisle;
}

//ask the users and search for that item (node) 
void search_list(Link_list *list,bool delete_node)
{
    int search_UPC;
    cout << "Enter item:(UPC) ";
    cin >>  search_UPC;
    item data = list->retrieve_node(search_UPC);
    print_item(data);
    
    //this part only apply when deleting item (node)
    //ask for comfirmation
    if(delete_node && data.description.compare("Error404") != 0)
    {
        char comfirm;
        cout << "Confirm delete (y/n)? "; 
        cin >> comfirm;
        if(comfirm =='y')
        {
            list->delete_node(search_UPC);
        } 
        else 
        {
            cout << "Request Terminated" << endl;
        }
    }
}

//given item this function will print out all it's details
void print_item(item data, string end_how)
{
    //if retrieve_item return a error item 
    if(data.description.compare("Error404") == 0)
    {
        cout << "Invalid Code or Item don't exist " << endl;
    }
    else 
    {
        cout << setw(10) << left << data.upc_code << "\t";
        cout << setw(10) << left << data.description << "\t";
        cout << setw(10) << left << data.quantity << "\t";
        cout << "$" << setw(10) << left << data.cost << "\t";
        cout << "Aisle " << setw(10) << left << data.aisle << end_how;
    }
}
//sort the items by UPC codes and print all items out 
void sort_and_print(Link_list list)
{
    int length = list.list_count();
    //array that will hold all UPC codes values
    int hold_UPCcode[length];
    //pointer that to the return pointer from traverse function
    int* arr_ptr = list.traverse_list(hold_UPCcode,length);
    //no items case
    if(length == 0)
    {
        cout << "There are no item added" << endl;
    }
    //1 or more case
    else 
    {
        int temp;
        bool swapped;
        //simple sort l to h
        do
        {
            swapped = false;
            for(int i = 0; i < length-1; i++)
            {
                if(arr_ptr[i] > arr_ptr[i+1])
                {
                    temp = arr_ptr[i];
                    arr_ptr[i] = arr_ptr[i+1];
                    arr_ptr[i+1] = temp;
                    swapped = true;
                }
            }
        } while(swapped); 
        //print out all items 
        for(int i = 0; i < length; i++)
        {
            item data = list.retrieve_node(arr_ptr[i]);
            Node totalCost(data);
            //print with tab at the end for total cost
            print_item(data, "\t");
            cout << "Total Cost $" << totalCost.process_data() << endl;
        }
    }
}








