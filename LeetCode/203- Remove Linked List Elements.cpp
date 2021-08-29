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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = ListNode();
        start = head;
        
        while(start != NULL && start->val==val){
            start = start->next;
        }
        
        ListNode* prev;
        
        prev = start;
        
        ListNode* itr;
        
        itr = start;
        
        while(itr != NULL){
            if(itr->val == val){
                prev -> next = itr -> next;
                itr = itr -> next;
                continue;
            }
            prev = itr;
            itr = itr -> next;
        }
        return start;


        ///Better solution
        if(head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return val==head->val?head->next:head;
    }
};