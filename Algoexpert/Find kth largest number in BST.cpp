using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

int ans, K;
void solve(BST *tree){
	if(tree == NULL|| K==0)
		return;
	
	solve(tree->right);
	K--;
	// cout << tree->value << " " << K << endl;
	if(K == 0){
		ans = tree->value;
		return;
	}
	solve(tree->left);
}

int findKthLargestValueInBst(BST *tree, int k) {
  // Write your code here.
	K=k;
	solve(tree);
	
  return ans;
}
