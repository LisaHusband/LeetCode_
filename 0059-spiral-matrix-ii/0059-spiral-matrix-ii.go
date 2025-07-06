func generateMatrix(n int) [][]int {
    matrix := make([][]int, n)
    for i := range matrix {
        matrix[i] = make([]int, n)
    }

    left, right := 0, n-1
    top, bottom := 0, n-1
    num := 1

    for left <= right && top <= bottom {
        // 从左到右填充 top 行
        for col := left; col <= right; col++ {
            matrix[top][col] = num
            num++
        }
        top++

        // 从上到下填充 right 列
        for row := top; row <= bottom; row++ {
            matrix[row][right] = num
            num++
        }
        right--

        // 从右到左填充 bottom 行
        if top <= bottom {
            for col := right; col >= left; col-- {
                matrix[bottom][col] = num
                num++
            }
            bottom--
        }

        // 从下到上填充 left 列
        if left <= right {
            for row := bottom; row >= top; row-- {
                matrix[row][left] = num
                num++
            }
            left++
        }
    }

    return matrix
}
