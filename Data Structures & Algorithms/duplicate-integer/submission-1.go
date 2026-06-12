func hasDuplicate(nums []int) bool {
    record := map[int]bool{}
    for _,num := range nums{
        if record[num]{
            return true
        }else{
            record[num] = true
        }
    }
    return false
}
