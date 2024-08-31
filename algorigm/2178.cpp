#include<bits/stdc++.h>

using namespace std;
#define MAX 101

int visited[MAX][MAX];                      //방문여부
int Maze[MAX][MAX] = { 0 };                   //미로

int dy[4] = { -1, 0, 1, 0 };                //상하좌우 이동
int dx[4] = { 0, 1, 0, -1 };

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
    int root = 1, N;				//루트, 노드

    int leftChild, rightChild;


    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> leftChild >> rightChild;
        adj[leftChild].push_back(rightChild);
        adj[rightChild].push_back(leftChild);
    }
    bfs(root);
    for (int i = 2; i <= N; i++)
    {
        cout << parents[i] << '\n';
    }
}
//
//#include<bits/stdc++.h>
//using namespace std;
//const int max_n = 104;
//int dy[4] = { -1, 0, 1, 0 };
//int dx[4] = { 0, 1, 0, -1 };
//int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;
//int main() {
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%1d", &a[i][j]);
//        }
//    }
//    queue<pair<int, int>> q;
//    visited[0][0] = 1;
//    q.push({ 0, 0 });
//    while (q.size()) {
//        tie(y, x) = q.front(); q.pop();
//        for (int i = 0; i < 4; i++) {
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
//            if (visited[ny][nx]) continue;
//            visited[ny][nx] = visited[y][x] + 1;
//            q.push({ ny, nx });
//        }
//    }
//    printf("%d", visited[n - 1][m - 1]);
//    return 0;
//}