#include<iostream>
using namespace std;

struct node
{
    int value;
    node* previous;
    node* next;
    node (int x)
    {
        value=x;
        next=nullptr;
        previous=nullptr;
    }
};

void insert2 (node* &head,node* pre, int y)
{
    node* n1=new node(y);
    if (head== nullptr)
    {
        head=n1;
    }
    else
    {
        n1->next=pre->next;
        n1->previous=pre;
        pre->next->previous=n1;
        pre->next=n1;
    }

}

//Delete the element which is exactly two positions ahead of the number 7
void deleteAtAny(node* &head, int x) {
    node* temp = head;

    while (temp != nullptr && temp->value != x)
    {
        temp = temp->next;
    }

    temp=temp->next->next;

    if (temp == nullptr)
    {
        cout << "Value not found\n";
        return;
    }
    if (temp == head)
    {
        head = head->next;
        if (head != nullptr)
            head->previous = nullptr;
        delete temp;
        return;
    }
    if (temp->previous != nullptr)
        temp->previous->next = temp->next;
    if (temp->next != nullptr)
        temp->next->previous = temp->previous;

    delete temp;
}

//· Insert at the position that is equal to the number of elements currently divisible by 2
void insert1(node* &head,int y)
{
    node* n1=new node (y);
    int x=0;
    node* temp=head;
    node* temp1=head;
    while (temp!=nullptr)
    {
        if (temp->value % 2 ==0)
        {
            x++;
        }
        temp=temp->next;
    }
    for (int i=0;i<x-2;i++)
    {
        temp1=temp1->next;
    }
       n1->next=temp1->next;
        n1->previous=temp1;
        temp1->next->previous=n1;
        temp1->next=n1;
}

//Delete the element that is at the position of the highest number in the list
void delete1(node* &head)
{
    node* temp=head;
    node* temp1;
    node* temp2=head;
    node* high=head;
    while (temp2!=nullptr)
    {
        if (temp2->value > high->value)
        {
            high=temp2;
        }
        temp2=temp2->next;
    }

    if (high == head)
    {
        head = head->next;
        if (head != nullptr)
            head->previous = nullptr;
        delete high;
    }
    else
    {
        if (high->previous != nullptr)
            high->previous->next = high->next;
        if (high->next != nullptr)
            high->next->previous = high->previous;
        delete high;
    }
}

void display (node* &head)
{
    cout << "link list elements are : ";
    node* temp=head;
    while (temp!=nullptr)
    {
        cout << temp->value<< " -> ";
        temp=temp->next;
    }
    cout << endl;
}

class queue
{
public:

    struct node1
{
    int value;
    node1* next;
    node1 (int x)
    {
        value=x;
        next=nullptr;
    }
};

    node1* front=nullptr;
    node1* rear=nullptr;

    //from the final list, enqueue all elements that are even, from left to right.
    void enqueue (node* &head)
    {
        node* temp=head;
        while (temp!=nullptr)
        {
            if (temp->value % 2 == 0)
            {
                node1* n1=new node1(temp->value);
                if (front==nullptr && rear==nullptr)
                {
                    front=n1;
                    rear=n1;
                }
                else
                {
                    rear->next=n1;
                    rear=n1;
                }
            }
            temp=temp->next;
        }
    }

    void dequeue ()
    {

        if (front==nullptr)
        {
            cout << "queue is empty "<<endl;
            return;
        }

        node1* temp=front;
        if (front == rear)
        {
            front = rear=nullptr;
        }

       else
        {
            front=front->next;
        }
         delete temp;

    }
    //Enqueue the sum of the current first and last elements in the queue
    void enqueue1()
    {
        if (front !=nullptr && rear!=nullptr)
        {
            int x=(front->value + rear->value);
        node1* n1 = new node1(x);

        if (front==nullptr && rear==nullptr)
                {
                    front=n1;
                    rear=n1;
                }
                else
                {
                    rear->next=n1;
                    rear=n1;
                }
    }
        }

    void display ()
    {
        node1* temp=front;
        if (temp==nullptr)
        {
            cout << "queue is empty "<<endl;
            return;
        }
        cout << " queue elements are : ";
        while (temp!=nullptr)
        {
            cout << temp->value<< " -> ";
            temp=temp->next;
        }
        cout << endl;
    }
};

int main ()
{
    node* d1=new node(16);
    node* d2=new node(29);
    node* d3=new node(7);
    node* d4=new node(42);
    node* d5=new node(13);

    node* head=d1;

    d1->next=d2;

    d2->previous=d1;
    d2->next=d3;

    d3->previous=d2;
    d3->next=d4;

    d4->previous=d3;
    d4->next=d5;

    d5->previous=d4;

    //insert 11 after second elements
    insert2 (head,d2,11);

    //Insert 5 at the position that is equal to the number of elements currently divisible by 2
    insert1 (head,5);

    //Delete the element which is exactly two positions ahead of the number 7
    deleteAtAny(head,7);

    //Delete the element that is at the position of the highest number in the list
    delete1(head);

    //printing elements
    display (head);


    // making queue
    queue q1;
    //from the final list, enqueue all elements that are even, from left to right.
    q1.enqueue(head);
    q1.display();

    //Dequeue one element
    q1.dequeue();
    q1.display();

    //Enqueue the sum of the current first and last elements in the queue
    q1.enqueue1();
    q1.display();

    //display the queue
    q1.display();

    return 0;
}

