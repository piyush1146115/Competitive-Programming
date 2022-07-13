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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    
    return partition(lists, 0, lists.size() - 1);
}

ListNode* partition(vector<ListNode*> &lists, int st, int en){
    if(st == en)
        return lists[st];
    if(st < en){
        int mid = st + (en-st)/2;
        
        ListNode* p1 = partition(lists, st, mid);
        ListNode* p2 = partition(lists, mid+1, en);
        
        return mergeTwoLists(p1, p2);
    }else{
        return NULL;
    }
    
}
    
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
};