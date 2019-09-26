// 成员默认是公有（public）的。使用private访问修饰符可以在类外部隐藏它们。
class Point {
    private var _x = 0 // 私有变量 类外部不可以访问
    private var _y = 0
    private val bound = 100 // 私有常量

    def x = _x // 访问私有变量 getter
    def x_= (newValue: Int): Unit = {
    // setter x_= 是下划线等于
        if (newValue < bound) _x = newValue else printWarning
    }
    
    def y = _y
    def y_= (newValue: Int): Unit = {
        if (newValue < bound) _y = newValue else printWarning
    }

    // 异常处理
    private def printWarning = println("WARNING: Out of bounds")
}

val point1 = new Point
println(point1)

// 成员赋值
point1.x = 99
point1.y = 101 // prints the warning
println(point1)