func topKFrequent(nums []int, k int) []int {
    fre := make(map[int]int)
    for _,num := range nums{
        fre[num]++
    }

    pairs := make([][2]int,0,len(fre))
    for num, cnt := range fre{
        pairs = append(pairs,[2]int{cnt,num})
    }
    sort.Slice(pairs,func(i,j int)bool{
        return pairs[i][0] > pairs[j][0]
    })

    res := make([]int,0,k)
    for i:=0;i<k;i++{
        res = append(res,pairs[i][1])
    }
    return res
}
