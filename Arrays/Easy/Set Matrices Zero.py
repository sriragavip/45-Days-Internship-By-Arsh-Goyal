class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        r,c = len(matrix), len(matrix[0])
        loc = defaultdict(set)
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    loc["r"].add(i)
                    loc["c"].add(j)
                    
        for m in list(loc["r"]):
            matrix[m] = [0]*c
           
        for l in matrix:
            for val in list(loc["c"]):
                if l[val] != 0:
                    l[val] = 0
        
        return matrix