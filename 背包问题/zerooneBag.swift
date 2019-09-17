// https://www.jianshu.com/p/d9a0624c05e7
var zeroOneBag = function(W,V,N){
    let dp = Array(N + 1).fill(0)
    for(let i = 0; i < W.length; i++){
        for(let j = N; j >= w[i]; j--){
            dp[j] = Math.max(V[i] + dp[j - W[i]],dp[j]) 
        }
    }
    return dp[N]
}