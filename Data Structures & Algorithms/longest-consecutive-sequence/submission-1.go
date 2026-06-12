func longestConsecutive(nums []int) int {
	set := make(map[int]bool)
	for _,num := range nums{
		set[num] = true
	}

	MaxStreak := 0
	for num:= range set{
		// Check if it's on the set
		if !set[num-1]{
			currNum := num
			currStreak := 1

			for set[currNum+1]{
				currNum++
				currStreak++
			}
			if currStreak > MaxStreak{
				MaxStreak = currStreak
			}
		}
	}
	return MaxStreak
}
