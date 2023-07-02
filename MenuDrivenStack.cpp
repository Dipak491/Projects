#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        node *next;

        node(int value) //constructor 
        {
            data = value;
            next = NULL;
        }

}NODE,*PNODE;
///////////////////////////////////////////////////////
class Stack
{
    private:
        PNODE First;
        int iCount;

    public:
        Stack();
        void Push(int no); //insertlast
        int Pop(); // Deletelast
        void Display();
        int Count();

};
///////////////////////////////////////////////
Stack ::Stack()
{
    First = NULL;
    iCount = 0;
}
///////////////////////////////////////////
void Stack :: Push(int no)  //insertlast
{
    PNODE newn = new NODE(no);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=newn;
    }

    iCount++;

}
//////////////////////////////////////////////
int Stack:: Pop() //deleteLast()
{
    int value =0;
    PNODE newn = new NODE(value);

    if(iCount == 0)  //(First == null)
    {
        cout<<"Stack is empty  /n";
        return -1;  //function chi return value int ahe mnun 
    }
    else if(iCount == 1)
    { 
        value = First -> data;
        delete First;
        First = NULL; // 1 hota to pan gela mnun null krn garjech ah 
    }
    else
    {
        
        PNODE temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    return value;
}
////////////////////////////////////////////////
void Stack::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to Display as stack is empty\n";
    }
    cout<<"Elements of stack: \n";
    PNODE temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }

}
////////////////////////////////////////////////

int Stack::Count()
{
    return iCount;

}
/////////////////////////////////////////////////////


int main()
{
    Stack obj;
    int iChoice = 1;
    int iValue =0;
    int iRet = 0;

    cout<<"------------------------------------------\n";
    cout<<"Dynamic Implimentation of stack \n";
    cout<<"------------------------------------------\n";
    while(iChoice != 0)
    {
        cout<<"------------------------------------------\n";
        cout<<"Please Enter the option : \n";

        cout<<"1 : Push element into stack\n";
        cout<<"2 : Pop element from the stack\n";
        cout<<"3 : Display Number of elements from stack\n";
        cout<<"4 : Count number of elements from stack\n";
        cout<<"0: Terminate the application \n";
        cout<<"------------------------------------------\n";


        cin>>iChoice;

        switch(iChoice)
        {
            case 1: 
                cout<<"Enter the element at you want to push \n";
                cin>>iValue;
                obj.Push(iValue);
                break;

            case 2:
               iRet =  obj.Pop();
                if(iRet != -1)
                {
                    cout<<"Poped element from stack is :"<<iRet<<"\n";
                }
                break;

            case 3:
                obj.Display();
                break;
            
            case 4:
                iRet = obj.Count();
                cout<<"Number of elements are: "<< iRet<<"\n";
                break;

            case 0:
                cout<<"Thank you for using the application \n";

            default:
                cout<<"Please enter valid option\n";
                break;
        } //end of switch 
    }//end of while 
    
    return 0;
}//end of main