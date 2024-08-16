#include <iostream>

using namespace std;


int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ny, nx;
int T, M, N, K;			        //테스트케이스 개수,  배추밭의 가로길이,  배추밭의 세로길이, 배추가 심어진 위치갯수
int X, Y, W = 0;					//배추의 위치(x,y),배추 흰지렁이 수


void dfs(int x, int y, int a[][50], bool visited[][50]) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (a[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, a, visited);
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        int a[50][50] = { 0 };                      //배추밭 배추 유무(초기화와 동시에 선언)
        bool visited[50][50] = { 0 };               
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            a[X][Y] = 1;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (a[i][j] == 1 && !visited[i][j]) {
                     dfs(i, j, a, visited);
                     W++;
                }
            }
        }
        cout << W << '\n';
        W = 0;
    }

    return 0;
}

