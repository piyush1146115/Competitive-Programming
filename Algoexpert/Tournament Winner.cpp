#include <vector>
using namespace std;

// Piyush

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
	unordered_map<string,int> mp;
	string ans = "";
	
	for(int i = 0; i < competitions.size(); i++){
		if(results[i] == 1){
			mp[competitions[i][0]] += 3;
			if (mp[competitions[i][0]] > mp[ans])
					ans = competitions[i][0];
		}
		else{
			mp[competitions[i][1]] += 3;
			if (mp[competitions[i][1]] > mp[ans])
					ans = competitions[i][1];
		}
	}
	
  return ans;
}
