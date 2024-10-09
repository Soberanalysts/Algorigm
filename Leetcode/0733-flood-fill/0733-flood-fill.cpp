class Solution {
public:
    int precolor, ny, nx,n,m;
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    vector<vector<bool>> visited;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    if(image[sr][sc] == color){
        return image;
    }
    // 방문 배열 초기화


    precolor = image[sr][sc];
    n = image.size();
    m = image[0].size();
    visited.assign(n, vector<bool>(m, false));

    DFS(image, sr, sc, color);
    return image;
    }

    void DFS(vector<vector<int>> &image, int row, int col, int color){
        visited[row][col] = true; // 현재 위치 방문 처리
        image[row][col]= color;
        
    for (int i = 0; i < 4; i++) {
        ny = row + dy[i]; // 다음 위치의 y 좌표
        nx = col + dx[i]; // 다음 위치의 x 좌표

            // 범위를 벗어나는지 확인
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            // 아직 방문하지 않았고, 깊이 판정이 된 경우
        if (image[ny][nx]==precolor && !visited[ny][nx]) {
            DFS(image, ny, nx, color); // 재귀적으로 DFS 호출
            }
        }
    return;
    }
};
