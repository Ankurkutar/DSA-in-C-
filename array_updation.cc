#include <iostream>
using namespace std;

void show(int[], int);
void insert_first(int[], int, int&);
void insert_last(int[],int, int&);
void insert_mid(int[], int , int&);
void insert_random(int[], int,int&);

int main()
{
    int size;
    cout << "*****************Welcome*******************\n";
    cout << "Enter size of array: \n";
    cin >> size;
    int arr[size] = {10, 20, 30, 40};
    int choice, ind = 4;
    while (1)
    {
        cout << "\nPlease chooce one of these option:\n\n";
        cout << "1.insert first()\n";
        cout << "2.insert last()\n";
        cout << "3.insert mid()\n";
        cout << "4.insert random()\n";
        cout << "5.show()\n";
        cout << "6.insert exit(0)\n";
        cout << "Enter your choice: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert_first(arr, size, ind);
            break;
        case 2:
            insert_last(arr,size ,ind);
            break;
        case 3:
            insert_mid(arr, size , ind);
            break;
        case 4:
            insert_random(arr, size,ind);
            break;
        case 5:
            show(arr, ind);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Oops you entered wrong choice: \n";
            break;
        }
    }
    return 0;
}

void show(int arr[], int ind)
{
    cout << "Element of array:\n";
    for (int i = 0; i <= ind-1; i++)
    {
        cout << arr[i] << " ";
    }
}

void insert_first(int arr[], int size, int &ind)
{
    if (ind == size)
    {
        cout << "array full:\n";
    }
    else
    {
        int num;
        cout << "Enter element: ";
        cin >> num;
        for (int i = ind; i >= 0; i--)
        {
            // cout<<arr[i]<<" ";
            arr[i+1] = arr[i];
        }
        arr[0] = num;
        ind++;
        cout<<"Element Inserted: "<<arr[0];
    }
}

void insert_last(int arr[],int size, int &ind){
    if(ind == size){
        cout<<"Array Full!:";
    }else{
        int num;
        cout<<"Enter element: ";
        cin>>num;
        arr[ind] = num;
        cout<<"Element Inserted successfully! "<<arr[ind]<<"\n";
        ++ind;
       
    }
}

void insert_mid(int arr[], int size, int &ind){
    if(ind == size){
        cout<<"Array full!\n";
    }else{
        int num;
        cout<<"Enter number: ";
        cin>>num;
        int mid = ind/2;
        for(int i=ind; i>=mid; i--){
            arr[i+1] = arr[i];
        }
        arr[mid] = num;
        cout<<"Element Inserted: "<<arr[mid];
        ++ind;
    }
}

void insert_random(int arr[], int size,int &ind){
    if(ind == size){
        cout<<"Array full!\n";
    }else{
        int num,position;
        cout<<"Enter position where want to insert: ";
        cin>>position;
        cout<<"Enter element: ";
        cin>>num;
        for(int i=ind; i>=position; i--){
            arr[i+1] = arr[i];
        }
        arr[position] = num;
        cout<<"Element inserted: "<<arr[position];
        ++ind;
    }
}