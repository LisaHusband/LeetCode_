class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []
        for n in range(numRows):
            row = [comb(n, k) for k in range(n+1)]
            triangle.append(row)
        return triangle