package main

import (
	"fmt"
)

// ---------- 主函数 ----------
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	wordSet := make(map[string]bool)
	for _, word := range wordList {
		wordSet[word] = true
	}
	if !wordSet[endWord] {
		return [][]string{}
	}

	// 图结构：记录每个单词的前驱
	graph := make(map[string][]string)
	// 记录访问层级（用于限制只走最短路径）
	visited := make(map[string]int)

	queue := []string{beginWord}
	visited[beginWord] = 0

	found := false
	step := 0

	// ---------- BFS 构图 ----------
	for len(queue) > 0 && !found {
		step++
		nextQueue := []string{}
		localVisited := make(map[string]bool)

		for _, word := range queue {
			wordRunes := []rune(word)
			for i := 0; i < len(wordRunes); i++ {
				original := wordRunes[i]
				for c := 'a'; c <= 'z'; c++ {
					if c == original {
						continue
					}
					wordRunes[i] = c
					nextWord := string(wordRunes)
					if wordSet[nextWord] {
						if _, ok := visited[nextWord]; !ok {
							localVisited[nextWord] = true
							visited[nextWord] = step
							nextQueue = append(nextQueue, nextWord)
							graph[nextWord] = append(graph[nextWord], word)
						} else if visited[nextWord] == step {
							graph[nextWord] = append(graph[nextWord], word)
						}
						if nextWord == endWord {
							found = true
						}
					}
				}
				wordRunes[i] = original
			}
		}

		// 移除本层已访问的单词（防止走回头路）
		for word := range localVisited {
			delete(wordSet, word)
		}
		queue = nextQueue
	}

	// ---------- DFS 回溯 ----------
	res := [][]string{}
	if found {
		path := []string{endWord}
		dfs(endWord, beginWord, graph, path, &res)
	}
	return res
}

// ---------- DFS 回溯路径 ----------
func dfs(word, beginWord string, graph map[string][]string, path []string, res *[][]string) {
	if word == beginWord {
		// reverse path
		reversed := make([]string, len(path))
		for i := range path {
			reversed[i] = path[len(path)-1-i]
		}
		*res = append(*res, reversed)
		return
	}
	for _, prev := range graph[word] {
		path = append(path, prev)
		dfs(prev, beginWord, graph, path, res)
		path = path[:len(path)-1] // 回溯
	}
}
