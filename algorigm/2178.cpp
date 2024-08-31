#include<bits/stdc++.h>

using namespace std;
#define MAX 101

int visited[MAX][MAX];                      //방문여부
int Maze[MAX][MAX] = { 0 };                   //미로

int dy[4] = { -1, 0, 1, 0 };                //상하좌우 이동
int dx[4] = { 0, 1, 0, -1 };

int x, y, nx, ny;

void bfs(int n, int m) {
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0,0 });
    while (q.size()) {
        y = q.front().first; 
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m|| Maze[ny][nx]==0) continue;
            if (visited[ny][nx] != 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }

    }
}

int main() {
    int  N, M;				        //미로 세로길이, 가로길이

    string input;                   //미로 입력값

    cin >> N >> M;

    for (int i = 0; i < N; i++)     //미로 입력
    {
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            Maze[i][j] = input[j] - '0';
        }
        input = "";
    }
    bfs(N,M);
    cout << visited[N - 1][M - 1];
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