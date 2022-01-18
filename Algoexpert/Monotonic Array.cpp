using namespace std;

//Piyush

bool isMonotonic(vector<int> array) {
  // Write your code here.
	bool increase = true, decrease = true;
	
	for(int i = 1; i < array.size(); i++){
		if(array[i] > array[i-1]){
			decrease = false;
		}
		if(array[i] < array[i-1]){
			increase = false;
		}
	}
  return (increase || decrease);
}
