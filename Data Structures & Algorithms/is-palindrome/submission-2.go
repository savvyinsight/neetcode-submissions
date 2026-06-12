func isPalindrome(s string) bool {
	var filtered []byte
	for i:=0;i<len(s);i++{
		if isAlphaNum(s[i]){
			filtered = append(filtered,toLower(s[i]))
		}
	}

	n := len(filtered)
	for i:=0;i<n/2;i++{
		if filtered[i] != filtered[n-1-i]{
			return false
		}
	}
	return true
}

func isAlphaNum(c byte)bool{
	return (c>='a' && c<='z') ||
	(c>='A' && c<='Z') ||
	(c>='0' && c<='9')
}

func toLower(c byte)byte{
	if c>='a' && c<='z'{
		return c - ('a' - 'A')
	}
	return c
}
