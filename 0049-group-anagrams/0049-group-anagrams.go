package main

import (
	"fmt"
)

func groupAnagrams(strs []string) [][]string {
	// 每个字母对应一个质数，a -> 2, b -> 3, ..., z -> 103
	primes := []int{
		107, 3, 2, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41,
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
	}

	hash := make(map[uint64][]string)

	for _, s := range strs {
		var key uint64 = 1
		for _, ch := range s {
			idx := ch - 96 // 这里注意：Go中的rune类型直接用'a'会得到97
			if idx < 1 || idx > 26 {
				continue // 防止越界
			}
			key *= uint64(primes[idx])
		}
		hash[key] = append(hash[key], s)
	}

	result := make([][]string, 0, len(hash))
	for _, group := range hash {
		result = append(result, group)
	}

	return result
}


