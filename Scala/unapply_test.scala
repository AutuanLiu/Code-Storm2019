// 提取器对象
import scala.util.Random

object CustomerID {
  def apply(name: String) = s"$name--${Random.nextLong}"

  def unapply(customerID: String): Option[String] = {
    val stringArray: Array[String] = customerID.split("--")
    if (stringArray.tail.nonEmpty) Some(stringArray.head) else None
  }
}

// 当我们调用 CustomerID("Sukyoung") ，其实是调用了 CustomerID.apply("Sukyoung") 的简化语法。
// 当我们调用 case CustomerID(name) => println(name)，就是在调用提取器方法。
val customer1ID = CustomerID("Sukyoung")
println(customer1ID)

customer1ID match {
  case CustomerID(name) => println(name)  // prints Sukyoung
  case _ => println("Could not extract a CustomerID")
}
