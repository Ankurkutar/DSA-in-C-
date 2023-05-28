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
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL; // doubly linked list pointer

void insert_first();
void insert_last();
void insert_mid();
void insert_random();
void delete_first();
void delete_last();
void delete_mid();
void delete_random();
void display();
void search();

int main()
{

    cout << "Welcome to the Doubly Linked List!" << endl;
    int choice;
    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Insertion at the first position\n";
        cout << "2. Insertion at the last position\n";
        cout << "3. Insertion at between position\n";
        cout << "4. Insertion at a random position\n";
        cout << "5. Deletion at the first position\n";
        cout << "6. Deletion at the last position\n";
        cout << "7. Deletion at between position\n";
        cout << "8. Deletion at a random position\n";
        cout << "9. Linked List traversal\n";
        cout << "10. Search node\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_mid();
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
            delete_mid();
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
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
    return 0;
}

void insert_first()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "memory can't be allocated:\n";
    }
    else
    {
        int element;
        cout << "Enter element: ";
        cin >> element;
        ptr->data = element;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;
            ptr->prev = NULL;
            cout << "Element inserted: " << ptr->data << endl;
        }
        else
        {
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
            cout << "Element inserted: " << ptr->data << endl;
        }
    }
}
void insert_last()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "memory can't be allocated:\n";
    }
    else
    {
        int data;
        cout << "Enter element: ";
        cin >> data;
        ptr->data = data;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            cout << "Element inserted: " << ptr->data << endl;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            ptr->next = NULL;
            ptr->prev = temp;
            temp->next = ptr;
            cout << "Element inserted: " << ptr->data << endl;
        }
    }
}
void insert_mid()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "memory can't be allocated:\n";
        return;
    }
    else
    {
        int i = 0, data;
        struct node *temp = head;
        cout << "Enter element: " << endl;
        cin >> data;
        ptr->data = data;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            cout << "Element inserted: " << head->data << endl;
        }
        else if (head->next != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
                i++;
            }
            temp = head;
            int mid = i / 2;
            for (int i = 1; i <= mid; i++)
            {
                temp = temp->next;
            }
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next = ptr;
            temp->next->prev = ptr;
            cout << "Element inserted: " << ptr->data << endl;
        }
        else
        {
            ptr->next = NULL;
            ptr->prev = head;
            head->next = ptr;
            cout << "Element Inserted: " << head->next->data << endl;
        }
    }
}

void insert_random()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cerr << "memory can't be allocated:\n";
        return;
    }
    else
    {
        int position, data;
        cout << "Enter number: " << endl;
        cin >> data;
        ptr->data = data;
        if (head->next == NULL)
        {
            ptr->next = NULL;
            ptr->prev = head;
            head->next = ptr;
        }
        else
        {

            struct node *temp = head;
            cout << "Enter position where do you want to insert:\n";
            cin >> position;
            for (int i = 1; i < position; i++)
            {
                temp = temp->next;
            }

            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next = ptr;
            temp->next->prev = ptr;
            cout << "Element Inserted: " << ptr->data;
        }
    }
}

void delete_first()
{
    if (head == NULL)
    {
        cout << "Doubly linked list is empty: " << endl;
    }
    else if (head->next == NULL)
    {
        cout << "Element deleted: " << head->data << endl;
        free(head);
        head = NULL;
    }
    else
    {
        struct node *ptr = head;
        cout << "Element deleted: " << head->data << endl;
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }
}
void delete_last()
{
    if (head == NULL)
    {
        cout << "Doubly linked list empty:\n";
    }
    else if (head->next == NULL)
    {
        cout << "Element deleted: " << head->data << endl;
        free(head);
        head = NULL;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        cout << "Element deleted: " << ptr->data << endl;
        ptr->prev->next = NULL;
        free(ptr);
    }
}
void delete_mid()
{
    if (head == NULL)
    {
        cerr << "Doubly linked list Empty:\n";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Element deleted successfuly! " << head->data << endl;
        free(head);
        head = NULL;
    }
    else
    {
        int i = 1;
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        int mid = i / 2;
        ptr = head;
        for (i = 1; i <= mid; i++)
        {
            ptr = ptr->next;
        }
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        cout << "Element deleted: " << ptr->data;
        free(ptr);
    }
}
void delete_random()
{
    if (head == NULL)
    {
        cerr << "Doubly linked list empty:" << endl;
    }
    else if (head->next == NULL)
    {
        cout << "Element deleted: " << head->data;
        free(head);
        head = NULL;
    }
    else
    {
        int position, i = 1;
        struct node *ptr = head;
        cout << "Enter position which element do you want to delete: ";
        cin >> position;
        while (ptr->next != NULL && i < position-1)
        {
            ptr = ptr->next;
            i++;
        }

        if (i == position-1)
        {
            ptr = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            cout << "Element deleted: " << ptr->data;
            free(ptr);
        }
        else
        {
            cerr << "Invalid positon: "<< endl;
        }
    }
}
void display()
{
    if (head == NULL)
    {
        cout << "Doubly linked list empty:\n";
    }
    else
    {
        struct node *ptr = head;
        cout << "Element are:\n";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}
void search()
{
    if (head == NULL)
    {
        cerr << "Doubly linked list empty:\n";
    }
    else
    {
        struct node *ptr = head;
        int data, i = 1;
        cout << "Enter element which you want to find: ";
        cin >> data;
        bool flag = false;
        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                flag = true;
                break;
            }
            ptr = ptr->next;
            i++;
        }
        if (!flag)
        {
            cout << "Element not found:" << endl;
        }
        else
        {
            cout << "Element found at position: " << i << endl;
        }
    }
}
