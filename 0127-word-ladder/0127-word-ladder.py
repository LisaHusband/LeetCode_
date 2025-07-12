from collections import defaultdict
from collections.abc import Iterable
from itertools import chain
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # 辅助函数：BFS实现
        class BFS:
            __slots__ = ('searched', 'searching', 'searching_next')

            def __init__(self, length: int, searching: Iterable[int], is_searched: bool) -> None:
                self.searched: list[list[int]] = [[] for _ in range(length)]
                self.searching: set[int] = set(searching)
                self.searching_next: set[int] = set()
                if is_searched:
                    for i in self.searching:
                        self.searched[i].append(i)

            def search_one_index(self, index_prev: int, i: int) -> None:
                if not self.searched[i]:
                    self.searching_next.add(i)
                    self.searched[i].append(index_prev)
                elif i in self.searching_next:
                    self.searched[i].append(index_prev)

            def search_indexes(self, index_prev: int, indexes: Iterable[int]) -> None:
                for i in indexes:
                    self.search_one_index(index_prev, i)

            def switch_next(self) -> None:
                self.searching, self.searching_next = self.searching_next, self.searching

        # 如果 endWord 不在 wordList 中，直接返回 0
        if endWord not in wordList:
            return 0

        # 处理结束条件
        try:
            wordList.remove(endWord)
        except ValueError:
            return 0

        # 如果 beginWord 和 endWord 只差一个字母，直接返回 2
        if sum(1 for chr1, chr2 in zip(beginWord, endWord) if chr1 != chr2) == 1:
            return 2

        try:
            wordList.remove(beginWord)
        except ValueError:
            pass

        len_word = len(beginWord)
        dict_indexes = defaultdict(list)

        # 创建字典：每个单词的变形组合
        for i, word in enumerate(wordList):
            for j in range(len_word):
                dict_indexes[f'{word[:j]}_{word[j + 1 :]}'].append(i)

        wordList.extend([beginWord, endWord])
        len_wordlist = len(wordList)

        # 初始化BFS的两个方向
        begin = BFS(len_wordlist, [-2], False)
        end = BFS(len_wordlist, [-1], False)

        # 双向BFS
        for depth in range(1, len_wordlist + 2):
            for _ in range(len(begin.searching)):
                word = wordList[i := begin.searching.pop()]
                begin.search_indexes(i, chain(*[dict_indexes[f'{word[:j]}_{word[j + 1 :]}'] for j in range(len_word)]))
            begin.switch_next()

            # 如果找到了交集，返回从 beginWord 到 endWord 的最短路径长度
            if intersection := begin.searching & end.searching:
                if depth % 2 == 0:
                    begin, end = end, begin
                return depth + 1

            begin, end = end, begin

        return 0
