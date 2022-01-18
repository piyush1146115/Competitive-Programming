#include <vector>
using namespace std;

//Piyush

int firstDuplicateValue(vector<int> array) {

// 	unordered_map<int, bool> mp;
	
// 	for(auto val: array){
// 		if(mp.find(val) != mp.end())
// 			return val;
		
// 		mp[val] = true;
// 	}
	
	
	for(auto val: array){
		int indx = abs(val) - 1;
		if(array[indx] < 0){
			return abs(val);
		}
		
		array[indx] = -1*array[indx];
	}
	
	return -1;

}
