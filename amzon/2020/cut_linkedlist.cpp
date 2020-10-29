/*Given a linked list cut the linked list at particular position and join it in the beginning of linked list.

in : 1-2-3-4-5-6-7-8
     3

out: 4-5-6-7-8-1-2-3

*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
Node * getNewList(Node *head,int cutpoint)
{
    if(head==NULL)
        return head;
    
    Node *lastNodePtr = NULL;
    Node *tra= head;
    Node *cutNode;
    int cnt=1;

    while(tra->next!=NULL)
    {
        if(cnt == cutpoint)
        {
            cutNode = tra;
        }
        tra=tra->next;
        cnt++;
    }

    //corner case
    if(cnt == cutpoint)
        return head;

    lastNodePtr = tra;
    Node *newhead = cutNode->next;
    cutNode->next = NULL;
    lastNodePtr->next = head;
    return newhead;
}