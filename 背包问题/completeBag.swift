// https://www.jianshu.com/p/d9a0624c05e7
var completelyBag = function(W,V,N){
    let dp = Array(N + 1).fill(0)
    for(let i = 0; i < W.length; i++){
        for(let j = W[i]; j <= N; j++){
            dp[j] = Math.max(V[i] + dp[j - W[i]],dp[j])
        }
    }
    return dp[N]
}

/**
 * 物品对象
 *
 * @param {*} w 物品重量
 * @param {*} v 物品价值
 * @param {*} r 物品价重比
 */
 
function Goods(w,v,r) {
    this.w = w;
    this.v = v;
    this.r = r;
}

var completelyBag2 = function(W,V,N){
    let GoodsArr = []
    for(let i = 0; i < W.length; i++){
        GoodsArr[i] = new Goods(W[i],V[i],V[i]/W[i])
    }

    GoodsArr.sort((a,b) => b.r - a.r)  //将物品按价重比从大到小排序
    let res = 0

    for(let i = 0; i < GoodsArr.length; i++){
        let goods = GoodsArr[i]
        res += Math.floor(N/goods.w)*goods.v
        N = N%goods.w
        if(N == 0) return res
    }
    return res
}
