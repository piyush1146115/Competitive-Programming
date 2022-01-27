using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

// piyush
BST *make(int l, int r, vector<int> &array){
	if(l > r){
		return NULL;
	}
	if(l == r){
		return  new BST(array[l]);
	}
	
	int mid = (l + r)/2;
	
	BST *root;
	root = new BST(array[mid]);
	
	root->left = make(l, mid -1, array);
	root->right = make(mid+1, r, array);
	
	return root;
}

BST *minHeightBst(vector<int> array) {
  // Write your code here.
  return make(0, array.size()-1, array);
}
