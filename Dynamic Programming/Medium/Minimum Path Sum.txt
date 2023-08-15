class Solution {
    public int minPathSum(int[][] grid) {
       int m= grid.length;
        int n=grid[0].length;
        int memo[][]=new int[m][n];
        return find(grid,m-1,n-1,memo);  
    }
    public static int find(int [][]grid,int m,int n,int memo[][]){
        if (m==0&&n==0) return grid[m][n];
        else if (m<0||n<0) {
            return Integer.MAX_VALUE;
        } else if (memo[m][n]!=0) {
            return memo[m][n];
        }
        return memo[m][n]=grid[m][n]+Math.min(find(grid,m-1,n,memo),find(grid,m,n-1,memo));
    }
}