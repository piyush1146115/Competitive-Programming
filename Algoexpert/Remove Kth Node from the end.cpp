#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  // Write your code here.
	
	LinkedList *fast = head;
	
	while(k--){
		fast = fast->next;
	}
	
	if(fast == NULL){
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	
	LinkedList* slow = head;
	
	while(fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	
	slow->next = slow->next->next;
	
}
