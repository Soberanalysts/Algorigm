#include<bits/stdc++.h>

using namespace std;
#define MAX 301

bool visited[MAX][MAX];                                      //방문여부
int coordinate[MAX][MAX] = { 0 };                           //체스판 좌표

int dy[8] = { -1, 2, 1, 2, -1, 1, -2, -2 };                //나이트 이동 범위
int dx[8] = { 2, 1, 2, -1, -2, -2, 1, -1 };


int T, I;                                                   //테스트 케이스, 체스판 한면의 길이, 
int pre_X, pre_Y, mov_X, mov_Y;                             //현재 나이트 위치(X,Y), 이동하려는 위치(X,Y)

int x, y, nx, ny;


//void bfs(int length, int preX, int preY, int movX, int movY) {
//    queue<pair<int, int>> q;
//    //visited[preX][preY] = 1;
//    coordinate[movX][movY]=1;
//    q.push({ preX,preY });
//    while (q.size()) {
//        x = q.front().first;
//        y = q.front().second;
//        q.pop();
//        for (int i = 0; i < 8; i++)
//        {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            
//            if (ny < 0 || ny >= length || nx < 0 || nx >= length || coordinate[nx][ny] == 1) continue;
//            
//            if (visited[ny][nx] != 0) continue;
//
//            visited[nx][ny] = visited[x][y] + 1;
//            q.push({ nx, ny });
//
//            if ((nx== movX)&&(ny==movY))break;
//        }
//
//    }
//}
int bfs(int length, int beginX, int beginY, int endX, int endY) {
    queue<pair<int, int> > q;

    q.push(make_pair(beginX, beginY));
    visited[beginX][beginY] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x == endX && y == endY) return coordinate[x][y];

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];//이동하기 
            int ny = y + dy[i];
            if (nx < 0 || nx >= length || ny < 0 || ny >= length) continue;
            if (visited[nx][ny] == true) continue;
            else {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                coordinate[nx][ny] = coordinate[x][y] + 1;
            }
        }
    }
    return coordinate[endX][endY];
}
int main() {

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> I;
        cin >> pre_X >> pre_Y;
        cin >> mov_X >> mov_Y;
        bfs(I, pre_X, pre_Y, mov_X, mov_Y);
        cout << /*coordinate[mov_X][mov_Y]*/bfs(I, pre_X, pre_Y, mov_X, mov_Y) << '\n';
        //coordinate[mov_X][mov_Y] = 0;
        fill(&visited[0][0], &visited[I][I], 0);
        fill(&coordinate[0][0], &coordinate[I][I], 0);
    }
    //for (int i = 0; i < I; i++)
    //{
    //    for (int j = 0; j < I; j++)
    //    {
    //        if (coordinate[i][j] == 1)
    //        {
    //            cout << visited[i][j] << "\n";
    //        }
    //    }

    //}
    //

}