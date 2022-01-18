using namespace std;

// Piyush
class MinMaxStack {
public:
	vector<int> st, mn, mx;
	
  int peek() {
    // Write your code here.
		int ret = -1;
		if(st.size() > 0)
			ret = st[st.size() - 1];
		
    return ret;
  }

  int pop() {
    // Write your code here.
		int ret = -1;
		if(st.size() > 0){
			ret = st[st.size() - 1];
			st.pop_back();
			mn.pop_back();
			mx.pop_back();
		}
    return ret;
  }

  void push(int number) {
    // Write your code here.
		st.push_back(number);
		if(mn.size() > 0){
			mn.push_back(min(mn[mn.size() -1], number));
			mx.push_back(max(mx[mx.size() - 1], number));
		}else{
			mn.push_back(number);
			mx.push_back(number);
		}
  }

  int getMin() {
		int ret = -1;
    // Write your code here.
		if(mn.size() > 0){
				ret = mn[mn.size() -1];
		}
    return ret;
  }

  int getMax() {
    // Write your code here.
		int ret = -1;
		if(mx.size() > 0){
			ret = mx[mx.size()- 1];
		}
    return ret;
  }
};
