
// sinlgy linear list
#include <iostream>  //for input output
using namespace std; // for cin cout

typedef struct Node
{
    int data;
    struct Node *next;

} NODE, *PNODE;

class SinglyLL
{
private:
    PNODE First; // characterstic   8byet
    int iCount;  // characteristic  4byte

public:
    SinglyLL();  // constructr
    ~SinglyLL(); // Destructor

    void InsertFirst(int no); // behaviour
    void InsertLast(int no);  // behaviour

    void DeleteFirst(); // behaviour
    void DeleteLast();  // behaviour

    void InsertAtPos(int no, int ipos); // behaviour
    void DeleteAtPos(int ipos);         // behaviour

    void Display(); // behaviour
    int Count();    // behaviour
};

// implimentaion of all behaviours

/*
return_value Class_name :: Function_name(Paramteter_List)
{
    Function_body
}

*/
///////////////////////////////////////////////////
void SinglyLL ::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE; // newn = (PNODE)malloc(sizeof(NODE))
    newn->data = no;
    newn->next = NULL;

    if (First == NULL) // if LL is empty
    {
        First = newn;
    }
    else // LL contain atleast one node
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}
/////////////////////////////////////////////////
void SinglyLL ::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE; // newn = (PNODE)malloc(sizeof(NODE))
    newn->data = no;
    newn->next = NULL;

    if (First == NULL) // if LL is empty
    {
        First = newn;
    }
    else // LL contain atleast one node
    {
        PNODE temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

///////////////////////////////////////////////

void SinglyLL ::DeleteFirst()
{

    if (First == NULL) // empty LL
    {
        return;
    }
    else if (First->next == NULL) // single node in LL
    {
        delete First; // free(First);
        First = NULL;
    }
    else // more than one node
    {
        PNODE temp = First;

        First = First->next;
        delete temp;
    }
    iCount--;
}

///////////////////////////////////////////////

void SinglyLL ::DeleteLast()
{
    if (First == NULL) // empty LL
    {
        return;
    }
    else if (First->next == NULL) // single node in LL
    {
        delete First; // free(First);
        First = NULL;
    }
    else // more than one node
    {
        PNODE temp = First;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////
void SinglyLL ::Display()
{
    PNODE temp = First;
    cout << "Eelements of Linked list are :"
         << "\n";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

//////////////////////////////////////////////////
int SinglyLL ::Count()
{
    return iCount;
}
/////////////////////////////////////////////////////

SinglyLL ::SinglyLL()
{
    cout << "Inside Constructor \n";
    First = NULL; //
    iCount = 0;
}
/////////////////////////////////////////

SinglyLL ::~SinglyLL()
{
    cout << "Inside destructor \n";
    PNODE temp = First;

    for(int iCnt =1; iCnt<= iCount; iCnt++)
    {
        temp = First;
        First = First-> next;
        delete temp;
    }
}

//////////////////////////////////////////////////
void SinglyLL ::InsertAtPos(int no, int ipos)
{
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp = First;

        for (int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////
void SinglyLL ::DeleteAtPos(int ipos)
{

    if ((ipos < 1) || (ipos > iCount)) //
    {
        cout << "Invalid Position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempx = NULL;

        for (int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        tempx = temp->next;
        // sequece is imp
        temp->next = temp->next->next;
        delete tempx;

        iCount--;
    }
}

int main()
{
    SinglyLL obj;
    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;
    cout << "Marvellous Linkedlist application \n";

    while (1) // unconditional loop
    {
        cout << "-----------------------------------------------------\n";
        cout << "Please enter your choice : \n\n";

        cout << "1: Insert node at First position \n";
        cout << "2: Insert node at Last position \n";
        cout << "3: Insert node at the given position \n";
        cout << "4: Delete node at First position \n";
        cout << "5: Delete node at Last position \n";
        cout << "6: Delete node at givem position \n";
        cout << "7: Display the elements of linked list \n";
        cout << "8: Count number of nodes in linked list  \n";
        cout << "9: Terminate the application \n";
           cin >> iChoice;
cout<<"-----------------------------------------------------\n";
     
        switch (iChoice)
        {
        case 1:
            cout << "Enter the value that you want to insert: \0";
            cin >> iValue;
            obj.InsertFirst(iValue);
            obj.Display();
            break;

        case 2:
            cout << "Enter the value that you want to insert: \0";
            cin >> iValue;
            obj.InsertLast(iValue);
             obj.Display();
            break;

        case 3:
            cout << "Enter the value that you want to insert: \0";
            cin >> iValue;

            cout << "Enter the position \n";
            cin >> iPosition;
            obj.InsertAtPos(iValue, iPosition);
             obj.Display();
            break;

        case 4:
            obj.DeleteFirst();
             obj.Display();
            break;

        case 5:
            obj.DeleteLast();
             obj.Display();
            break;

        case 6:
            cout << "Enter the position \n";
            cin >> iPosition;
            obj.DeleteAtPos(iPosition);
             obj.Display();
            break;

        case 7:
            obj.Display();
            break;

        case 8:
            cout << "Number of elements are :" << obj.Count() << "\n";
            break;

        case 9:
            cout << "Thank you for using the application \n";
            return 0;

        default:
            cout << "Invalid choice \n";
            break;
        }
        cout << "-----------------------------------------------------\n";
    }

    return 0;
}