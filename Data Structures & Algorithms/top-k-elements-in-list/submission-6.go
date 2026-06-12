func topKFrequent(nums []int, k int) []int {
    fre := make(map[int]int)
    for _,num := range nums{
        fre[num]++
    }
    minHeap := &MinHeap{}
    heap.Init(minHeap)

    for num,count := range fre{
        heap.Push(minHeap,pair{num,count})
        if minHeap.Len() > k{
            heap.Pop(minHeap)
        }
    }

    res := make([]int,0,k)
    for minHeap.Len() > 0{
        res = append(res,heap.Pop(minHeap).(pair).num)
    }
    return res
}

type pair struct{
    num int
    count int
}

type MinHeap []pair

func (h MinHeap) Len() int {return len(h)}
func (h MinHeap) Less(i,j int) bool {return h[i].count < h[j].count}
func (h MinHeap) Swap(i,j int) {h[i],h[j] = h[j],h[i]}

func (h *MinHeap) Push(x interface{}){
    *h = append(*h,x.(pair))
}

func (h *MinHeap) Pop() interface{}{
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0:n-1]
    return x
}

