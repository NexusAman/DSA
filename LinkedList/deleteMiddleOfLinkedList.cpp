#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *convertArrToLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void printList(ListNode *head)
{
    ListNode *temp = head;

    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
// Brute force approach
ListNode *deleteMiddle(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    int midPrevNode = cnt / 2;

    temp = head;

    while (temp)
    {
        midPrevNode--;
        if (midPrevNode == 0)
        {
            break;
        }
        temp = temp->next;
    }

    ListNode *deleteNode = temp->next;
    temp->next = deleteNode->next;
    deleteNode->next = nullptr;
    delete deleteNode;
    return head;
}
*/

ListNode *deleteMiddle(ListNode *head){
    if(head == nullptr || head->next == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    fast = fast->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* middle = slow->next;
    slow->next = middle->next;
    delete middle;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // deleting the middle of the linked list
    head = deleteMiddle(head);
    printList(head);
    return 0;
}