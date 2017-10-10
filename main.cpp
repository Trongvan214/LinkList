//Author: Trong Van
//Student ID: x454v285
//Programming Number: 4

//Description: making a link list for  grocery list

/*
 * Function Name: printMenu         =>
 *              input: none
 *              output: print guide menu
 *              return: void
 *  
 * Function Name: ask_info          =>
 *              input: item (data)
 *              output: ask users for all info about item
 *              return: void
 * 
 * Function Name: search_list
 *              input: linklist
 *              output: print out a retrieve item
 *              return: void
 * 
 * Function Name: print_item
 *              input: item (data)
 *              output: print out the details about that item
 *              return: void
 * 
 * -------------------Program start------------------------
*              if grocerylist.txt exist
*                  put everything from the file into the link list
*              else
*                 ask user for choice
*                 do while user input != 5
 *                      if user == 1
 *                          ask_info
 *                      else if user == 2
 *                          search_list with delete option
 *                      else if user == 3
 *                          search_list
 *                      else if user == 4 
 *                          print out all node
 *                 print everything to file
 *                      
 *                      
 * 
 * 
 * */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "linked_list.hpp"
#include "node.hpp"

void printMenu();
void ask_info(item *new_item);
//have default choice value
void search_list(Link_list *list,bool delete_node = false);
void print_item(item data);

using namespace std;

int main() 
{
    //make a new link list
    Link_list grocery_list;
    ifstream read("grocerylist.txt");
    //if grocerylist.txt exists read it
    if(read.good())
    {
        //print out from file
        item new_data;
        int code, quantity, aisle;
        string description;
        float cost;
        //adding everything from the file into the list again
        while(!read.fail())
        {
            read>>code>>quantity>>cost>>aisle;
            getline(read,description);
            new_data.upc_code = code;
            new_data.quantity = quantity;
            new_data.cost = cost;
            new_data.aisle = aisle;
            new_data.description = description;
            grocery_list.insert_node(new_data);
        }
        read.close();
    }
    printMenu();
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
            //search and print item
            search_list(&grocery_list);
        }
        else if(user_input == 4)
        {
            //print out all items
            if(grocery_list.list_count()==0)
            {
                cout<<"Empty list" << endl;
            }
            else
            {
               grocery_list.traverse_list(); 
            }
        }
    } while(user_input != 5);
    //put the list in a file
    grocery_list.put_in_file();
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
void print_item(item data)
{
    //if retrieve_item return a error item 
    if(data.description.compare("Error404") == 0)
    {
        cout << "Invalid Code or Item don't exist " << endl;
    }
    else 
    {
        cout << setprecision(2) << fixed;
        cout << setw(5) << left << data.upc_code << "\t";
        cout << setw(5) << left << data.description << "\t";
        cout << setw(5) << left << data.quantity << "\t";
        cout << "$" << setw(5) << left << data.cost << "\t";
        cout << "Aisle " << setw(5) << left << data.aisle << endl;
    }
}










