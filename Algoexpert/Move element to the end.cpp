#include <vector>

using namespace std;

// Piyush

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
	int p1 = 0, p2 = array.size() -1;
	
	while(p1 <= p2){
		if(array[p2] == toMove){
			p2--;
			continue;
		}
		if(array[p1] == toMove){
			swap(array[p2], array[p1]);
			p2--;
		}
		p1++;
	}
  return array;
}
