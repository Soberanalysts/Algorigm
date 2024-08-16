//#include <iostream>
//
//using namespace std;
//
//int M, N;   //가로, 세로
//bool TF;    //칸
//
//
//void dfs(int y, int x, int a[][100], bool visited[][100]) {
//    visited[y][x] = 1;
//    for (int i = 0; i < 4; i++) {
//        ny = y + dy[i];
//        nx = x + dx[i];
//        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
//        if (a[nx][ny] == 1 && !visited[nx][ny]) {
//            dfs(nx, ny, a, visited);
//        }
//    }
//    return;
//}
//
//
////붙어있는 입력값은 1. string으로 받거나 2. scanf로 받아야 한다
//
//int main() {
//
//    cin >> N >> M;
//    for(int i=0; i<N;i++)
//        for (int j = 0; j < M; j++) {
//            bool map[100][100] = { 0 };
//            cin >> TF;
//            map[j][i] = TF;
//        }
//    
//    
//    
//
// 
//
//    return 0;
//}
//

#include<bits/stdc++.h>
using namespace std;
const int max_n = 104;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0, 0 });
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }
    printf("%d", visited[n - 1][m - 1]);
    return 0;
}