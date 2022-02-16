/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]

 

Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], newColor < 216
    0 <= sr < m
    0 <= sc < n

*/

class Solution {
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();

        auto inside = [&](int x, int y) {
            return x >= 0 and y >= 0 and x < m and y < n;
        };
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int curr = image[sr][sc];

        queue<pair<int, int>> q;
        vis[sr][sc] = true;
        q.push(make_pair(sr, sc));
        image[sr][sc] = newColor;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = node.first + dx[k];
                int y = node.second + dy[k];
                if (inside(x, y) and !vis[x][y] and image[x][y] == curr) {
                    image[x][y] = newColor;
                    vis[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
        }
        return image;
    }
};

