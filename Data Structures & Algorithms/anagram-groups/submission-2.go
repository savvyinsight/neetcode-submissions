func groupAnagrams(strs []string) [][]string {
	anagMap := make(map[string][]string)
	for _,s := range strs{
		sorted := sortString(s)
		anagMap[sorted] = append(anagMap[sorted],s)
	}

	result := make([][]string,0,len(anagMap))
	for _,group := range anagMap{
		result = append(result,group)
	}
	return result
}

func sortString(s string) string{
	runes := []rune(s)
	sort.Slice(runes,func(i,j int)bool{
		return runes[i] < runes[j]
	})
	return string(runes)
}
