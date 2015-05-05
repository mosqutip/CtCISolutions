#include "ChapterDeclarations.hpp"

namespace CtCISolutions
{
    void RemoveDuplicates(Node* head)
    {
        if (head == nullptr)
        {
            return;
        }

        Node* current = head;
        while (current != nullptr)
        {
            Node* runner = current;
            while (runner->next != nullptr)
            {
                if (runner->next->data == current->data)
                {
                    Node* tmp = runner->next;
                    runner->next = tmp->next;
                    delete(tmp);
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    Node* FindNthToLastNode(Node* head, int n)
    {
        Node *current = head, *runner = head;

        while (n > 0)
        {
            if (runner->next == nullptr)
            {
                return nullptr;
            }

            runner = runner->next;
            --n;
        }

        while (runner != nullptr)
        {
            runner = runner->next;
            current = current->next;
        }

        return current;
    }

    void DeleteNode(Node* node)
    {
        Node* tmp = node->next;
        node->data = tmp->data;
        node->next = tmp->next;
        delete(tmp);
    }

    bool IsLinkedListPalindrome(Node* head)
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *slow = head, *fast = head;
        vector<int> stack;

        while (fast != nullptr && fast->next != nullptr)
        {
            stack.push_back(slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }

        if ((stack.size() % 2) != 0)
        {
            slow = slow->next;
        }

        while (slow != nullptr)
        {
            if (slow->data != stack.back())
            {
                return false;
            }

            slow = slow->next;
            stack.pop_back();
        }

        return true;
    }

    Node* SumLinkedListDigitsForward(Node* first_list, Node* second_list)
    {
        int carry = 0, current_sum;
        Node *sum = nullptr, *head = nullptr;

        while ((first_list != nullptr) || (second_list != nullptr))
        {
            if (sum == nullptr)
            {
                sum = new Node();
                head = sum;
            }
            else
            {
                sum->next = new Node();
                sum = sum->next;
            }

            if (first_list == nullptr)
            {
                current_sum = (second_list->data + carry);
                second_list = second_list->next;
            }
            else if (second_list == nullptr)
            {
                current_sum = (first_list->data + carry);
                first_list = first_list->next;
            }
            else
            {
                current_sum = ((first_list->data + second_list->data) + carry);
                first_list = first_list->next;
                second_list = second_list->next;
            }

            if (current_sum >= 10)
            {
                carry = (current_sum / 10);
                current_sum %= 10;
            }
            else
            {
                carry = 0;
            }

            sum->data = current_sum;
        }

        if (carry != 0)
        {
            sum->next = new Node();
            sum = sum->next;
            sum->data = carry;
        }

        return head;
    }

    Node* CreateLinkedList()
    {
        Node* head = new Node();
        Node* current = head;
        current->data = 3;
        current->next = new Node();
        current = current->next;

        current->data = 7;
        current->next = new Node();
        current = current->next;

        current->data = 3;
        current->next = new Node();
        current = current->next;

        current->data = 1;
        current->next = new Node();
        current = current->next;

        current->data = 3;
        current->next = new Node();
        current = current->next;

        current->data = 7;
        current->next = new Node();
        current = current->next;

        current->data = 3;
        current->next = nullptr;

        return head;
    }

    void PrintLinkedList(Node* head)
    {
        while (head != nullptr)
        {
            cout << head->data;
            if (head->next != nullptr)
            {
                cout << "->";
            }
            head = head->next;
        }
    }

    void RemoveDuplicatesTest()
    {
        Node* head = CreateLinkedList();
        cout << "Removing duplicates from linked list: ";
        PrintLinkedList(head);
        cout << " yields linked list: ";
        RemoveDuplicates(head);
        PrintLinkedList(head);
        cout << endl;
    }

    void FindNthToLastNodeTest()
    {
        Node* head = CreateLinkedList();
        int n = 4;
        Node* node_n = FindNthToLastNode(head, n);
        if (node_n == nullptr)
        {
            cout << "N is too large for the linked list!" << endl;
        }
        else
        {
            cout << "The element " << n << " elements before the end of the linked list: ";
            PrintLinkedList(head);
            cout << " is: " << node_n->data << endl;
        }
    }

    void DeleteNodeTest()
    {
        Node* head = CreateLinkedList();
        Node* delete_node = head->next->next->next->next;

        cout << "Deleting node 5 from linked list: ";
        PrintLinkedList(head);
        cout << " yields: ";
        DeleteNode(delete_node);
        PrintLinkedList(head);
        cout << endl;
    }

    void SumLinkedListDigitsTest()
    {
        Node* first_head = CreateLinkedList();
        Node* second_head = CreateLinkedList();

        //DeleteNode(second_head->next->next->next);
        //DeleteNode(second_head->next);

        cout << "The sum of the digits in linked lists: ";
        PrintLinkedList(first_head);
        cout << " and: ";
        PrintLinkedList(second_head);
        cout << " is: ";
        Node* sum_head = SumLinkedListDigitsForward(first_head, second_head);
        PrintLinkedList(sum_head);
        cout << endl;
    }

    void IsLinkedListPalindromeTest()
    {
        Node* head = CreateLinkedList();

        cout << "Is the linked list: ";
        PrintLinkedList(head);
        cout << " a palindrome? " << (IsLinkedListPalindrome(head) ? "True" : "False") << endl;
    }
};