class Solution {
public:
    int rows;
    int cols;
    vector<int> dirx{0, 1, 0, -1};
    vector<int> diry{-1, 0, 1, 0};
    //use the concept of bfs here to find the number of closed islands
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0 && !visited[r][c] && bfs(r, c,grid, visited)) {
                    count++;
                }
            }
        }
        return count;
    }
    //bfs approach
    //
    bool bfs(int x, int y,vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        //to hold the current condition
        bool isClosed = true;

       

        while (!q.empty()) {
            x = q.front().first;   
            y = q.front().second;  
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    // (x, y) is a boundary cell.
                    isClosed = false;
                } else if (grid[r][c] == 0 && !visited[r][c]) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }

        return isClosed;
    }
};