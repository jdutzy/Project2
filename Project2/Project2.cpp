#include<iomanip>
#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream>
#include"toDoList.h"
#include "toDoItem.h"

using namespace std;
#define MAX_SIZE 100 

int main()
{
	struct MyToDo* tempTodo, getToDoItem, getToDoData;
	ToDoItem td;
	string Type;
	string Status;
	string todoDesc1;
	string todoType1;
	string todoStatus1;
	string todoTitle1;
	string date;
	int todoPriority1;
	int nn;
	int priority;
	int i;
	int id = 0;
	int editid;
	int todel;
	int ss;

	cout << "You can perform the following operations:\n1. Add To Do Item\n2. Edit To Do Item\n3. Delete To Do Item\n4. Print Current List\n5. Sort List by Priority\n6. Write list to text file\n7. Read list to text file\n8. Exit the program\n";

	while (1)
	{
		cout << "\nEnter your choice: ";
		cin >> i;

		switch (i)
		{
		case 1:
			cout << "Enter the number of tasks you want to add: ";
			cin >> nn;
			for (int a = 0; a < nn; a++) {


				cout << "\nEnter the title, description, type, priority, status, and due date: " << endl;

				cout << "Enter to-do Title: ";
				cin >> todoTitle1;

				cout << "Enter to-do Description: ";
				cin >> todoDesc1;

				cout << "Enter to-do Type: ";
				cin >> todoType1;

				cout << "Enter to-do Priority: ";
				cin >> todoPriority1;

				cout << "Enter to-do Status: ";
				cin >> todoStatus1;

				cout << "Enter to-do Due Date(mm/dd) form: ";
				cin >> date;

				id++;

				td.addNode(id, todoTitle1, todoDesc1, todoType1, todoPriority1, todoStatus1, date);

				cout << "Task was added to the list with ID: " << id;

				cout << endl;
			}

			break;
		case 2:

			cout << "Enter task ID to edit: ";
			cin >> editid;

			cout << "Enter to-do Title: ";
			cin >> todoTitle1;

			cout << "Enter to-do Description: ";
			cin >> todoDesc1;

			cout << "Enter to-do Type: ";
			cin >> todoType1;

			cout << "Enter to-do Priority: ";
			cin >> todoPriority1;

			cout << "Enter to-do Status: ";
			cin >> todoStatus1;

			cout << "Enter to-do Due Date(mm/dd) form: ";
			cin >> date;

			td.EditList(editid, todoTitle1, todoDesc1, todoType1, todoPriority1, todoStatus1, date);

			break;

		case 3:
			cout << "Enter the ID of the task to delete: ";
			cin >> todel;
			td.DeleteItem(todel);
			cout << "Task was deleted.";

			break;

		case 4:
			cout << "Current list: \n";
			td.PrintToDo();
			break;

		case 5:
			tempTodo = new struct MyToDo[nn];
			cout << "Enter priority to sort list by: \n";
			cin >> priority;
			if (td.getByPriority(tempTodo, priority))

			{
				ss = sizeof(*tempTodo) / sizeof(tempTodo[0]);

				cout << "To-do with priority " << priority << ": " << endl;

				for (int kk = 0; kk < ss; kk++)

				{
					cout << "Title: " << tempTodo[kk].todoTitle << endl;
					cout << "Description: " << tempTodo[kk].todoDesc << endl;
					cout << "Type: " << tempTodo[kk].todoType << endl;
					cout << "Priority: " << tempTodo[kk].todoPriority << endl;
					cout << "Status: " << tempTodo[kk].todoStatus << endl;
					cout << "Due Date: " << tempTodo[kk].todoDate << endl << endl;
				}
			}

			break;

		case 6:
			cout << "List will be written to 'list.txt' \n";
			td.WriteList();
			break;

		case 7:
			cout << "List from 'list.txt'\n";
			td.ReadList();
			break;

		case 8:
			exit(0);
			break;

		default:
			cout << "Please enter one of the above choices.\n";
		}

	}
	return 0;
};
