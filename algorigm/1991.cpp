
#include<bits/stdc++.h>

using namespace std;

int N;								//��� ����
char C, L, R;						//��忡 �� ��, ���� ��尪, ������ ��� ��


struct Node {
	char data;						//����� ��
	Node *leftChild, *rightChild;	//�ڽĳ�� �ּ�

	Node(char data) : data(data), leftChild(nullptr), rightChild(nullptr) {}
};

class binaryTree{
public:
	binaryTree() :root(nullptr) {};
	~binaryTree() {};
	void addNode(char data, char leftdata, char rightdata) {
		if (root == nullptr) {
			// ��Ʈ ��尡 ���� ���, �� ��带 ��Ʈ�� ����
			root = new Node(data);
			if (leftdata != '.') root->leftChild = new Node(leftdata);
			if (rightdata != '.') root->rightChild = new Node(rightdata);
		}
		else {
			// ��Ʈ ��尡 �ִ� ���, ��带 ����
			addNodeHelper(root, data, leftdata, rightdata);
		}
	};
	Node* getRoot() {
		return root;
	}
	void preorder(Node *root) {				//������ȸ
		if (root == nullptr) return;
		cout << root->data;
		preorder(root->leftChild);
		preorder(root->rightChild);
	};			
	void inorder(Node* root) {				//������ȸ
		if (root == nullptr) return;
		inorder(root->leftChild);
		cout << root->data;
		inorder(root->rightChild);
	};
	void postorder(Node* root) {			//������ȸ
		if (root == nullptr) return;
		postorder(root->leftChild);
		postorder(root->rightChild);
		cout << root->data;
	};

private:
	Node *root;
	void addNodeHelper(Node* current, char data, char leftdata, char rightdata) {
		if (current == nullptr) return;

		if (current->data == data) {
			// ���� ����� �����Ͱ� �����Ϸ��� �����Ϳ� ��ġ�ϸ� �ڽ� ��带 �߰�
			if (leftdata != '.') current->leftChild = new Node(leftdata);
			if (rightdata != '.') current->rightChild = new Node(rightdata);
		}
		else {
			// ���� ����� �����Ϳ� ��ġ���� ������ �ڽ� ��带 Ž��
			addNodeHelper(current->leftChild, data, leftdata, rightdata);
			addNodeHelper(current->rightChild, data, leftdata, rightdata);
		}
	}
};


int main() {
	binaryTree *BST = new binaryTree();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C >> L >> R;
		BST->addNode(C,L,R);
	}
	BST->preorder(BST->getRoot());
	cout << '\n';
	BST->inorder(BST->getRoot());
	cout << '\n';
	BST->postorder(BST->getRoot());
	cout << '\n';
}