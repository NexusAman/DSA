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
bool hasCycle(ListNode *head)
{
    ListNode *temp = head;
    unordered_map<ListNode *, int> mpp;

    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }
        mpp[temp]++;
        temp = temp->next;
    }
    return false;
}
*/

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {4, 5, 6};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // adding 1 to the LL number
    cout << hasCycle(head);

    return 0;
}