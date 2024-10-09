/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */

var floodFill = function(image, sr, sc, color) {
    let precolor = image[sr][sc];
    if (precolor === color) return image;

    let n = image.length;
    let m = image[0].length;
    let visited = Array.from({ length: n }, () => Array(m).fill(false));

    let dy = [-1, 0, 1, 0];
    let dx = [0, 1, 0, -1];

    function DFS(row, col) {
        visited[row][col] = true;
        image[row][col] = color;

        for (let i = 0; i < 4; i++) {
            let ny = row + dy[i];
            let nx = col + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (image[ny][nx] === precolor && !visited[ny][nx]) {
                DFS(ny, nx);
            }
        }
    }

    DFS(sr, sc);
    return image;
};