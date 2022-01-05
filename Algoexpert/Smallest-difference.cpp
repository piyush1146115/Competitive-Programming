#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Piyush
	
	int p1 = 0, p2 = 0;
	int minDif = INT_MAX, min1, min2;
	
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	
	while(p1 < arrayOne.size() && p2 < arrayTwo.size()){
		int dif = abs(arrayOne[p1] - arrayTwo[p2]);
		if(dif < minDif){
			minDif = dif;
			min1 = p1;
			min2 = p2;
		}
		if(arrayOne[p1] < arrayTwo[p2]){
			p1++;
		}
		else{
			p2++;
		}
	}
	
	while(p1 < arrayOne.size()){
		int dif = abs(arrayOne[p1] - arrayTwo[p2 - 1]);
		if(dif < minDif){
			minDif = dif;
			min1 = p1;
			min2 = p2 - 1;
		}
		p1++;
	}
	
	while(p2 < arrayOne.size()){
		int dif = abs(arrayOne[p1 - 1] - arrayTwo[p2]);
		if(dif < minDif){
			minDif = dif;
			min1 = p1 -1;
			min2 = p2;
		}
		p2++;
	}
	
  return {arrayOne[min1], arrayTwo[min2]};
}
