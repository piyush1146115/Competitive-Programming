using namespace std;
// Piyush

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int i = 0, j = 0;
	
	bool ans = true;
	
	while(i < sequence.size()){
		while(j < array.size()){
			if(array[j] == sequence[i]){
				j++;
				i++;
				break;
			}
			j++;
		}
		if(j >= array.size() && i < sequence.size()){
			ans = false;	
			break;
		}
	}
	
  return ans;
}
