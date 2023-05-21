// all operation will be independent
// 1. insertion at first position
// 2. insertion at last position
// 3. insertion at between position
// 4. insertion at random position
// 5. deletion at first postion
// 6. deletion at last postion
// 7. deletion at between postion
// 8. deletion at random postion
// 9. linked list traversal
// 10. search node
// 11. exit()

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_first();
void insert_last();
void insert_between();
void insert_random();
void delete_first();
void delete_last();
void delete_between();
void delete_random();
void display();
void search();

int main()
{
    cout << "******************WELCOME********************\n\n";
    int choice;
    while (choice != 11)
    {
        cout << "\nplease select one option from the menu:\n";
        cout << "1.insert first()\n";
        cout << "2.insert last()\n";
        cout << "3.insert between()\n";
        cout << "4.insert random()\n";
        cout << "5.delete first()\n";
        cout << "6.delete last()\n";
        cout << "7.delete between()\n";
        cout << "8.delete random()\n";
        cout << "9.display Node()\n";
        cout << "10.Search Node()\n";
        cout << "11.insert exit()\n";
        cout << "Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_between();
            break;
        case 4:
            insert_random();
            break;
        case 5:
            delete_first();
            break;
        case 6:
            delete_last();
            break;
        case 7:
            delete_between();
            break;
        case 8:
            delete_random();
            break;
        case 9:
            display();
            break;
        case 10:
            search();
            break;
        case 11:
            exit(0);
            break;

        default:
            cout<<"Please enter valid choice.. \n\n";
            break;
        }
    }
    return 0;
}

void insert_first(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        cout<<"Linked list Overflow: \n";
    }else{
        int num;
        cout<<"Enter element: ";
        cin>>num;
        ptr->data = num;
        ptr->next = head;
        head = ptr;
        cout<<"Element inserted: "<<head->data<<"\n";
    }
}
void insert_last(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int element;
    if(ptr == NULL){
        cout<<"Linked list Overflow:\n";
    }else{
        struct node* temp = head;
        cout<<"Enter element: ";
        cin>>element;
        ptr->data = element;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
            cout<<"Element inserted: ";
        }else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout<<"Element Inserted: "<<ptr->data<<"\n";
        }
    }
}
void insert_between(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        cout<<"Unable to allocate memory:\n";
    }else{
        int element;
        cout<<"Enter element:";
        cin>>element;
        ptr->data = element;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
            cout<<"Element inserted: "<<head->data<<"\n";
        }else if(head->next ==NULL){
            head->next = ptr;
            ptr->next = NULL;
            cout<<"Element inserted: "<<ptr->data<<"\n";
        }
        else{
            int i = 0;
            struct node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
                i++;
            }
            temp = head;
            int mid = i/2;
            for(int i=0; i<=mid-1; i++){
                temp = temp->next;
            }
            ptr->next = temp->next;
            temp->next = ptr;
            cout<<"element inserted: "<<ptr->data<<"\n";
        }
    }
}
void insert_random(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        cout<<"Unable to memory allocate:\n";
    }else{
        int element;
        cout<<"Enter element:";
        cin>>element;
        ptr->data = element;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
            cout<<"Element inserted: "<<head->data<<"\n";
        }else if(head->next == NULL){
            ptr->next = NULL;
            head->next = ptr;
            cout<<"Element inserted: "<<ptr->data<<"\n";
        }else{
            int position;
            cout<<"Enter the location after which you want to insert ";
            cin>>position;
            struct node *temp = head;
            for(int i=1; i<position-1; i++){
                temp = temp->next;
                if(temp == NULL){
                    cout<<"Unable to Insert invalid position:\n";
                    return;
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
            cout<<"Element Inserted:"<<ptr->data<<"\n";
        }
    }
}
void delete_first(){
    if(head == NULL){
        cout<<"Linked list empty:\n";
    }else{
        struct node *ptr = head;
        head = ptr->next;
        cout<<"Node deleted from the begning: "<<ptr->data<<"\n";
        free(ptr);
    }
}
void delete_last(){
    if(head == NULL){
        cout<<"Linked list empty:\n";
    }
    else if(head->next == NULL){
        cout<<"Element deleted: "<<head->data;
        free(head);
        head = NULL;
    }
    else{
        struct node *ptr = head;
        struct node *ptr1 = head->next;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        cout<<"Element deleted: "<<ptr1->data<<"\n";
        free(ptr1);
    }
}
void delete_between(){
    if(head == NULL){
        cout<<"Linked lst in empty:\n";
    }else if(head->next == NULL ){
        cout<<"Element deleted: "<<head->data<<"\n";
        free(head);
        head = NULL;
    }else{
        struct node *ptr = head;
        int i=1;
        while(ptr->next != NULL){
            ptr = ptr->next;
            i++;
        }
        int mid = i/2;
        ptr = head;
        struct node *ptr1 = head->next;
        for(int i=1; i<mid; i++){
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
        ptr->next = ptr1->next;
        cout<<"Element deleted: "<<ptr1->data<<"\n";
        free(ptr1);
    }
}
void delete_random(){
    if(head == NULL){
        cout<<"Linked list Empty:\n";
    }else if(head->next == NULL){
        cout<<"Element deleted: "<<head->data<<"\n";
        free(head);
        head = NULL;
    }else{
        struct node *ptr , *temp;
        int position;
        cout<<"Enter position which element do you want to delete: ";
        cin>>position;
        ptr = head;
        temp = head->next;
        for(int i=1; i<position-1; i++){
            temp = temp->next;
            ptr = ptr->next;
        }
        ptr->next = temp->next;
        cout<<"Element deleted: "<<temp->data<<" \n";
        free(temp);
    }
}
void display(){
    if(head != NULL){
        struct node *ptr = head;
        cout<<"Element are: \n";
        while(ptr != NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<"\n";
    }else{
        cout<<"Linked list Empty:\n";
    }
}
void search(){
    if(head == NULL){
        cout<<"Linked list is empty:\n";
    }else{
        int num;
        cout<<"Enter item which you want to search: ";
        cin>>num;
        struct node *ptr = head;
        int flag , i = 1;
        while(ptr != NULL){
            if(ptr->data == num){
                cout<<"Element found at index: "<<i<<"\n";
                flag = 1;
                return;
            }
            ptr = ptr->next;
            i++;
        }
        if(flag != 1){
            cout<<"Element not found:\n";
        }
    }
}