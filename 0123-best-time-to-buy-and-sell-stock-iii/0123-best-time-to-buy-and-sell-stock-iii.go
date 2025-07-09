func maxProfit(prices []int) int {
    firstBuy, firstSell := -1<<31, 0
    secondBuy, secondSell := -1<<31, 0

    for _, price := range prices {
        if -price > firstBuy {
            firstBuy = -price
        }
        if firstBuy+price > firstSell {
            firstSell = firstBuy + price
        }
        if firstSell-price > secondBuy {
            secondBuy = firstSell - price
        }
        if secondBuy+price > secondSell {
            secondSell = secondBuy + price
        }
    }
    return secondSell
}