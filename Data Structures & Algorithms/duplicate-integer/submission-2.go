func hasDuplicate(nums []int) bool {
    record := map[int]bool{}
    for _,x := range nums{
        if record[x]{
            return true
        }else{
            record[x] = true
        }
    }
    return false
}
