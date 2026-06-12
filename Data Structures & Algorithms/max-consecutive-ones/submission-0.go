func findMaxConsecutiveOnes(nums []int) int {
	cnt,res := 0,0
	for _,x := range nums{
		if x == 0{
			if cnt > res{
				res = cnt
			}
			cnt = 0
		}else{
			cnt++
		}
	}

	if cnt>res{
		res = cnt
	}
	return res
}
