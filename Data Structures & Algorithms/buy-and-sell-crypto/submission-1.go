func maxProfit(prices []int) int {
	maxProfit := 0
	minPrice := prices[0]
	for i:=1;i<len(prices);i++{
		if minPrice>prices[i]{
			minPrice = prices[i]
		}else{
			profit := prices[i] - minPrice
			maxProfit = max(maxProfit,profit)
		}
	}
	return maxProfit
}
