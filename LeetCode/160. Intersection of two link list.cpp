/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> S;
        
        while(headA != NULL){
            S.insert(headA);
            headA = headA -> next;
        }
        
        while(headB != NULL){
            if(S.find(headB) != S.end()){
                return headB;
            }
            
            headB = headB -> next;
        }
        
        return headB;
    }
};