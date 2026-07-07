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

ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
/*
// Brute force approach
ListNode *addOne(ListNode *head)
{
    head = reverseList(head);
    ListNode* temp = head;
    int carry = 1;

    while(temp){
        temp->val = temp->val + carry;
        if(temp->val < 10){
            carry = 0;
            break;
        }else{
            temp->val = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    head = reverseList(head);
    if(carry == 1){
        ListNode* newNode = new ListNode(carry);
        newNode->next = head;
        return newNode;
    }
    return head;
}
*/
int helper(ListNode* temp){
    if(temp == nullptr) return 1;

    int carry = helper(temp->next);
    temp->val = temp->val + carry;

    if(temp->val < 10){
        return 0;
    }
    temp->val = 0;
    return 1;
}

ListNode *addOne(ListNode *head){
    int carry = helper(head);

    if(carry == 1){
        ListNode* newHead = new ListNode(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}

int main()
{
    vector<int> arr = {4, 5, 6};
    ListNode *head = convertArrToLL(arr);
    printList(head);

    // adding 1 to the LL number
    head = addOne(head);
    printList(head);

    return 0;
}