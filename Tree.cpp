#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

//����������
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
		cout << "����" << ch << "�����ӽڵ㣺";
		CreateBiTree(&((*root)->left));
		cout << "����" << ch << "�����ӽڵ㣺";
		CreateBiTree(&((*root)->right));
	}
	return;
}

//���������������������
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

//�������������������ң�һ�������ڶ������в����µ�NodeЧ�����
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

//�������������������Ҹ���һ������ɾ������������ΪҪ��ɾchildren����ɾ���ڵ�
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


//�����������
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

//�ӽڵ�ĸ���

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
//	cout << "�������һ���ڵ��ֵ�� -1��ʾû���ӽڵ㣺" << endl;
//	CreateBiTree(&root);
//
//	cout << "���������������";
//	PreOrderBiTree(root);
//	cout << endl;
//
//	cout << "���������������";
//	InOrderBiTree(root);
//	cout << endl;
//
//	cout << "���������������";
//	PostOrderBiTree(root);
//	cout << endl;
//
//	deep = TreeDeep(root);
//	cout << "�������Ϊ��" << deep << endl;
//
//	leafCount = LeafCount(root);
//	cout << "Ҷ�ӽڵ������" << leafCount << endl;
//
//	return 0;
//}
