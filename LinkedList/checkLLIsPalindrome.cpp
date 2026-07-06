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
bool isPalindrome(ListNode *head)
{
    ListNode *temp = head;
    stack<int> st;
    while (temp)
    {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        if (st.top() != temp->val)
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}
*/

ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = nullptr;

    while (temp)
    {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *newHead = reverseList(slow->next);
    ListNode *first = head;
    ListNode *second = newHead;

    while (second != nullptr)
    {
        if (first->val != second->val)
        {
            reverseList(slow->next);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseList(slow->next);
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // check if LL is Palindrome or not
    cout << isPalindrome(head);
    return 0;
}