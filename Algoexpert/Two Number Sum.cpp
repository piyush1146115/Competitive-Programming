#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	//Piyush
	vector<int> ans;
	unordered_map<int, int> mp;
	
	for(int i = 0; i < array.size(); i++){
		
		if(mp.find(targetSum-array[i]) != mp.end()){
			ans.push_back(array[i]);
			ans.push_back(targetSum-array[i]);
			break;
		}
		mp[array[i]] = 1;
		
	}
	
  return ans;
}
