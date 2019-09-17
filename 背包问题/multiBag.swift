// https://www.jianshu.com/p/d9a0624c05e7
var multipleBag = function(W,V,N,nums){
    let dp = Array(N + 1).fill(0)
    for(let i = 0; i < W.length; i++){  
        for(let j = N; j >= w[i]; j--){
            //第i件物品在容量为j的背包里可以带走的最大数量
            let count = Math.min(~~(j/W[i]),nums[i])
            for(let k = 0; k <= count; k++){    
                dp[j] = Math.max(k*V[i] + dp[j - k*W[i]],dp[j])
            }
        }
    }
    return dp[N]
 }