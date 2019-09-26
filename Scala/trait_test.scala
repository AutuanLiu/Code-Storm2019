// 特质 (Traits) 用于在类 (Class)之间共享程序接口 (Interface)和字段 (Fields)。 它们类似于Java 8的接口。 
// 类和对象 (Objects)可以扩展特质，但是特质不能被实例化，因此特质没有参数。
// 使用 extends 关键字来扩展特征。然后使用 override 关键字来实现trait里面的任何抽象成员。
trait Iterator[A] {
    def hasNext: Boolean
    def next(): A
}

class IntIterator(to: Int) extends Iterator[Int] {
    private var cnt = 0

    override def hasNext: Boolean = cnt < to
    override def next(): Int =  {
        if (hasNext) {
            val t = cnt
            cnt += 1
            t
        } else -1
  }
}


val iterator = new IntIterator(10)
println(iterator.next()) // 0
println(iterator.next()) // 1
println(iterator.next()) // 2

val iterator1 = new IntIterator(2)
println(iterator1.next())  // 0
println(iterator1.next())  // 1
println(iterator1.next())  // -1