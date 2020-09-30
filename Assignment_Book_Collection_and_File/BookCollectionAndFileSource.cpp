/********************
*Assignment:  Book Collection And File
*For this project you must create a C++ project that will:
*
*-Create a vector called bookCollection
*        Should be a vector of string objects
*        Users will be prompted to type in the titles of the books
*        Use the getLine() function rather than just "cin" to get the user input
*-Provide a menu for the user to:
*        Add a book to the collection
*        Display the books currently in the collection
*        Remove a book from the collection
*        Stop adding books and store the data in an external file
*-Use the “push_back()” function appropriately to add the books to the collection
*-Correctly use an iterator to move through and display the collection
*-Correctly use an iterator for removing a specific book when necessary.
*-Put the collection in alphabetic order before storing to the external file,
*        only after all titles are added and any desired titles have been removed
*        Should happen immediately before the file is written
*-Ensure that the external file is open for writing
*-Name the file appropriately within the programming
*        Do not have the user enter a file name
*-After the collection has been written to the file, make sure the file is correctly closed.
*-Next, open the file for reading, and read the data into a new vector called "displayCollection"
*-Use this vector to display the list of books to the user
*-Lastly the program should ask if the user would like to run the program again
*        If they choose yes, ensure that both vectors are cleared out, and the program starts over again
*        If they choose no, the program should then end
*-Make sure that you use functions for each of the different menu options
*        Creating and displaying the menu itself
*        Adding a book to the list
*        Displaying the current list (Also used at the end of the program)
*        Removing a book from the list
*            This function will call the display function to show the list
*            Then it will ask the user which book they want to remove
*-Also create functions for the following:
*        Writing the collection to the file
*        Clearing out the two vectors at the end of the program (use a pointer for this)
*
*
*
* Author: Angela Robinson
* Date:   May 31, 2018
*
**********************/



// PreProcessor Directives
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <vector>
#include "BookCollection.h"

using namespace std;



//Main Program
int main()
{
	//variables
	vector<string> bookCollection;
	vector<string> displayCollection;
	vector<string> fullCollection;
	vector<string> *clear;
	int choice;
	char cont = 'Y';

	//code
	while (cont == 'Y')
	{
		//clear all previously saved vectors
		clear = &bookCollection;
		clearVector(clear);
		clear = &displayCollection;
		clearVector(clear);
		clear = &fullCollection;
		clearVector(clear);

		cout << "Your current list is: ";
		displayBooks(bookCollection);
		cout << '/n' << endl;
		cout << "Your saved list is: ";
		displayBooks(displayCollection);
		cout << '/n' << endl;
		cout << "Your Full list is: ";
		displayBooks(fullCollection);
		cout << '/n' << endl;

		//offer menu and get choice
		choice = menu();

		//loop while choice isn't exit
		while (choice != 7)
		{
			switch (choice)
			{
			case 1:
				addBook(bookCollection);
				break;
			case 2:
				removeBook(bookCollection);
				break;
			case 3:
				displayBooks(bookCollection);
				break;
			case 4:
				saveBooks(bookCollection);
				break;
			case 5:
				openBooks(displayCollection);
				displayBooks(displayCollection);
				break;
			case 6:
				fullCollection = mergeVectors(bookCollection, displayCollection);
				saveBooks(fullCollection);
				displayBooks(fullCollection);
				break;
			default:
				cout << "That is not a valid entry, please try again." << endl;
				break;

			}

			choice = menu();
		}

		//if choice exit, ask if the user wants to run program again.
		cout << "Your current list is: "; 
		displayBooks(bookCollection);
		cout << '/n' << endl;
		cout << "Your saved list is: ";
		openBooks(displayCollection);
		displayBooks(displayCollection);
		cout << '/n';
		cout << "Would you like to run the program again? (Y or N) ";
		cin >> cont;
		cont = toupper(cont);

		
	}

	
	//if user doesn't want to run program again
	cin.ignore();//clear buffer
	cout << "Press any key to exit . . .";
	getchar(); //this will accept any charcter including Enter
			   //system("Pause");
	return 0;
}

