#include<bits/stdc++.h>

using namespace std;
#define MAX 51

vector<pair<int, int>>v;
int visited[MAX][MAX];                      //�湮����
int Area[MAX][MAX] = {0};                   //�� ������ �α���
int N, L, R;                                //�� ����, �α�����(�ּ�), �α�����(�ִ�)
int sum, days;                         // �� �α�, �̵��� �ɸ��� ��

int dy[4] = { -1, 0, 1, 0 };                //�����¿� �̵�
int dx[4] = { 0, 1, 0, -1 };

int x, y, nx, ny;


void bfs(int m, int n) {
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
            //if (ny < 0 || ny >= m || nx < 0 || nx >= n || Area[nx][ny]) continue;
            //if (visited[nx][ny] != 0) continue;

            //visited[nx][ny] = visited[x][y] + 1;
            //q.push({ nx, ny });
            if (ny < 0 || nx >= m || nx < 0 || ny >= n || Area[nx][ny]) {
                if (abs(Area[nx][ny] - Area[temp.first][temp.second]) >= L &&
                    abs(Area[nx][ny] - Area[temp.first][temp.second]) <= R) {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;

                    v.push_back({ nx, ny });
                    sum += Area[nx][ny]; //����� ���ϱ� ����
                }
            }
        }

    }
}

int main(){
    cin >> N >> L >> R;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Area[i][j];
        }
    }

    while (true) {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({ i,j });
                    sum = Area[i][j];
                    bfs(i,j);
                    if (v.size() == 1) continue;
                    for (pair<int, int> b : v) {
                        Area[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (flag) days++; //�Ϸ� �߰�
    }

    cout << days;
    return 0;
}