func isValid(s string) bool {
    for {
		newS := removePair(s)
		if newS == s{
			break
		}
		s = newS
	}
	return s == ""
}

func removePair(s string) string{
	for i:=0;i<len(s)-1;i++{
		tmp := s[i:i+2]
		if tmp == "()" || tmp == "[]" || tmp == "{}"{
			return s[:i] + s[i+2:]
		}
	}
	return s
}
