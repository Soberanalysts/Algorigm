
#include<bits/stdc++.h>

using namespace std;

int N;								//노드 개수
char C, L, R;						//노드에 들어갈 값, 왼쪽 노드값, 오른쪽 노드 값


struct Node {
	char data;						//노드의 값
	Node *leftChild, *rightChild;	//자식노드 주소

	Node(char data) : data(data), leftChild(nullptr), rightChild(nullptr) {}
};

class binaryTree{
public:
	binaryTree() :root(nullptr) {};
	~binaryTree() {};
	void addNode(char data, char leftdata, char rightdata) {
		if (root == nullptr) {
			// 루트 노드가 없는 경우, 새 노드를 루트로 설정
			root = new Node(data);
			if (leftdata != '.') root->leftChild = new Node(leftdata);
			if (rightdata != '.') root->rightChild = new Node(rightdata);
		}
		else {
			// 루트 노드가 있는 경우, 노드를 삽입
			addNodeHelper(root, data, leftdata, rightdata);
		}
	};
	Node* getRoot() {
		return root;
	}
	void preorder(Node *root) {				//전위순회
		if (root == nullptr) return;
		cout << root->data;
		preorder(root->leftChild);
		preorder(root->rightChild);
	};			
	void inorder(Node* root) {				//중위순회
		if (root == nullptr) return;
		inorder(root->leftChild);
		cout << root->data;
		inorder(root->rightChild);
	};
	void postorder(Node* root) {			//후위순회
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
			// 현재 노드의 데이터가 삽입하려는 데이터와 일치하면 자식 노드를 추가
			if (leftdata != '.') current->leftChild = new Node(leftdata);
			if (rightdata != '.') current->rightChild = new Node(rightdata);
		}
		else {
			// 현재 노드의 데이터와 일치하지 않으면 자식 노드를 탐색
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