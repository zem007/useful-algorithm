/*
Morris������������ʹ�ÿռ临�Ӷ�ΪO(1)

�������̣�
����ָ��curָ��ǰ�ڵ㣬cur��ͷ��㿪ʼ��
1. ���cur�����ӣ���cur = cur.right��
2. ���cur�����ӣ����ҵ�cur�����������ҵĽڵ㣬��ΪmostRight����Ϊ�������������
    aa.��mostRight��rightָ��Ϊnull��������ָ��cur����cur = cur.left;
    bb.��mostRight��rightָ��ָ��cur��������ָ��null����cur = cur.right
3.curΪ��ʱ����ֹͣ
*/

#include <iostream>

using namespace std;

struct Node
{
	int val;
	struct Node* left;
	struct Node* right;

	Node(int _val) :
		val(_val), left(NULL), right(NULL) {}
};

// Morris������� (�� -> �� -> ��)
void MorrisInOrderTraverse(Node* head)
{
	if (head == NULL)
	{
		return;
	}

	Node* p1 = head;
	Node* p2 = NULL;

	while (p1 != NULL)
	{
		p2 = p1->left;
		if (p2 != NULL)
		{
			while (p2->right != NULL && p2->right != p1)
			{
				p2 = p2->right;
			}
			if (p2->right == NULL)
			{
				p2->right = p1;		// ����ָ��
				p1 = p1->left;
				continue;
			}
			else
			{
				p2->right = NULL;
			}
		}
		cout << p1->val << " ";
		p1 = p1->right;
	}
}

// Morrisǰ����� (�� -> �� -> ��)
void MorrisPreOrderTraverse(Node* head)
{
	if (head == NULL)
	{
		return;
	}

	Node* p1 = head;
	Node* p2 = NULL;

	while (p1 != NULL)
	{
		p2 = p1->left;
		if (p2 != NULL)
		{
			while (p2->right != NULL && p2->right != p1)
			{
				p2 = p2->right;
			}
			if (p2->right == NULL)
			{
				p2->right = p1;		// ����ָ��
				cout << p1->val << " ";	// ��ӡ���ֵ��˳����΢����
				p1 = p1->left;
				continue;
			}
			else
			{
				p2->right = NULL;
			}
		}
		else
		{
			cout << p1->val << " ";
		}
		p1 = p1->right;
	}
}

// �����ұ߽�
Node* reverseEdge(Node* head)
{
	Node* pre = NULL;
	Node* next = NULL;

	while (head != NULL)
	{
		next = head->right;
		head->right = pre;
		pre = head;
		head = next;
	}

	return pre;
}

// �����ӡ�������ұ߽�
void printEdge(Node* head)
{
	Node* lastNode = reverseEdge(head);
	Node* cur = lastNode;

	while (cur != NULL)
	{
		cout << cur->val << " ";
		cur = cur->right;
	}
	reverseEdge(lastNode);
}

// Morris������� (�� -> �� -> ��)
void MorrisPostOrderTraverse(Node* head)
{
	if (head == NULL)
	{
		return;
	}

	Node* p1 = head;
	Node* p2 = NULL;

	while (p1 != NULL)
	{
		p2 = p1->left;
		if (p2 != NULL)
		{
			while (p2->right != NULL && p2->right != p1)
			{
				p2 = p2->right;
			}
			if (p2->right == NULL)
			{
				p2->right = p1;		// ����ָ��
				p1 = p1->left;
				continue;
			}
			else
			{
				p2->right = NULL;
				printEdge(p1->left);
			}
		}
		p1 = p1->right;
	}
	printEdge(head);
}

void buildBinTree(Node** head)
{
	int _val;
	cin >> _val;

	if (_val == -1)
	{
		*head = NULL;
	}
	else
	{
		*head = (Node*)malloc(sizeof(Node));
		(*head)->val = _val;
		buildBinTree(&(*head)->left);
		buildBinTree(&(*head)->right);
	}
}

int main(void)
{
	Node* head;
	buildBinTree(&head);
	cout << "ǰ���������Ϊ:";
	MorrisPreOrderTraverse(head);
	cout << endl;

	cout << "�����������Ϊ:";
	MorrisInOrderTraverse(head);
	cout << endl;

	cout << "�����������Ϊ:";
	MorrisPostOrderTraverse(head);
	cout << endl;

	return 0;
}
