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
    ListNode* middleNode(ListNode* head) {
        //0(n)+0(n/2)
        /*
        int n=0;
        ListNode *temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int half=n/2;
        temp=head;
        while(half--){
            temp=temp->next;
        }
        return temp;
        */
        
        //TortoiseHare Method
        //0(n/2);
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};