type Solution struct{}

func (s *Solution) Encode(strs []string) string {
	if len(strs) == 0{
		return ""
	}
	res := ""
	for _,str := range strs{
		res += strconv.Itoa(len(str)) + "#" + str
	}
	return res
}

func (s *Solution) Decode(encoded string) []string {
	if len(encoded) == 0{
		return []string{}
	}
	res := []string{}
	i := 0
	for i<len(encoded){
		j := i
		for encoded[j] != '#'{
			j++
		}
		length,_ := strconv.Atoi(encoded[i:j])
		j++
		res = append(res, encoded[j:j+length])
		i = j+length
	}
	return res
}
