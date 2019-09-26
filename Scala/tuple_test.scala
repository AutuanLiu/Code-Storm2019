// 元组解构用于模式匹配
val planetDistanceFromSun = List(
    ("Mercury", 57.9), 
    ("Venus", 108.2), 
    ("Earth", 149.6), 
    ("Mars", 227.9), 
    ("Jupiter", 778.3)
    )

planetDistanceFromSun.foreach { tuple => {
    tuple match {
        case ("Mercury", distance) => println(s"Mercury is $distance millions km far from Sun")
        case p if(p._1 == "Venus") => println(s"Venus is ${p._2} millions km far from Sun")
        case p if(p._1 == "Earth") => println(s"Blue planet is ${p._2} millions km far from Sun")
        case _ => println("Too far....")
        }
    }
}

// 使用 for 表达式
val numPairs = List((2, 5), (3, -7), (20, 56))

for ((a, b) <- numPairs) {
  println(a * b)
}