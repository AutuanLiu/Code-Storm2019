// 特质（trait）和类（class）可以用sealed标记为密封的，
// 这意味着其所有子类都必须与之定义在相同文件中，从而保证所有子类型都是已知的。
sealed abstract class Furniture
case class Couch() extends Furniture
case class Chair() extends Furniture

def findPlaceToSit(piece: Furniture): String = piece match {
  case a: Couch => "Lie on the couch"
  case b: Chair => "Sit on the chair"
}

val x = Couch()
val y = Chair()
println(findPlaceToSit(x))
println(findPlaceToSit(y))
