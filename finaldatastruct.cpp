#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
typedef struct Node * temp_node;
int numberOfElements;
using namespace std;
struct Node {
    int data;
    Node *next;
};
bool printSteps = false;
void showList(temp_node a);
void division (temp_node head, temp_node *front, temp_node *back, bool yesDisplay){
    temp_node fast;
    temp_node slow;
    if (head==NULL || head->next==NULL){
        *front=head;
        *back=NULL;
    }
    else {
        slow =head;
        fast=head->next;
        while (fast !=NULL){
            fast=fast->next;
            if (fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        *front=head;
        *back=slow->next;
        slow->next=NULL;
        if (yesDisplay){
        showList(*front);
        showList(*back);
        }
    }
}
temp_node merge_List(temp_node a, temp_node b){
    temp_node mergedList=NULL;
    if (a==NULL){
        return b;
        } else if (b==NULL){
        return a;
    }
    if(a->data <= b->data){
        mergedList=a;
        mergedList->next = merge_List(a->next,b);
        } else{ mergedList=b;
        mergedList->next=merge_List(a,b->next);
    }
    return mergedList;
}
void merge_sort(temp_node *source, bool yesDisplay){
    temp_node head= *source;
    temp_node a=NULL;
    temp_node b=NULL;
    if (head==NULL || head->next==NULL){
        return;
    }
    division(head, &a,&b, yesDisplay);
    merge_sort(&a, yesDisplay);
    merge_sort(&b, yesDisplay);
    *source =merge_List(a,b);
}
void showList(temp_node head){

    temp_node current = head;
    while (current != NULL){
        cout<< current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
void display( Node *head){
    int counter = 1;
    if(!printSteps)
    return;
    Node* ptr = head;
    while(ptr) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
    cout << endl;
}
Node* mkList(int a[], int sz){
    Node *head = new  Node;
    Node *current = head;
    for(int i = 0; i < sz; i++) {
        current->data = a[i];
        if (i == sz - 1 ) {
            current->next = NULL;
            break;
        }
        current->next = new  Node;
        current = current->next;
    }
    return head;
}
void selectionSort(temp_node HEAD, bool yesDisplay){
    Node *h = HEAD, *i, *j, *next_i;
    for(i = h; i!=NULL && i->next!=NULL; i=i->next)
    {
        Node *min;
        min = i;
        for(j = i->next; j!=NULL ; j=j->next)
        {
            if(j->data < min->data)
            min=j;
        }
        if(min!=i)
        {
            if(yesDisplay){
            cout<<" Swap "<< i->data<<" with "<<min->data<<endl;
             swap(i->data,min->data);
            showList(HEAD);
            }
            else
                 swap(i->data,min->data);
        }
    }
    HEAD = h;
}
void bubble_Sort(Node *top, bool yesDisplay){
    Node *current, *neighbour, *ptr, *last, *swapping;
    last=NULL;
    while (current != top->next){
        ptr=current=top;
        neighbour=current->next;
        while(current !=last) {
            if(current->data > neighbour->data){
                if(yesDisplay)
                cout<< "swap "<<current->data<< " with "<<neighbour->data<< " :"<<endl;
                if (current ==top){
                    swapping=neighbour->next;
                    neighbour->next=current;
                    current->next=swapping;
                    top=neighbour;
                    ptr=neighbour;
                }
                else{
                    swapping=neighbour->next;
                    neighbour->next=current;
                    current->next=swapping;
                    ptr->next=neighbour;
                    ptr=neighbour;
                }

                if (yesDisplay)
                showList(top);
            }
            else{
                ptr=current;
                current=current->next;
            }
            neighbour=current->next;
            if (neighbour==last){
                last=current;
            }
        }
    }
}
void insertionSort(temp_node current, bool displayData){
    temp_node head = current;
    temp_node insertionPointer = head;
    current = current->next;
    while(current != NULL){
        insertionPointer = head;
        while(insertionPointer->next != current){
            if (insertionPointer->data > current->data){
                if(displayData)
                cout<<" Swap "<<insertionPointer->data<<" with "<<current->data<<endl;
                int temp = current->data;
                current->data = insertionPointer->data;
                insertionPointer->data = temp;
                if (displayData)
                showList(head);
                }else{
                insertionPointer = insertionPointer->next;
            }
        }
        current = current->next;
    }
}

void test(int arr[],int size){
    Node *head =NULL;
    head = mkList(arr,size);

    if (size < 200)
    showList(head);
    if (size < 200){
            TICK();
    merge_sort(&head, true);
    TOCK();
    }
    else{
            TICK();
    merge_sort(&head, false);
     TOCK();
    }
    cout<< "sorted Merge List :"<<endl;
    showList(head);

    SHOW_DURATION();
    system ("color 3b");
      system("pause");
    cout<< "Bubble Sort"<<endl;
    head = mkList(arr, size);
    if (size <200)
    display(head);

    if (size <200){
             TICK();
    bubble_Sort(head, true);
    TOCK();
    }
    else{
            TICK ();
    bubble_Sort(head, false);
    TOCK ();
    }
    cout<< "sorted Bubble Method  :\n";
    showList(head);

    SHOW_DURATION();
    system ("color 2a");
      system("pause");
    cout<< "insertion method"<<endl;
    head = mkList(arr, size);
    if (size <200)
    display(head);

    if (size < 200){
            TICK ();
    insertionSort(head, true);
    TOCK ();
    }
    else{
            TICK ();
    insertionSort(head, false);
    TOCK ();
    }
    cout<< "sorted Insertion :\n";
    showList(head);

    SHOW_DURATION();
    system ("color 1b");
      system("pause");
    cout<< "selection method"<<endl;
    head = mkList(arr, size);
    if (size <200)
    display(head);

    if (size <200){
            TICK ();
    selectionSort(head, true);
    TOCK ();
    }
    else{
            TICK ();
    selectionSort(head, false);
    TOCK ();
    }
    cout<< "sorted Selection Method : \n";
    showList(head);

    SHOW_DURATION();
    cout << endl;
    system ("color 3c");
      system("pause");
}

int main(void){
    cout<< "Merge Sorting"<<endl;

    int lowest=0, highest=2000;
    int range=(highest-lowest)+1;
    int arr[2000];
    for(int index=0; index<2000; index++){
        int random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0));
        arr[index] = random_integer;
    }
    string userInput;
    do
    {
        system("cls");
        system ("color 3a");
        cout<<"1. 2000 Elements \n";
        cout<<"2. 200 Elements \n";
        cout<<"3. 20 Elements \n";
        cout<<"4. Exit\n";
        cin >> userInput;
        if (userInput == "1")
        {
            cout<<"2000 Elements \n";
            test(arr,2000);



        }else if (userInput == "2"){


                cout<<"200 Elements \n";
        test(arr,200);
        }else if (userInput == "3")
        {
            cout<<"20 Elements \n";
            test(arr,20);
        }else if (userInput == "4"){

            return 0;
        }else
        {

            cout<<"Invalid Input\n";
            system("pause");
        }
    }while (true);


    return 0;
}
