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

ListNode *addHeadKthElement(ListNode *headA, int k)
{
    ListNode *temp = headA;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }

    ListNode *headB = new ListNode(3);
    headB->next = temp;
    return headB;
}

/*
// Brute force approach
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA;
    ListNode *tempB = headB;

    unordered_map<ListNode *, int> mpp;

    while (tempA)
    {
        mpp[tempA]++;
        tempA = tempA->next;
    }

    while (tempB)
    {
        if (mpp.find(tempB) != mpp.end())
        {
            return tempB;
        }
        tempB = tempB->next;
    }
    return nullptr;
}
*/

/*
// Better approach
ListNode *collisionPoint(ListNode *smallerHead, ListNode *largeHead, int diff)
{
    // iterating largehead to similar point
    while (diff)
    {
        diff--;
        largeHead = largeHead->next;
    }

    // now iterating together if they are same or not
    while (smallerHead != largeHead)
    {
        smallerHead = smallerHead->next;
        largeHead = largeHead->next;
    }
    return smallerHead;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA;
    ListNode *t2 = headB;
    int N1 = 0, N2 = 0;

    // finding the length of the linked list
    while (t1)
    {
        N1++;
        t1 = t1->next;
    }

    while (t2)
    {
        N2++;
        t2 = t2->next;
    }

    if (N1 < N2)
    {
        return collisionPoint(headA, headB, N2 - N1);
    }
    else
    {
        return collisionPoint(headB, headA, N1 - N2);
    }
    return nullptr;
}
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *t1 = headA;
    ListNode *t2 = headB;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
            return t1;

        if (t1 == nullptr)
            t1 = headB;
        if (t2 == nullptr)
            t2 = headA;
    }
    return t1;
}

int main()
{
    vector<int> arr1 = {1, 9, 1, 2, 4};
    ListNode *headA = convertArrToLL(arr1);
    printList(headA);

    ListNode *headB = addHeadKthElement(headA, 4);
    printList(headB);

    ListNode *head = getIntersectionNode(headA, headB);
    cout << head->val;
    return 0;
}