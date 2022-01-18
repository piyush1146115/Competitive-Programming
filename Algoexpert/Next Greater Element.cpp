#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
  // Write your code here.
	int n = array.size();
	vector<int> ans(n, -1);
	stack<int> st;
	
	
	for(int i = 0; i < array.size(); i++){
		while(!st.empty() && array[st.top()] < array[i]){
			ans[st.top()] = array[i];
			st.pop();
		}
		st.push(i);
	}
	
	for(int i = 0; i < array.size(); i++){
		while(!st.empty() && array[st.top()] < array[i]){
			ans[st.top()] = array[i];
			st.pop();
		}
		st.push(i);
	}
	
	
	
  return ans;
}
