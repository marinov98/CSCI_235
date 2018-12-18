#include <iostream>
#include <deque>
#include <stack>

// Single linked list
class SingleLinkedList
{
  public:
    int data;
    SingleLinkedList *next;

    SingleLinkedList(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

// Print linked list
void printLinkedList(SingleLinkedList *head)
{
    //// Recursive
    std::cout << head->data << '\n';

    if (head->next)
        printLinkedList(head->next);

    //// Iterative
    auto *temp = head;
    while (temp)
    {
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
}

// Print in reverse
void reversePrint(SingleLinkedList *head)
{
    //// Recursive
    if (head->next)
        reversePrint(head->next);

    std::cout << head->data << '\n';

    //// deque
    std::deque<int> ldek;

    auto *temp = head;

    while (temp)
    {
        ldek.push_front(temp->data);
        temp = temp->next;
    }

    while (!ldek.empty())
    {
        std::cout << ldek.front() << '\n';
        ldek.pop_front();
    }

    // Deque with for loops

    for (auto *current = head; current != 0; current = current->next)
        ldek.push_front(current->data);

    for (const auto &x : ldek)
        std::cout << x << '\n';

    //// Stack
    std::stack<int> lstack;

    auto *iterator = head;

    while (iterator)
    {
        lstack.push(iterator->data);
        iterator = iterator->next;
    }

    while (!lstack.empty())
    {
        std::cout << lstack.top() << '\n';
        lstack.pop();
    }
}

//// Insertion

// Inserting at the end
SingleLinkedList *insertNodeAtTail(SingleLinkedList *head, int data)
{
    auto *new_node = new SingleLinkedList(data);

    auto *temp = head;

    if (!head)
    {
        head = new_node;
    }
    else
    {
        // Go to end (NOT necessary if you have tail pointer!)
        while (temp->next)
        {
            temp = temp->next;
        }

        // Add node
        temp->next = new_node;
    }

    return head;
}

// Inserting at the beginning
SingleLinkedList *insertNodeAtHead(SingleLinkedList *head, int data)
{
    auto *new_node = new SingleLinkedList(data);

    if (!head)
        head = new_node;
    else
    {
        auto *hold = head;
        head = new_node;
        head->next = hold;
    }

    return head;
}

// Inserting at specific location
SingleLinkedList *insertNodeAtPosition(SingleLinkedList *head, int data, int position)
{

    auto curr = head;
    auto prev = head;
    int counter = 0;

    if (position < 0)
    {
        return head;
    }
    else
    { // transverse list untill the specified position is found
        while (curr->next && counter < position)
        {
            prev = curr;
            curr = curr->next;
            counter++;
        }

        auto to_insert_node = new SingleLinkedList(data);
        prev->next = to_insert_node;
        to_insert_node->next = curr;
    }
    return head;
}

// Deletion
SingleLinkedList *deleteNode(SingleLinkedList *head, int position)
{
    // case 0: nothing to be deleted
    if (!head)
        return head;
    // case 1: deleting the first node
    else if (position == 0)
    {
        auto *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
    // case 2: general case
    else
    {
        int counter = 0;
        auto *curr = head;
        auto *prev = head;
        // Transverse list to the position
        while (curr->next && counter < position)
        {
            prev = curr;
            curr = curr->next;
            counter++;
        }

        auto *hold = curr;
        prev->next = curr->next;
        delete hold;
    }

    return head;
}

// Reverse a linked list
SingleLinkedList *reverse(SingleLinkedList *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    auto *nodes = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return nodes;
}

// Compare two linked list
bool compare_lists(SingleLinkedList *head1, SingleLinkedList *head2)
{
    bool result = true;

    while (head1 && head2)
    {
        if ((head1->next != nullptr && head2->next == nullptr) ||
            (head1->next == nullptr && head2->next != nullptr) ||
            (head1->data != head2->data))
        {
            result = false;
            break;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return result;
}

//// Doubly-Linked list
struct DoubleLinkedList
{
    int data;
    DoubleLinkedList *next;
    DoubleLinkedList *prev;

    DoubleLinkedList(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

DoubleLinkedList *sortedInsert(DoubleLinkedList *head, int data)
{
    auto *to_insert_node = new DoubleLinkedList(data);

    if (!head)
    {
        head = to_insert_node;
        return head;
    }

    auto *temp = head;

    while (temp->next && temp->data <= to_insert_node->data)
        temp = temp->next;

    if (head->data >= to_insert_node->data)
    {
        to_insert_node->next = temp;
        to_insert_node->prev = temp->prev;
        temp->prev = to_insert_node;
        head = to_insert_node;
    }
    else if (temp->data >= to_insert_node->data)
    {
        temp = temp->prev;
        to_insert_node->next = temp->next;
        to_insert_node->prev = temp;
        temp->next = to_insert_node;
    }
    else
    {
        to_insert_node->next = temp->next;
        to_insert_node->prev = temp;
        temp->next = to_insert_node;
    }

    return head;
}
