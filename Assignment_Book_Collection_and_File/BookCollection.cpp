/********************
*Assignment:  Book Collection And File

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
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int menu()
{
	int input;

	cout << std::string(60, '#') << endl;
	cout << "\t What would you like to do today?\n";
	cout << "\t 1. Add A Book\n";
	cout << "\t 2. Remove a Book\n";
	cout << "\t 3. See what books you have\n";
	cout << "\t 4. Overwrite Books.txt and save your books\n";
	cout << "\t 5. Open list of books from file Books.txt\n";
	cout << "\t 6. Merge two lists together and save back to file Books.txt\n";
	cout << "\t 7. Exit\n";
	cout << std::string(60, '#') << endl;
	cout << "\nPlease enter your choice: ";
	cin >> input;


	//verify a number was put in, if not make input zero to flag the default message of not valid entry
	if (cin.fail())
	{
		input = 0;
		cin.clear();
		cin.ignore();
	}
	
	return input;
	
};

void addBook(vector<string>& collection)
{
	//ask user to enter in name of book to add
	string bookName;
	cout << "What is the name of the book you want to add to your collection? ";

	//clear buffer and get full name of book including spaces
	cin.ignore();
	getline(cin, bookName);

	bookName[0] = toupper(bookName[0]); //make sure first letter is capitalized
	
	//add to the collection
	collection.push_back(bookName);

};

void removeBook(vector<string>& collection)
{
	//ask user to enter in name of book to remove
	string bookName;
	cout << "What is the name of the book you want to remove from your collection? ";

	//clear buffer and get full name of book including spaces
	cin.ignore();
	getline(cin, bookName);

	bookName[0] = toupper(bookName[0]); //make sure first letter is capitalized
	
	int notFound = 0;
	//iterate through the book collection and compare what entered to name
	//delete if matches
	for (size_t index = 0; index < collection.size(); index++)
	{
		if (collection.at(index) == bookName)
		{
			collection.erase(collection.begin() + index);
		}
		else
		{
			notFound++;
		}
	}

	if (notFound == collection.size())
	{
		cout << "Sorry that book was not found in the list." << endl;
	}
};

void displayBooks(vector<string> collection)
{
	//sort the collection
	sort(collection.begin(), collection.end());

	//loop through the collection and print out the contents
	for (vector<string>::iterator book = collection.begin(); book < collection.end(); book++)
	{
		cout << *book << endl;
	}
};

void saveBooks(vector<string> collection)
{
	//sort collection
	sort(collection.begin(), collection.end());

	//declare file stream
	ofstream saveFile;

	//open file stream
	saveFile.open("Books.txt");

	if (saveFile.fail())
	{
		cout << "Something went wrong and the file Books.txt could not be created." << endl;
	}

	//write to the file.
	//this will overwrite what ever was in the file before
	for (vector<string>::iterator book = collection.begin(); book < collection.end(); book++)
	{
		saveFile << *book << endl;
	}

	//close file
	saveFile.close();
};

vector<string> openBooks(vector<string>& collection)
{
	//delcare file stream
	ifstream inFile;

	//open file
	inFile.open("Books.txt");

	if (inFile.fail())
	{
		cout << "There is not a file named Books.txt" << endl;
	}

	//variable to hold the read in name
	string name; 

	//read each line
	while (inFile.good())
	{
		inFile >> name;

		collection.push_back(name);
	}
	
	//close file
	inFile.close();

	return collection;
};

vector<string> mergeVectors(vector<string>& collection1, vector<string>& collection2)
{
	vector<string> mergedVector;

	//loop through collection1 to add to merged vector
	for (vector<string>::iterator book = collection1.begin(); book < collection1.end(); book++)
	{
		mergedVector.push_back(*book);
	}

	//loop through collection2 to add to merged vector
	for (vector<string>::iterator book = collection2.begin(); book < collection2.end(); book++)
	{
		mergedVector.push_back(*book);
	}

	return mergedVector;
	
};

vector<string> * clearVector(vector<string> *collection)
{
	collection->clear();

	return collection;
};