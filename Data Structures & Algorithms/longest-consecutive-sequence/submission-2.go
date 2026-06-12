func longestConsecutive(nums []int) int {
	set := make(map[int]bool)
	for _,num := range nums{
		set[num] = true
 	}
	res := 0
	for num := range set{
		curr,streak := num,0
		for set[curr]{
			curr++
			streak++
		}
		if streak>res{
			res = streak
		}
	}
	return res
}
