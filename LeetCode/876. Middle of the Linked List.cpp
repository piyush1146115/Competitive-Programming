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
       ListNode* fast;
       ListNode* slow;
        
        fast = head;
        slow = head;
        
        if(slow -> next == NULL)
            return slow;
        
        while(fast -> next != NULL && slow != NULL){
            slow = slow -> next;
        
            if(fast -> next -> next == NULL){
                fast = fast -> next;
            }
            else{
                fast = fast -> next -> next;
            }
        }
        return slow;
    }
};