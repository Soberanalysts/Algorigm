#include<bits/stdc++.h>

using namespace std;
#define MAX 1001

int visited[MAX][MAX];                      //방문여부
int Map[MAX][MAX] = { 0 };                  //미로

int dy[4] = { -1, 0, 1, 0 };                //상하좌우 이동
int dx[4] = { 0, 1, 0, -1 };

int x, y, nx, ny;

void bfs(int n, int m) {
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0,0 });
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n || Map[nx][ny] == 0) continue;
            if (visited[nx][ny] != 0) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push({ nx, ny });
        }

    }
}

int main() {
    int  N, M;				        //미로 세로길이, 가로길이

    cin >> N >> M;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int input;
            cin >> input;
            if (input == 2)
            {
                x = i;
                y = j;
            }
            Map[i][j] = input;
        }
    }
    bfs(N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Map[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << visited[i][j] - 1 << " ";
            }
        }
        cout << "\n";
    }
}