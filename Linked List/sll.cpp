#include <iostream>
using namespace std;

// Node structure for the linked list
struct ListNode
{
    int data;
    ListNode *next;

    ListNode() : next(nullptr) {}
    ListNode(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class
class SLL
{
public:
    ListNode *head; // Head pointer for the list
    SLL() : head(nullptr) {}
    void addAtHead(int data);
    void addAtTail(int data);
    void deleteElement(int data);
    void addElementAtIndex(int data, int index);
    int getLength();
    void reverseList();
    void deleteList();
    void printList();
};

// Add a node with the given data at the head of the list
void SLL::addAtHead(int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Add a node with the given data at the tail of the list
void SLL::addAtTail(int data)
{
    ListNode *lastNode = head;
    ListNode *newTail = new ListNode(data);

    if (head == nullptr)
    {
        head = newTail;
        return;
    }

    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newTail;
}

// deleteElement the first occurrence of a node with the given data
void SLL::deleteElement(int data)
{
    ListNode *currNode = head, *prevNode;

    // If head node holds the data to be deleted
    if (currNode != nullptr && currNode->data == data)
    {
        head = head->next;
        delete currNode;
        currNode = nullptr;
        return;
    }

    // Search for the node to be deleted
    while (currNode != nullptr && currNode->data != data)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If the given data does not exist
    if (currNode == nullptr)
    {
        cerr << "error(deleteElement): " << data << " does not exist in the list\n";
        return;
    }

    // Unlink the node from the list
    prevNode->next = currNode->next;
    delete currNode;
    currNode = nullptr;
}

// Add a node with the given data at the specified index
void SLL::addElementAtIndex(int data, int index)
{
    ListNode *newNode = new ListNode(data);
    if (index == 0)
    {
        // Inserting at index 0
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode *curr = head, *prev;
    int count = 0;
    while (curr != nullptr && count < index)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If index is greater than the length of the list
    if (curr == nullptr && count != index)
    {
        cerr << "error(addElementAtIndex): index " << index << " is out of range\n";
        delete newNode;
        return;
    }

    prev->next = newNode;
    newNode->next = curr;
}

// Get the length of the list
int SLL::getLength()
{
    ListNode *node = head;
    int length = 0;
    while (node != nullptr)
    {
        length++;
        node = node->next;
    }
    return length;
}

void SLL::reverseList()
{
    // if list has only one elment
    if (SLL::getLength() == 1)
    {
        return;
    }

    ListNode *prev = head, *curr = prev->next, *next = curr->next;
    // if list has only two elements
    if (SLL::getLength() == 2)
    {
        curr->next = prev;
        head->next = nullptr;
        head = curr;
        return;
    }
    // If list has more than two elements
    while (next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    head->next = nullptr;
    head = curr;
}

// Delete the entire list
void SLL::deleteList()
{
    ListNode *curr = head, *temp;
    while (curr != nullptr)
    {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
}

// Print the entire list
void SLL::printList()
{
    ListNode *temp = head;
    if (temp == nullptr)
    {
        cerr << "linked list is empty\n";
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

// main function
int main()
{
    SLL sll;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sll.addAtTail(temp);
    }

    sll.printList();
    sll.reverseList();
    sll.printList();
    return 0;
}
