// 凡是需要特质的地方，都可以由该特质的子类型来替换。
// 能调用pet.name的前提是它必须在特质Pet的子类型中得到了实现。
import scala.collection.mutable.ArrayBuffer

trait Pet {
    val name: String
}

class Cat(val name: String) extends Pet
class Dog(val name: String) extends Pet

val dog = new Dog("Harry")
val cat = new Cat("Sally")

val animals = ArrayBuffer.empty[Pet]
animals.append(dog)
animals.append(cat)
animals.foreach(pet => println(pet.name))  // Harry Sally