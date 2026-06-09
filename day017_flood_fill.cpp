#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        int rows = image.size(), cols = image[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        if (image[r][c] != color) return;
        
        image[r][c] = newColor;
        dfs(image, r + 1, c, color, newColor);
        dfs(image, r - 1, c, color, newColor);
        dfs(image, r, c + 1, color, newColor);
        dfs(image, r, c - 1, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
