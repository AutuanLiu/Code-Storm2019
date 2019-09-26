trait Greeter {
  def greet(name: String): Unit = 
    println("Hello, " + name + "!")
} // 默认实现

// 默认类继承
class DefaultGreeter extends Greeter

// 自定义继承
class CustomizalableGreeter(prefix: String, postfix: String) extends Greeter {
	override def greet(name: String): Unit = {
  	println(prefix + name + postfix)
  }
}

val greeter = new DefaultGreeter()
greeter.greet("Scala") // Hello, Scala!

val greeter1 = new CustomizalableGreeter("Hello, ", "!")
greeter1.greet("Scala") // Hello, Scala!