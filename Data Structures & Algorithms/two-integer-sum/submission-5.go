func twoSum(nums []int, target int) []int {
    type pair struct{
        val int
        index int
    }

    pairs := make([]pair,len(nums))
    for i,num := range nums{
        pairs[i] = pair{val:num,index:i}
    }
    sort.Slice(pairs,func(i,j int)bool{
        return pairs[i].val < pairs[j].val
    })

    l,r := 0,len(pairs)-1
    for l<r{
        sum := pairs[l].val + pairs[r].val
        if sum == target{
            if pairs[l].index < pairs[r].index{
                return []int{pairs[l].index,pairs[r].index}
            }else{
                return []int{pairs[r].index,pairs[l].index}
            }
        }else if sum>target{
            r--
        }else{
            l++
        }
    }
    return []int{}
}
