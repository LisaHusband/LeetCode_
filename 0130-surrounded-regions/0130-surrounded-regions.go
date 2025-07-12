func solve(board [][]byte)  {
    if len(board) == 0 || len(board[0]) == 0 {
		return
	}

	m, n := len(board), len(board[0])

	// 辅助函数：标记与边缘相连的 'O' 为 'S'
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' {
			return
		}
		board[i][j] = 'S' // 标记为安全的 'O'
		// 四个方向进行 DFS
		dfs(i+1, j)
		dfs(i-1, j)
		dfs(i, j+1)
		dfs(i, j-1)
	}

	// 从四个边缘的 'O' 开始 DFS
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			// 如果是边缘上的 'O'
			if (i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O' {
				dfs(i, j)
			}
		}
	}

	// 遍历整个矩阵，将 'O' 替换为 'X'，将 'S' 恢复为 'O'
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			} else if board[i][j] == 'S' {
				board[i][j] = 'O'
			}
		}
	}
}