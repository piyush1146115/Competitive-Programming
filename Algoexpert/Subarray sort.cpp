#include <vector>
using namespace std;

// Piyush
vector<int> subarraySort(vector<int> array) {
  // Write your code here.
	
	int L = INT_MAX;
	int n = array.size();
	int mn = array[n - 1];
	
	for(int i = n - 2; i >= 0; i-- ){
		if(array[i] > mn){
			L = i;
		}
		mn = min(mn, array[i]);
	}
	
	if(L == INT_MAX){
		return {-1, -1};
	}
	
	int mx = array[0], R;
	for(int i = 1; i < n; i++){
		if(array[i] < mx){
			R = i;
		}
		mx = max(array[i], mx);
	}
	
  return {L, R};
}
