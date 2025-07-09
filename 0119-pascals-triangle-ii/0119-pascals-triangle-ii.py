class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        triangle = []
        for n in range(rowIndex+1):
            row = [comb(n, k) for k in range(n+1)]
            triangle.append(row)
        return triangle[-1]