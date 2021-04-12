/*
ARRAY BASED LIST
*/
#include<iostream>
using namespace std;
class Array_data_list
{
public:
    int* arr;//will be used to initialize an empty list and will always point to the first position.
    int size;//total capcity of the list
    int current; //pointer to point the current position
    //int length; //number of current elements in the list
     //Constructor for initializing List
    //You can initialize size to any value
    Array_data_list()  //Default Constructor
    {
        cout << " Your List size \n";
        cin >> size;
        current = -1;
        arr = new int[size]; //Dynamic Memory Allocation
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }
    Array_data_list(int S, int C, int* a) //parametric constructor
    {
        size = S;
        current = C;
        arr = a;
    }
    //Deep Copy Constructor
   //write code to create a new list and copy elements of the list passed in the parameter
    Array_data_list(const Array_data_list& A) //Copy constructor
    {
        cout << "Copy constructor" << endl;
        size = A.size;
        current = A.current;
        arr = A.arr;
    }
    //Checking the limit of list
    bool check()
    {
        if (current == size - 1)
        {
            char option;
            cout << " The limit size reached \n";
            cout << " If you want to increase the limit press 'y' or otherwise press 'n' \n";
            cin >> option;
            if (option == 'y')
            {
                size++;
            }
            else
                return false;
        }
        else
            return true;
    }
    //Insert the given value in the list at the next available position
    void add()
    {
        int data;
        if (current == -1)
        {

            cout << "Enter the value = \n ";
            cin >> data;
            current++;
            arr[current] = data;
        }
        else
        {
            if (check())
            {
                cout << "Enter the value for the Array Data list = \n ";
                cin >> data;
                current++;
                arr[current] = data;
            }
        }
    }
    //Update Existing value at a position
    void update()
    {
        int data;
        cout << "Enter the value you want to update with the existing value of array list \n ";
        cin >> data;
        arr[current] = data;
    }
    //Get value stored at a specific position
    int get()
    {
        int foo;
        foo = arr[current];
        return foo;
    }
    //Remove a value at specific position
    int remove()
    {
        int foo;
        foo = arr[current];
        arr[current] = -1;
        return foo;
    }
    //Return Current Length of the list
    int length()
    {
        return size;
    }
    // to starting position of the list
    void start()
    {
        current = 0;
    }
    //Move to the end of the list
    void end()
    {
        current = size - 1;
    }
    // For backwards in the list
    void back()
    {
        if (current != 0)
        {
            current--;
        }
    }
    // For towards next in the list
    void next()
    {
        if (current != size - 1)
        {
            current++;
        }
    }
    //checks whether the list is completely empty or not   
    bool isempty()
    {
        int i;
        if (arr[i] = -1)
        {
            if (i == 0)
            {
                cout << " List is not  empty\n";

            }
            else
            {
                cout << "  empty \n";
            }
        }
    }
    //checks whehter the list is completely filled or not
    bool isfull()
    {
        if (current >= size)
        {
            cout << " List is full \n";
        }
        else
        {
            cout << " Your have enough space for input the elements \n";
        }
    }
    //Display the list 
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                if (i == 0)
                    cout << "List is Empty\n";
                break;
            }
            else
                cout << i + 1 << ". " << arr[i] << endl;
        }
    }
    void choices()
    {
        int press;
        do
        {
            cout << " Choose your option given below and press key \n";
            cout << "1 = For length \n";
            cout << "2 = For Get Current value of  Array data List\n";
            cout << "3 = For Move Next\n";
            cout << "4 = For Move Back\n";
            cout << "5 = For Move to the Start\n";
            cout << "6 = For Move to the End\n";
            cout << "7 = For Add a value\n";
            cout << "8 = For Remove a Value\n";
            cout << "9 = For Update a Value\n";
            cout << "10 = For Display List\n";
            cout << "11 = For check the is empty or not ?? \n";
            cout << "12 = For check the is full or not ?? \n";
            cout << "13 = 13 For QUIT !!!! \n";
            cin >> press;
            if (press == 1)
            {
                cout << "Current List Length is: " << length() << endl;
            }
            if (press == 2)
            {
                cout << "Value is : " << get() << endl;
            }
            if (press == 3)
            {
                next();
            }
            if (press == 4)
            {
                back();
            }
            if (press == 5)
            {
                start();
            }
            if (press == 6)
            {
                end();
            }
            if (press == 7)
            {
                add();
            }
            if (press == 8)
            {
                cout << "Removed Value is: " << remove() << endl;
            }
            if (press == 9)
            {
                update();
            }
            if (press == 10)
            {
                display();
            }
            if (press == 11)
            {
                isempty();
            }
            if (press == 12)
            {
                isfull();
            }
        } while (press != 13);
    }
};
int main()
{
    Array_data_list A;//, A2;
    A.choices();
    Array_data_list A2(A);
    A.display();
    A2.display();
    system("pause");
    return 0;
}