#include<bits/stdc++.h>
#define MAX 101

using namespace std;


int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1};

int n, m, tmoatoState[MAX][MAX][MAX], visited[MAX][MAX][MAX], x, y, z;



int day;                                                        //모두 익는데 걸리는 날


void dfs() {
    visited[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        nz = z + dz[i];
        if (ny < 0 || nx < 0 || nz<0 || ny >= N || nx >= M) continue;
        if (a[nx][ny] == 1 && !visited[nx][ny][nz]) {
            dfs(nx, ny, nz);
        }
    }
    day++
    dfs();
}
int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

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