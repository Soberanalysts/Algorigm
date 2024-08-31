#include<bits/stdc++.h>

using namespace std;
#define MAX 100001

vector<int> adj[MAX];
int visited[MAX];
int parents[MAX] = { 0 };                   //부모노드


void bfs(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int there : adj[here]) {
            if (visited[there]) continue;
            visited[there] = 1;
            q.push(there);
            parents[there] = here;
        }
    }
}

int main() {
	int root=1, N;				//루트, 노드

	int leftChild, rightChild;	


	cin >> N;

	for (int i = 0; i < N-1; i++) {
        cin >> leftChild >> rightChild;
        adj[leftChild].push_back(rightChild);
        adj[rightChild].push_back(leftChild);
	}
    bfs(root);
    for (int i = 2; i <= N; i++)
    {
        cout << parents[i]<<'\n';
    }
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//#define MAX 100001
//
//int N;
//int arr[MAX];
//bool visited[MAX];
//vector<int> v[MAX];
//
//void dfs(int k) {
//    visited[k] = true;
//    for (int i = 0; i < v[k].size(); i++) {
//        int next = v[k][i];
//        if (!visited[next]) {
//            arr[next] = k;
//            dfs(next);
//        }
//    }
//}
//
//int main() {
//    cin >> N;
//
//    for (int i = 0; i < N; i++) {
//        int x, y;
//        cin >> x >> y;
//        v[x].push_back(y);
//        v[y].push_back(x);
//    }
//
//    dfs(1);
//
//    for (int i = 2; i <= N; i++) cout << arr[i] << "\n";
//}