func isValidSudoku(board [][]byte) bool {
	// row
	for i:=0;i<9;i++{
		seen := make(map[byte]bool)
		for j:=0;j<9;j++{
			if board[i][j] != '.'{
				if seen[board[i][j]] {
					return false
				}
				seen[board[i][j]] = true
			}
		}
	}

	// col
	for j:=0;j<9;j++{
		seen := make(map[byte]bool)
		for i:=0;i<9;i++{
			if board[i][j] != '.'{
				if seen[board[i][j]]{
					return false
				}
				seen[board[i][j]] = true
			}
		}
	}

	// square
	for s := 0;s<9;s++{
		seen := make(map[byte]bool)
		for i:=0;i<3;i++{
			for j:=0;j<3;j++{
				row := (s/3)*3 + i
				col := (s%3)*3 + j
				if board[row][col] != '.'{
					if seen[board[row][col]]{
						return false
					}
					seen[board[row][col]] = true
				}
			}
		}
	}
	return true
}
