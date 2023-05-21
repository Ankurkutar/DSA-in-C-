// linked list insertion operation 
// 1. insert in begning
// 2. insert in last 
// 3. insert in between
// 4. insert in random position

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void linked_list_traversal(struct node* head) {
    if (head != NULL) {
        struct node* ptr = head;
        cout<<"Element are: \n";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    } else {
        cout << "Linked list empty\n";
    }
}

struct node* insert_at_begning(struct node *head, int element){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = element;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node* insert_at_last(struct node* head, int element)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    ptr->data = element;
    ptr->next = NULL;
    temp->next = ptr;
    return head;
};

struct node* insert_at_between(struct node* head, struct node* prevNode, int element){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = element;
    temp->next = prevNode->next;
    prevNode->next = temp;
    return head;

}

struct node* insert_at_index(struct node* head, int index, int element){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = element;
    struct node *temp = head;
    int i=0;
    while(i != index-1){
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    return head;

}


int main(){
    cout<<"******************WELCOME********************\n";
     
     struct node *head = NULL;
     struct node *first;
     struct node *second;
     struct node *third;
     struct node *fourth;

     head = (struct node*)malloc(sizeof(struct node));
     first = (struct node*)malloc(sizeof(struct node));
     second = (struct node*)malloc(sizeof(struct node));
     third = (struct node*)malloc(sizeof(struct node));
     fourth = (struct node*)malloc(sizeof(struct node));

     

     head->data = 10;
     head->next = first;

     first->data = 20;
     first->next = second;

     second->data = 30;
     second->next = third;

     third->data = 40;
     third->next = fourth;

     fourth->data = 50;
     fourth->next = NULL;

    linked_list_traversal(head);
    cout<<"\nfirst insertion: \n";
    head = insert_at_begning(head, 55);
    linked_list_traversal(head);
    cout<<"\nLast insertion: \n";
    head = insert_at_last(head, 78);
    linked_list_traversal(head);
    cout<<"\nBetween insertion: \n";
    head = insert_at_between(head , second, 100);
    linked_list_traversal(head);
    cout<<"\nAfter index insertion: \n";
    head = insert_at_index(head,4,  555);
    linked_list_traversal(head);
    
    
    return 0;
}