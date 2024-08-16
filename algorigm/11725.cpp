#include<iostream>
#include <vector>

using namespace std;

int main() {
	int root=1, N;				//루트, 노드
	int leftChild, rightChild;	//왼쪽 자식, 오른쪽 자식노드
	vector<int> pNode;				//부모노드


	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> leftChild >> rightChild;
		pNode[i] = N;
	}


}