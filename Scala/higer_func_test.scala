// 高阶函数是指使用其他函数作为参数、或者返回一个函数作为结果的函数。
val salaries = Seq(20000, 70000, 40000)
val doubleSalary = (x: Int) => x * 2
val newSalaries = salaries.map(doubleSalary)
println(newSalaries)

// 匿名函数
val salaries1 = Seq(20000, 70000, 40000)
val newSalaries1 = salaries1.map(x => x * 2)
println(newSalaries1)

// 精简匿名函数
val salaries2 = Seq(20000, 70000, 40000)
val newSalaries2 = salaries2.map(_ * 2)
println(newSalaries2)

// 返回函数
// urlBuilder的返回类型是(String, String) => String，这意味着返回的匿名函数有两个String参数，返回一个String。
def urlBuilder(ssl: Boolean, domainName: String): (String, String) => String = {
    val schema = if (ssl) "https://" else "http://"
    // 要返回的函数
    (endpoint: String, query: String) => s"$schema$domainName/$endpoint?$query"
}

val domainName = "www.example.com"
def getURL = urlBuilder(ssl=true, domainName)
val endpoint = "users"
val query = "id=1"
val url = getURL(endpoint, query)
println(url) // https://www.example.com/users?id=1
