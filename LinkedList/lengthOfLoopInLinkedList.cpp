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

int lengthOfLoop(ListNode *head)
{
    unordered_map<ListNode *, int> mpp;
    int timer = 1;

    ListNode *temp = head;

    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            int value = mpp[temp];
            return (timer - value);
        }

        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> arr = {4, 5, 6};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // finding the length of the loop in linked list
    cout << lengthOfLoop(head);
    return 0;
}