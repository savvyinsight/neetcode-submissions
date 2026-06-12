func topKFrequent(nums []int, k int) []int {
    fre := make(map[int]int)
	for _, num := range nums {
		fre[num]++
	}

    buckets := make([][]int, len(nums)+1)
	for num, count := range fre {
		buckets[count] = append(buckets[count], num)
	}

    res := make([]int, 0, k)
    for i:=len(buckets)-1;i>0;i--{
        for _,num := range buckets[i]{
            res = append(res,num)
            if len(res) == k{
                return res
            }
        }
    }
    return res
}
