object Main {
  def main(args: Array[String]): Unit = {
    println("Hello, Scala!")
    if (args.length > 0) {
      println(args(0)) // 命令行参数
    }
  }
}

// 运行命令
// scala main_object.scala