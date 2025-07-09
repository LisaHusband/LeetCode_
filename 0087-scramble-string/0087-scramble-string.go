package main

import (
	"fmt"
)

type Solution struct {
	sta map[string]bool
}

func (sol *Solution) isScramble0(s1 string, s2 string) bool {
	sol.sta = make(map[string]bool)
	return sol.check(s1, s2)
}

func (sol *Solution) check(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	if len(s1) <= 1 {
		return s1 == s2
	}

	key := s1 + "#" + s2
	if val, ok := sol.sta[key]; ok {
		return val
	}

	// from left to right
	mem := make(map[rune]int)
	for i := 0; i < len(s1); i++ {
		mem[rune(s1[i])]++
		mem[rune(s2[i])]--

		isValid := true
		for _, v := range mem {
			if v != 0 {
				isValid = false
				break
			}
		}

		if isValid {
			if i != len(s1)-1 {
				if sol.check(s1[:i+1], s2[:i+1]) && sol.check(s1[i+1:], s2[i+1:]) {
					sol.sta[key] = true
					return true
				}
			}
		}
	}

	// from right to left
	mem = make(map[rune]int)
	for i := 0; i < len(s1); i++ {
		mem[rune(s1[i])]++
		mem[rune(s2[len(s2)-i-1])]--

		isValid := true
		for _, v := range mem {
			if v != 0 {
				isValid = false
				break
			}
		}

		if isValid {
			if i != len(s1)-1 {
				if sol.check(s1[:i+1], s2[len(s2)-i-1:]) && sol.check(s1[i+1:], s2[:len(s2)-i-1]) {
					sol.sta[key] = true
					return true
				}
			}
		}
	}

	sol.sta[key] = false
	return false
}

func isScramble(s1 string, s2 string) bool {
    sol := &Solution{}
	return sol.isScramble0(s1,s2)
}
