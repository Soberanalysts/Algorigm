#include <iostream>

using namespace std;


int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ny, nx;
int T, M, N, K;			        //�׽�Ʈ���̽� ����,  ���߹��� ���α���,  ���߹��� ���α���, ���߰� �ɾ��� ��ġ����
int X, Y, W = 0;					//������ ��ġ(x,y),���� �������� ��


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
        int a[50][50] = { 0 };                      //���߹� ���� ����(�ʱ�ȭ�� ���ÿ� ����)
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

