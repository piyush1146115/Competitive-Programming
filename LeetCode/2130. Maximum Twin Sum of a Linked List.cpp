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
    void reverse(ListNode **head){
        ListNode *prev, *cur, *nxt;
        prev = NULL;
        cur = *head;
        
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        *head=prev; 
    }
    
    int pairSum(ListNode* head) {
        
        ListNode *prev = NULL, *slow = head, *fast = head;
        
        while(fast != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        reverse(&slow);
        
        ListNode *ptr1 = head, *ptr2 = slow;
        
        int maxSum = 0;
        
        while(ptr1 != NULL && ptr2 != NULL){
            maxSum = max(maxSum, ptr1->val + ptr2->val);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return maxSum;
    }
};