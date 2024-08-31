#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int countWorm = 0;					//웜에 걸리는 컴퓨터 수
const int n = 100;					//최대 컴퓨터 수
vector<int> adj[n];					//쌍을 이룰 컴퓨터 번호
bool visited[n] = { 0 };

void dfs(int u){
	visited[u] = 1;
	//cout << u << "\n";
	for (int v : adj[u]) {
		if (visited[v] == 0) {
			countWorm++;
			dfs(v);
		}
	}
	//for (int v = 0; v < adj[u].size(); v++) {
	//	if (visited[v] == 0) {
	//		countworm++;
	//		dfs(v);
	//	}
	//}

	return;
}

int main() {
	int countCom=0, comPair=0;	//컴퓨터 수, 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수, 
	
	

	cin >> countCom;
	cin >> comPair;

	for (int i = 0; i < comPair; i++) {
		int numCom1, numCom2 ;
		cin >> numCom1 >> numCom2;
		adj[numCom1].push_back(numCom2);
		adj[numCom2].push_back(numCom1);
	}
	dfs(1);
	
	cout << countWorm;

	return 0;
}