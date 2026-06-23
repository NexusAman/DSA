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
/*
// Brute force approach
ListNode *reverseDLL(ListNode *head)
{
    ListNode *temp = head;
    stack<int> st;

    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
*/

ListNode *reverseDLL(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *current = head;
    ListNode *last = nullptr;

    while (current)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40};

    // Array to DLL conversion
    ListNode *head = convertArrToDLL(arr);
    printList(head);

    // reversing the DLL
    head = reverseDLL(head);
    printList(head);
    return 0;
}