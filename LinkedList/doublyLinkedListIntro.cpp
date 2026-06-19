#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *back;

    ListNode(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

ListNode *convertArrToDLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printList(ListNode *head)
{
    ListNode *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};

    // Array to DLL conversion
    ListNode *head = convertArrToDLL(arr);
    printList(head);
    return 0;
}