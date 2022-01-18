using namespace std;

// Piyush

bool hasSingleCycle(vector<int> array) {
 int  n = array.size();
	unordered_map<int,int> mp;
	
	int sum = 0, cnt =1;
	mp[0] = 1;
	
	while(1){
		
		if(array[sum] < 0){
			sum -= (abs(array[sum])%n);
			if(sum < 0){
				//cout << sum << " " << n << endl;
				sum = n + sum;
			}
		}else{
			sum += array[sum];
			sum %= n;
		}
		
	//	cout << array[sum] << " " << sum << endl;
		
		if(mp.find(sum) == mp.end()){
			cnt++;
			mp[sum] = 1;
		}
		else{
			if(sum == 0 && cnt >= n){
				return true;				
			}
			else {
				break;
			}
		}

	}
	return false;
}
