// 通过混入来组合类
abstract class AbsIterator {
    type T
    def hasNext: Boolean
    def next(): T
}


class StringIterator(s: String) extends AbsIterator {
    type T = Char
    private var i = 0
    def hasNext: Boolean = i < s.length
    def next(): T = {
        val ch = s charAt i
        i += 1
        ch
    }
}


trait RichIterator extends AbsIterator {
    def foreach(func: T => Unit): Unit = while (hasNext) func(next())
}


object StringIteratorTest extends App {
    class RichStringIter extends StringIterator("Scala") with RichIterator
    val richStringIter = new RichStringIter
    richStringIter foreach println
}
