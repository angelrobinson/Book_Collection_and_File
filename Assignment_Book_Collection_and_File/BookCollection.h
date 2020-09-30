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

//function Prototypes
int menu();
void addBook(vector<string>&);
void removeBook(vector<string>&);
void displayBooks(vector<string>);
void saveBooks(vector<string>);
vector<string> openBooks(vector<string>&);
vector<string> mergeVectors(vector<string>&, vector<string>&);
vector<string> * clearVector(vector<string> *);