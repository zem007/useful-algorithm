#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

//创建二叉树
void CreateBiTree(Node** root) {
	int ch;
	cin >> ch;
	if (ch == -1) {
		*root = NULL;
		return;
	}
	else {
		*root = new Node;
		(*root)->value = ch;
		cout << "输入" << ch << "的左子节点：";
		CreateBiTree(&((*root)->left));
		cout << "输入" << ch << "的右子节点：";
		CreateBiTree(&((*root)->right));
	}
	return;
}

//先序遍历二叉树，根左右
void PreOrderBiTree(Node* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << root->value << " ";
		PreOrderBiTree(root->left);
		PreOrderBiTree(root->right);
	}
}

//中序遍历二叉树，左根右；一般用来在二叉树中插入新的Node效率最高
void InOrderBiTree(Node* root) {
	if (root == NULL) {
		return;
	}
	else {
		InOrderBiTree(root->left);
		cout << root->value << " ";
		InOrderBiTree(root->right);
	}
}

//后续遍历二叉树，左右根；一般用来删除二叉树，因为要先删children，再删父节点
void PostOrderBiTree(Node* root) {
	if (root == NULL) {
		return;
	}
	else {
		PostOrderBiTree(root->left);
		PostOrderBiTree(root->right);
		cout << root->value << " ";
	}
}


//二叉树的深度
int TreeDeep(Node* root) {
	int deep = 0;
	if (root != NULL) {
		int leftDeep = TreeDeep(root->left);
		int rightDeep = TreeDeep(root->right);
		if (leftDeep > rightDeep) {
			deep = leftDeep + 1;
		}
		else {
			deep = rightDeep + 1;
		}
	}
	return deep;
}

//子节点的个数

int LeafCount(Node* root) {
	static int count;
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			count++;
		}
		LeafCount(root->left);
		LeafCount(root->right);
	}
	return count;
}

//int main() {
//	Node* root;
//	int deep = 0;
//	int leafCount = 0;
//	cout << "请输入第一个节点的值， -1表示没有子节点：" << endl;
//	CreateBiTree(&root);
//
//	cout << "先序遍历二叉树：";
//	PreOrderBiTree(root);
//	cout << endl;
//
//	cout << "中序遍历二叉树：";
//	InOrderBiTree(root);
//	cout << endl;
//
//	cout << "后序遍历二叉树：";
//	PostOrderBiTree(root);
//	cout << endl;
//
//	deep = TreeDeep(root);
//	cout << "数的深度为：" << deep << endl;
//
//	leafCount = LeafCount(root);
//	cout << "叶子节点个数：" << leafCount << endl;
//
//	return 0;
//}
