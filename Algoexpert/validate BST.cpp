class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validate(BST *tree, int mx, int mn){
		
	if(tree == NULL)
		return true;
	
	int cur = tree->value;
	if(cur < mn || cur >= mx){
		return false;
	}
	return validate(tree->left, cur, mn) && validate(tree->right, mx, cur);
	
	
// 	bool ret = true;
	
// 	if(tree->left != NULL){
// 		if(tree->left->value >= value){
// 			return false;
// 		}
// 		ret = validate(tree->left, max(tree->value, value), min(tree->value, mn));
// 	}

// 	if(tree->right != NULL){
// 		if(tree->right->value < mn){
// 			return false;
// 		}
// 		ret = ret && validate(tree->right,max(tree->value, value),  min(tree->value, mn));
// 	}
//   return ret;
	
	
}

bool validateBst(BST *tree) {
  // Write your code here.
	
	return validate(tree, INT_MAX, INT_MIN);
}
