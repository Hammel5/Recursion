#include "Stack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream inFile;        // file containing operations
    ofstream outFile;       // file containing output
    string inFileName;      // input file external name
    string outFileName;     // output file external name
    string outputLabel;     // the label at the top of the output file
    string command;         // operation to be executed

    int number;             // the value put into the Item
    ItemType item;          // the item that will be placed 
    Stack stack;            // the list of items where the last in is first out
    int numCommands;        // the number of commands that are excuted


    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << outputLabel << endl;

    inFile >> command;

    numCommands = 0;
    while (command != "Quit") // if quit is inputted the program will quit
    {
        if (command == "Push") // if push is inputted an item will be added and it will be printed on the screen
        {
            inFile >> number;
            item.Initialize(number);
            stack.Push(item);
            item.Print(outFile);
            outFile << " has been added to the top" << endl;
        }
        else if (command == "Pop") // if pop is inputted the first item will be deleted and it will be printed on the screen
        {
            stack.Pop();
            item.Print(outFile);
            outFile << " has been deleted from the top" << endl;
        }
        else if (command == "Top") // if top is inputted the top item will be printed on the screen
        {
            stack.Top().Print(outFile);
            outFile << " is at the top of the stack" << endl;
        }
        else if (command == "IsFull") // if isFull is inputted it will check if the stack is full and it will be printed on the screen
        {
            if (stack.IsFull())
                outFile << "List is full." << endl;
            else outFile << "List is not full." << endl;
        }
        else if (command == "IsEmpty") // if isEmpty is inputted it will check if the stack is empty and it will be printed on the screen
        {
            if (stack.IsEmpty())
                outFile << "List is empty." << endl;
            else outFile << "List is not empty." << endl;
        }
        else if (command == "Reverse") // if reverse is inputted it will reverse the stack to the top is moved to the bottom and vice versa 
        {
            stack.head = stack.reverse(stack.head);
            outFile << "List has been reversed" << endl;
        }
        else cout << "Command not recognized." << endl; // will be outputted if no command is recognized

        numCommands++;
        cout << command;
        cout << " Command number " << numCommands << " completed." << endl;
        inFile >> command;
    }

    cout << endl << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}