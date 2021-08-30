#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == NULL || head2 == NULL){
        if(head1 == NULL)
            return head2;
        else {
            return head1;
        }
    }
    
    SinglyLinkedListNode* start;
    
    if(head1->data < head2->data){
        start = head1;
        head1 = head1->next;    
    }
    else{
        start = head2;
        head2 = head2->next;
    }
    
    SinglyLinkedListNode* ptr;
    ptr = start;
    
    while (head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data){
            start->next = head1;
            head1 = head1->next;
            start = start->next;
        }    
        else{
            start->next=head2;
            head2 = head2->next;
            start = start->next;
        }
    }
    
    if(head2 == NULL){
        start->next = head1;
    }
    else{
        start->next = head2;
    }
return ptr;
}

int main()