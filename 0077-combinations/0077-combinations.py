class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # 使用 itertools.combinations 来生成组合
        return list(itertools.combinations(range(1, n + 1), k))