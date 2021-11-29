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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int sz = 0;
        
//         ListNode* temp = head;
        
//         while(temp != NULL){
//             temp = temp->next;
//             sz++;
//         }
        
//         int target = sz - n;
//         sz = 0;
        
        
//         if(target == 0){
//             head = head->next;
//         }
//         temp = head;
//         // cout << target << " " << sz << endl;
//         while(temp != NULL){
//             sz++;
//             if(sz == target){
//                 temp->next = temp->next->next;
//                 break;
//             }
//             temp= temp->next;
//         }
        
//         return head;
        
        ListNode* start = new ListNode(0);
        start->next = head;
        
        ListNode* fast;
        ListNode* slow;
        
        
        slow = start;
        fast = start;
        
        
        for(int i = 1; i <= n +1 ; i++)
            fast = fast->next;
        
        
        
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next=slow->next->next;
        
        return start->next;
    }
    
};