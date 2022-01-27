#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
	sort(intervals.begin(), intervals.end());
	vector<int> cur = intervals[0];
	vector<vector<int> > ans;
	
	for(int i = 0; i < intervals.size(); i++){
		vector<int> buffer = intervals[i];
		if(buffer[0] <= cur[1]){
			cur[1] = max(buffer[1], cur[1]);
		}else{
			ans.push_back(cur);
			cur = buffer;
		}
	}
	ans.push_back(cur);
  return ans;
}
