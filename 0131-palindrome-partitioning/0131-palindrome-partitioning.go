package main

import "fmt"

type Solution struct{}

func partition(s1 string) [][]string {
    res := [][]string{}
    path := []string{}

    // 判断是否是回文串
    isPalindrome := func(start, end int) bool {
        for start < end {
            if s1[start] != s1[end] {
                return false
            }
            start++
            end--
        }
        return true
    }

    var backtrack func(start int)
    backtrack = func(start int) {
        // 如果 start 达到字符串的末尾，表示分割完成
        if start == len(s1) {
            // 保存当前路径（分割方案）
            res = append(res, append([]string(nil), path...))
            return
        }

        for end := start; end < len(s1); end++ {
            // 如果子串是回文串
            if isPalindrome(start, end) {
                path = append(path, s1[start:end+1]) // 选择当前子串
                backtrack(end + 1) // 递归处理剩下的部分
                path = path[:len(path)-1] // 撤销选择
            }
        }
    }

    // 从起始位置开始回溯
    backtrack(0)
    return res
}

// func main() {
//     solution := Solution{}
//     s := "aab"
//     result := solution.partition(s)
//     fmt.Println(result) // 输出: [["a", "a", "b"], ["aa", "b"]]
// }