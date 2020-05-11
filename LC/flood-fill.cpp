void fillPix(vector<vector<int>>& image, int sr, int sc, int& newColor, int& c) {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == -1 || image[sr][sc] != c) return;
    image[sr][sc] = -1;
    fillPix(image, sr + 1, sc, newColor, c);
    fillPix(image, sr - 1, sc, newColor, c);
    fillPix(image, sr, sc + 1, newColor, c);
    fillPix(image, sr, sc - 1, newColor, c);
    image[sr][sc] = newColor;
}

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c = image[sr][sc];
        fillPix(image, sr, sc, newColor, c);
        return image;
    }
};