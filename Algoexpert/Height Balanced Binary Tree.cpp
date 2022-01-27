using namespace std;

// This is an input class. Do not edit.
// Piyush
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};


bool ans;

int visit(BinaryTree *tree){
	if(tree == NULL)
		return 0;
	
	int left = 1 + visit(tree->left);
	int right = 1 + visit(tree->right);
	
	if(abs(left-right) > 1)
		ans = false;
	return max(left, right);
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
  // Write your code here.
	ans = true;
	visit(tree);
  return ans;
}
