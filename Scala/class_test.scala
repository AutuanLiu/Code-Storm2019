// Scala中的类是用于创建对象的蓝图，其中包含了方法、常量、变量、类型、对象、特质、类，这些统称为成员
// 主构造方法中带有val和var的参数是公有的。
// 不带val或var的参数是私有的，仅在类中可见。
class Point(var x: Int = 0, var y: Int = 0) {
    def move(dx: Int, dy: Int): Unit = {
        x = x + dx
        y = y + dy
    }

    // 因为toString覆盖了AnyRef中的toString方法，所以用了override关键字标记
    override def toString: String = {
        s"($x, $y)"
    }
}


val origin = new Point  // x and y are both set to 0
println(origin)

val point1 = new Point(1)
println(point1.x, point1.y)

val point2 = new Point(2, 3)
println(point2)

val point3 = new Point(y=2) // 只给y传参
println(point3) // 2