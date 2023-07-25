/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //Recursive Way
    ListNode* reverse(ListNode* head){
        if(head->next==NULL) return head;
        ListNode* newNode=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newNode;
    }
    ListNode* reverseList(ListNode* head) {
        //Iterative Way
        /*
        ListNode* newHead=NULL;
        while(head!=NULL){
            ListNode* next=head->next;
            head->next=newHead;
            newHead=head;
            head=next;
        }
        return newHead;
        */
        
        //Recursive Way
        if(head==NULL) return NULL;
        return reverse(head);
    }
};