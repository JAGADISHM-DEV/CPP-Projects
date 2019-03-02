/******************************************************************************

A stack can be easily implemented through the linked list. In stack Implementation, a stack contains a top pointer. which is “HEAD” of the stack where pushing and popping items happens at the head of the list. 
First node have null in link field and second node link have first node address in link field and so on and last node address in “top” pointer.

The main advantage of using linked list over an arrays is that it is possible to implements a stack that can shrink or grow as much as needed. In using array will put a restriction to the maximum capacity of the array which can lead to stack overflow. Here each new node will be dynamically allocate. so overflow is not possible.

Stack Operations:

push() : Insert a new  element into linked list, nothing but which is the top node of Stack.
pop() : Return top element from the Stack and move the top pointer to the second node of linked list or Stack.
display(): Print all element of Stack.


*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node
{
    int data;
    node *linkptr;
};

class StackImp
{
  node *TopofStack;
  public:
    StackImp()
    {
        TopofStack = NULL;
    }
    void push();
    void pop();
    void display();
    ~StackImp();
};


void StackImp :: push()
    {
        /* 
        Create a New Node Object from Heap Memeory whenever the 
        PUSH method is called from the Main Program
        NOTE : During the object creation the "struct node pointer" is set to NULL
        */
        
        node *allocnode = new node;
        cout << "Enter Data :";
        cin >> allocnode->data;
        allocnode->linkptr = NULL;
        
        /* 
        Main Alogrithm to Link the new node object to the previous Object
        MAKE the NEWLY CREATED OBJECT as the TOP OBJECT in the stack
        */
        
        if (TopofStack == NULL)
        TopofStack = allocnode;
        else 
        allocnode->linkptr = TopofStack;
        TopofStack = allocnode;
    }


void StackImp :: pop()
{
    node *tmpnode;
    
    if (TopofStack != NULL)
    {
    node *tmpnode = TopofStack;
    /* 
    Algorithm to delete the Top Element in the Stack
    CHANGE the link pointer of the TopofStack Node to the next node and remove the TOP link
    */
    
    TopofStack = TopofStack->linkptr;
    cout << tmpnode->data << "is Deleted from Top of the Stack \n";
    delete tmpnode;
    }
    else
    {
        cout << "Stack is Empty";
    }
}


void StackImp :: display()
{
    node *dispnode = TopofStack;    
    
    if (dispnode == NULL)
    {
    cout <<  "There are no Elements in the Stack\n";
    }
    
    while (dispnode != NULL)
    {
        cout << dispnode->data << endl;
        dispnode = dispnode->linkptr;
    }
}


StackImp :: ~StackImp()
{
    while (TopofStack != NULL)
    {
        node *delnode = TopofStack;
        TopofStack = TopofStack->linkptr;
        delete delnode;
    }
    
}

int main()
{
    // Create a new Stack OBJECT
    StackImp create_stack;
    char ch;
    system ("clear");
    
    do
    {
        cout << "Stack IMPLEMENTATION using LINKED LIST \n";
        cout << "P for PUSH ";
        cout << "\nO for POP"; 
        cout << "\nD for DISPLAY";
        cout << "\nQ for QUIT \n";
        
        cin >> ch;
        
        switch (ch)
        {
            case 'P' : create_stack.push();
                       break;
            case 'O' : create_stack.pop();
                       break;
            case 'D' : create_stack.display();
                       break;
            case 'Q' : exit(0);
                       break;
        }

    }
    while (ch != 'Q');

    getch();
    
}

