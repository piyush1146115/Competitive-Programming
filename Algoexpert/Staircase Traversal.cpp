using namespace std;

int visit(int height, int mx, vector<int> &DP){
	if(height == 0)
		return 1;
	if(height < 0)
		return 0;
	
	if(DP[height] != -1){
		return DP[height];
	}
	
	int ret = 0;
	for(int i = 1; i <= mx; i++){
		ret += visit(height-i,mx,DP);
	}
	
	DP[height] = ret;
	return ret;
}


int staircaseTraversal(int height, int maxSteps) {
  // Write your code here.
	vector<int > DP(height+1, -1);
	
	return visit(height, maxSteps, DP);
  
}
