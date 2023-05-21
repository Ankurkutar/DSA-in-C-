#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

 void linked_list_travel(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
 }
 

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *first = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));
    struct node *five = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = five;

    five->data = 60;
    five->next = NULL;

    cout<<"Linked list program: \n";
    cout<<"Linked list printing:\n";

    linked_list_travel(head);

    return 0;
}
