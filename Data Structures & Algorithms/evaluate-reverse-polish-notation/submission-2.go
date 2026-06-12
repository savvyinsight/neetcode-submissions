func evalRPN(tokens []string) int {
	for i := 0; i < len(tokens); i++ {
		v := tokens[i]
		if v == "+" || v == "-" || v == "*" || v == "/" {
			r, _ := strconv.Atoi(tokens[i-1])
			l, _ := strconv.Atoi(tokens[i-2])
			tokens_update := []string{}
			tokens_update = append(tokens_update, tokens[:i-2]...)
			switch v {
			case "+":
				// delete or flag three tokens, then replace with l+r, same as others.
				// but in Go, we can't change string, so not flaggable.
				// can we delete, if delete, needs move all elements to forward.
				// what should I do?

				// -->create new slice
				tokens_update = append(tokens_update, strconv.Itoa(l+r))
			case "-":
				tokens_update = append(tokens_update, strconv.Itoa(l-r))
			case "*":
				tokens_update = append(tokens_update, strconv.Itoa(l*r))
			case "/":
				tokens_update = append(tokens_update, strconv.Itoa(l/r))
			}

			tokens_update = append(tokens_update, tokens[i+1:]...)
			tokens = tokens_update
			i = i - 3
		}
	}
	res, _ := strconv.Atoi(tokens[0])
	return res // will remain only one token
}