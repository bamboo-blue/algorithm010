    解法1：递归
	
	解法二：剪枝递归
	
	解法三：动态规划（自底向上）
本问题其实常规解法可以分成多个子问题，爬第n阶楼梯的方法数量，等于 2 部分之和

爬上 n-1n−1 阶楼梯的方法数量。因为再爬1阶就能到第n阶
爬上 n-2n−2 阶楼梯的方法数量，因为再爬2阶就能到第n阶
所以我们得到公式 dp[n] = dp[n-1] + dp[n-2]dp[n]=dp[n−1]+dp[n−2]
同时需要初始化 dp[0]=1dp[0]=1 和 dp[1]=1dp[1]=1
时间复杂度：O(n)O(n)


class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
	
	解法四：递推（类似动态规划）
	int climbStairs(int n) {
    if (n == 0 ) {
        return 0;
    }
    if (n == 1 ) {
        return 1;
    }
    if (n == 2 ) {
        return 2;
    }   
    
    int one = 1;
    int two = 2;
    int cnt ;
    for(int i = 3; i <= n; i++) {
        cnt = one + two;
        one = two;
        two = cnt;
    }


    return cnt;
    }