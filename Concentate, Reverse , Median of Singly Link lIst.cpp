#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class linked_list
{
private:
    node* head, * tail, * current, * prev, * next;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
        prev = NULL;

    }

    void add_node(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    static void display(node* head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }
    //Part no 01

    static void concatenate(node* a, node* b)
    {
        if (a != NULL && b != NULL)
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next, b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }
    //Part No 04
    void Reverse()
    {
        node* current = head;
        node* prev = NULL, * next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void Display()
    {
        tail = head;
        cout << "The Doubly linked list is :: ";
        while (tail != 0)
        {
            cout << tail->data << ",";
            tail = tail->next;
        }
        cout << endl;
    }

    //Part no 03
    void push(struct node** head_ref, int new_data)
    {
        node* new_node = new node;
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }

    void printMidean(node* head)
    {
        node* m_ptr = head;
        node* m1_ptr = head;
        node* m2_ptr = head;

        if (head != NULL)
        {
            while (m1_ptr != NULL && m1_ptr->next != NULL)
            {

                m1_ptr = m1_ptr->next->next;
                m2_ptr = m_ptr;
                m_ptr = m_ptr->next;
            }

            if (m1_ptr != NULL)
            {
                cout << "Median is : " << m_ptr->data;
            }

            else
            {
                cout << " The Median Of Link List  is : "
                    << float(m_ptr->data + m2_ptr->data) / 2;
            }

        }
    }

};

int main()
{
    node* head = NULL;
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    linked_list b;
    b.add_node(3);
    b.add_node(4);
    b.add_node(4);
    linked_list::concatenate(a.gethead(), b.gethead());
    linked_list::display(a.gethead());
    a.Reverse();
    a.Display();
    a.push(&head, 1);
    a.push(&head, 2);
    a.push(&head, 3);
    a.push(&head, 4);
    a.push(&head, 4);
    a.printMidean(head);
    return 0;
}