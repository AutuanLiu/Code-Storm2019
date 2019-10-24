import scala.util.Random

// x是一个0到10之间的随机整数
val x: Int = Random.nextInt(10)

def matchTest(x: Int): String = x match {
  case 0 => "zero"
  case 1 => "one"
  case 2 => "two"
  case _ => "other"
}

println(x)
val ret = matchTest(x)
println(ret)
