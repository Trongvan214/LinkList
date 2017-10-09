//Author: Trong Van
//Student ID: x454v285
//Programming Number: 4

//Description: making a link list for  grocery list

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
void print_item(item data);
void putInFile(Link_list *list);

using namespace std;

int main() 
{
    //
    ifstream read("grocerylist.txt");
    //if grocerylist.txt exists read it
    if(read.good())
    {
        string line;
        while(getline(read, line))
        {
            cout << line << endl;
        }
        read.close() ;
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
        grocery_list.put_in_file();
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
        cout << setw(10) << left << data.upc_code << "\t";
        cout << setw(10) << left << data.description << "\t";
        cout << setw(10) << left << data.quantity << "\t";
        cout << "$" << setw(10) << left << data.cost << "\t";
        cout << "Aisle " << setw(10) << left << data.aisle << endl;
    }
}










