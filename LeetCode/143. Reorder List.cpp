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
    void reorderList(ListNode* head) {
        
        // Find middle element
        
        ListNode* slow;
        ListNode* fast;
        
        slow = head;
        fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow  = slow->next;
        }
        
        
        // cout << fast->val << " " << slow->val << endl;
        
        //reverse the last part
        ListNode* prev;
        ListNode* cur;
        ListNode* tmp;
        
        prev = NULL;
        cur = slow;
        
        while(cur != NULL){
            tmp = cur->next;
            
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        
        
        //merge the first part and last part
        ListNode* first;
        ListNode* second;
        
        first = head;
        second = prev;
        
        while(second->next != NULL){
            tmp = first->next;
            first->next=second;
            first = tmp;
            
            tmp=second->next;
            second->next=first;
            second=tmp;
        }
        
    }
};