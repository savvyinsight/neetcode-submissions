func isValid(s string) bool {
    stack := []byte{}
	pair:= map[byte]byte{
		')':'(',
		']':'[',
		'}':'{',
	}

	for i:=0;i<len(s);i++{
		char := s[i]
		if _ ,exists := pair[char];exists{
			if len(stack) == 0 || stack[len(stack)-1] != pair[char]{
				return false
			}
			stack = stack[:len(stack)-1]
		}else{
			stack = append(stack,char)
		}
	}
	return len(stack) == 0
}
