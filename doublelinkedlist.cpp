#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addnode()
    {
         int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *newnode = new Node;

        newnode->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }

            newnode->next = START;

            if (START != NULL)
                START->prev = newnode;

            newnode->prev = NULL;
            START = newnode;
            return;
        }
        Node *current = START;

        while (current->next != NULL && current->next->noMhs < nim)
            current = current->next;

        if (current->next != NULL && current->next->noMhs == nim)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        newnode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newnode;

        newnode->prev = current;
        current->next = newnode;
    }  

    void deletenode()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "\nRecord not found" << endl;
            return;
        }
        if (current == START)
        {
            START = current->next;

            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev->next = current->next;
        }

        delete current;
        cout << "\nRecord with roll number " << rollNo << " deleted" << endl;
    }
    void traverse()
    {
        
    }
};