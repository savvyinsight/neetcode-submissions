func longestConsecutive(nums []int) int {
	set := make(map[int]struct{})
	for _, num := range nums {
		set[num] = struct{}{}
	}

	res := 0
	for num := range set {
		curr, streak := num, 0
		for _, ok := set[curr]; ok; _, ok = set[curr] {
			curr++
			streak++
		}
		if streak > res {
			res = streak
		}
	}
	return res
}