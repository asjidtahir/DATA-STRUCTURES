#include <iostream>
using namespace std;
struct LinkList
{
    int data;
    LinkList* next;
};
void sortedInsert(struct LinkList** head, int element)
{
    LinkList* temp = *head;
    LinkList* t = new LinkList;
    if (*head == NULL)
    {
        *head = new LinkList;
        (*head)->data = element;
        (*head)->next = NULL;
    }

    else
    {

        if (element < temp->data)
        {
            t = new LinkList;
            t->data = element;
            t->next = *head;
            *head = t;
        }

        else
        {
            while (temp->next != NULL and !(element < temp->next->data && element >= temp->data))
                temp = temp->next;

            if (temp->next == NULL)
            {
                temp->next = new LinkList;
                temp = temp->next;
                temp->data = element;
                temp->next = NULL;
            }
            else
            {
                t = new LinkList;
                t->data = element;
                t->next = temp->next;
                temp->next = t;
            }
        }
    }
}
void display(struct LinkList** head)
{
    struct LinkList* temp = *head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            cout << temp->data << ",";
        }
        else
            cout << temp->data;
        temp = temp->next; //move to next node
    }
    //O(number of nodes)
    cout << endl;
}
int main()
{

    struct LinkList* head = NULL;
    cout << " ===========SORTED LINKLIST IN ASCENDING ORDER=============\n";
    cout << "\n Your Current List is :-\n";
    display(&head);
    sortedInsert(&head, 4);
    cout << "\n Your Current List is :-\n";
    display(&head);
    sortedInsert(&head, 20);
    cout << "\n Your Current List is :-\n";
    display(&head);
    sortedInsert(&head, 11);
    cout << "\n Your Current List is :-\n";
    display(&head);
    sortedInsert(&head, 52);
    cout << "\n Your Current List is :-\n";
    display(&head);
    sortedInsert(&head, 3);
    cout << "\n Your Current List is :-\n";
    display(&head);
    sortedInsert(&head, 21);
    cout << "\n Your Current List is :-\n";
    display(&head);
    return 0;
}