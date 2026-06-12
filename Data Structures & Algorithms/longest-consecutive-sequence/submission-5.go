func longestConsecutive(nums []int) int {
	if len(nums) == 0{
		return 0
	}

	sort.Ints(nums)

	res := 1
	streak:= 1
	for i:=1;i<len(nums);i++{
		// Skip duplicates
		if nums[i] == nums[i-1]{
			continue
		}

		if nums[i] == nums[i-1]+1{
			streak++
		}else{
			streak = 1
		}

		if streak > res{
			res = streak
		}
	}
	return res
}
