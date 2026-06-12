func isValidSudoku(board [][]byte) bool {
	rows := make([]map[byte]bool,9)
	cols := make([]map[byte]bool,9)
	square := make([]map[byte]bool,9)

	for i:=0;i<9;i++{
		rows[i] = make(map[byte]bool)
		cols[i] = make(map[byte]bool)
		square[i] = make(map[byte]bool)
	}

	for i:=0;i<9;i++{
		for j:=0;j<9;j++{
            ch := board[i][j]
            squareIndex := (i/3)*3 +j/3

			if board[i][j] != '.'{
				if rows[i][ch] || cols[j][ch] || square[squareIndex][ch]{
					return false
				}
				rows[i][ch] = true
				cols[j][ch] = true
				square[squareIndex][ch] = true
			
			}
        }
	}
	return true
}
