/******************************************************************************

A Queue can be easily implemented through the linked list. In Queue Implementation, a Queue contains 
a FRONT & REAR pointer. 

FRONT is “HEAD” of the stack 
Insertion happens at the REAR of the list. 
Deletion of items happens at the FRONT of the list. 

Whenever a new Node Object is being created it will initialize the link pointer with NULL.

The main advantage of using linked list over an arrays is that it is possible to implement a stack that can shrink or 
grow as much as needed. In using array will put a restriction to the maximum capacity of the array which can lead to
stack overflow. Here each new node will be dynamically allocated, Hence overflow is not possible.

Stack Operations:

Insert() : Insert a new  element into linked list, nothing but which is the top node of Stack.
Delete() : Return top element from the Stack and move the top pointer to the second node of linked list or Stack.
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

int queue_count=0;


class QueueImp
{
  node *QueueFront, *QueueRear;
  public:
    QueueImp()
    {
        QueueFront = NULL;
        QueueRear = NULL;
    }
    void qInsert();
    void qDelete();
    void qDisplay();
    ~QueueImp();
};


void QueueImp :: qInsert()
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
        Main Alogrithm to Link the new node object to the Last Object in the linked list
        MAKE the NEWLY CREATED OBJECT as the REAR OBJECT in the list
        Note that newly created object link pointer will always be NULL dring creation
        */
        
        if (QueueRear == NULL)
        {
        QueueRear = allocnode;
        QueueFront = allocnode;
        cout << "\n FIRST Token Number : "<< allocnode->data << "in the QUEUE \n";
        }
        else 
        {
        cout << "\n Token Number : "<< allocnode->data << "Issued\n";
        QueueRear->linkptr = allocnode;
        QueueRear = allocnode;
        queue_count++;

        cout << "\nLAST Token Number is "<< allocnode->data << "in the QUEUE \n";
        cout << "\nThere are" << queue_count << " persons ahead in the QUEUE "  << "Please wait for your turn \n";
        }
    }


void QueueImp :: qDelete()
{
    node *tmpnode;
    
    if (QueueFront != NULL)
    {
    node *tmpnode = QueueFront;
    /* 
    Algorithm to delete the First Element in the QUEUE
    CHANGE the link pointer of the QueueFront Node to the next node and remove the First link
    */
    
    QueueFront = QueueFront->linkptr;
    cout << tmpnode->data << " : First element in Front of Queue is Deleted from LIST \n";
    delete tmpnode;
    }
    else
    {
        cout << "QUEUE is Empty";
    }
}


void QueueImp :: qDisplay()
{
    node *dispnode = QueueFront;    
    
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


QueueImp :: ~QueueImp()
{
    while (QueueFront != NULL)
    {
        node *firstNode = QueueFront;
        QueueFront = QueueFront->linkptr;
        delete firstNode;
    }
    
}

int main()
{
    // Create a new QUEUE OBJECT
    cout << "Hello World";
    
    QueueImp create_queue;
    char ch;
    system ("clear");
    
    do
    {
        cout << "QUEUE IMPLEMENTATION using LINKED LIST \n";
        cout << "ENTER YUR CHOICE: (1-4) \n";

        cout << "1 for INSERT";
        cout << "\n2 for DELETE"; 
        cout << "\n3 for DISPLAY";
        cout << "\n4 for EXIT \n";
        
        cin >> ch;
        
        switch (ch)
        {
            case '1' : create_queue.qInsert();
                       break;
            case '2' : create_queue.qDelete();
                       break;
            case '3' : create_queue.qDisplay();
                       break;
            case '4' : exit(0);
                       break;
        }

    }
    while (ch != '4');

    getch();
    
}
