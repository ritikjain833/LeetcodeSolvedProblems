class Solution:
    def gameOfLife(self, board: [[int]]) -> None:
        def neighbors_of_cell(x, y) -> int:
            left = board[x - 1][y] if x else 0
            right = board[x + 1][y] if x + 1 < m else 0
            up = board[x][y - 1] if y else 0
            down = board[x][y + 1] if y + 1 < n else 0
            left_up = board[x - 1][y - 1] if x and y else 0
            left_down = board[x - 1][y + 1] if x and y + 1 < n else 0
            right_up = board[x + 1][y - 1] if x + 1 < m and y else 0
            right_down = board[x + 1][y + 1] if x + 1 < m and y + 1 < n else 0
            return left + right + up + down + left_up + left_down + right_up + right_down

        m = len(board)
        n = len(board[0])
        neighbors = [[0 for _ in range(n)] for _ in range(m)]  

        for r in range(m):
            for c in range(n):
                neighbors[r][c] = neighbors_of_cell(r, c)
        for r in range(m):
            for c in range(n):
                if board[r][c]:  
                    if neighbors[r][c] > 3:  
                        board[r][c] = 0
                    elif neighbors[r][c] < 2:  
                        board[r][c] = 0
                else:  # dead cell
                    if neighbors[r][c] == 3:  
                        board[r][c] = 1