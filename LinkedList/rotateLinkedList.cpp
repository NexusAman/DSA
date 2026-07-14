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

ListNode *findNthNode(ListNode *head, int n)
{
    ListNode *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        if (cnt == n)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || k == 0)
        return head;

    int length = 1;
    ListNode *tail = head;

    while (tail->next != nullptr)
    {
        length++;
        tail = tail->next;
    }

    if (k % length == 0)
        return head;

    k = k % length;

    tail->next = head;

    ListNode *newLastNode = findNthNode(head, length - k);
    head = newLastNode->next;
    newLastNode->next = nullptr;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // rotate linked list
    int k = 2;
    head = rotateRight(head, k);
    printList(head);

    return 0;
}