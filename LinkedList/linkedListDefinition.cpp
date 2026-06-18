#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

ListNode *convertArrToLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int lengthOfLL(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;

    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool checkIfPresent(ListNode *head, int val)
{
    ListNode *temp = head;

    while (temp)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    // ListNode *node = new ListNode(10);
    vector<int> arr = {10, 20, 30, 40};

    // Array to LL conversion
    ListNode *head = convertArrToLL(arr);
    ListNode *temp = head;

    // Length of LL
    int lengthLL = lengthOfLL(head);
    cout << "Length of linkedlist : " << lengthLL << endl;

    // Search element in LL
    int val = 40;
    bool isExist = checkIfPresent(head, val);
    if (isExist)
    {
        cout << "Element exist in the LL" << endl;
    }
    else
    {
        cout << "Element doesn't exist in the LL" << endl;
    }

    // Print list (traverse)
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}