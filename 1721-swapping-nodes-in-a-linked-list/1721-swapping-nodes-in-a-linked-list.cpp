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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        while (k>1){
            fast=fast->next;
            k--;
        }
        ListNode* temp=fast;
        while (fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        int aux=0;
        aux=temp->val;
        temp->val=slow->val;
        slow->val=aux;
        return head;
        
    }
};