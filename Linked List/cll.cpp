#include <iostream>
using namespace std;

struct CLLNode
{
    int data;
    CLLNode *next;

    CLLNode() : next(nullptr) {}
    CLLNode(int data) : next(nullptr), data(data) {}
};

class CLL
{
public:
    CLLNode *head;
    CLL() : head(nullptr) {}
    void addAtHead(int data);
    void addAtEnd(int data);
    void deleteHead();
    void deleteTail();
    void deleteElement(int data);
    int getLength();
    void printList();
};

void CLL::addAtHead(int data)
{
    CLLNode *newNode = new CLLNode(data);

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }

    else
    {
        // traverse the list to find the last element
        CLLNode *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void CLL::addAtEnd(int data)
{
    CLLNode *newNode = new CLLNode(data);

    // if the list is empty
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        CLLNode *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);

        CLLNode *newNode = new CLLNode(data);
        temp->next = newNode;
        newNode->next = head;
    }
}

void CLL::deleteElement(int data)
{
    CLLNode *temp = head, *prev;
    do
    {
        prev = temp;
        temp = temp->next;
    } while (temp->data != data && temp != head);

    if (temp == head)
    {
        cout << "given data " << data << " do not exists\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    temp = nullptr;
}

int CLL::getLength()
{
    CLLNode *temp = head;
    int count = 0;
    do
    {
        temp = temp->next;
        count++;
    } while (temp != head);

    return count;
}
void CLL::printList()
{
    CLLNode *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << '\n';
}

int main()
{
    CLL cll;
    cll.addAtHead(11);
    cll.addAtHead(10);
    cll.addAtHead(30);
    cll.addAtHead(0);
    cll.printList();
    cll.addAtHead(20);
    cll.addAtEnd(91);
    cll.printList();
    cll.deleteElement(91);
    cll.printList();
    return 0;
}
