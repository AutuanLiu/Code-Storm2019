// 1. 相当于把内联函数里面的内容写在调用内联函数处；
// 2. 相当于不用执行进入函数的步骤，直接执行函数体；
// 2. 相当于宏，却比宏多了类型检查，真正具有函数特性；
// 2. 编译器一般不内联包含循环、递归、switch 等复杂操作的内联函数；
// 2. 在类声明中定义的函数，除了虚函数的其他函数都会自动隐式地当成内联函数

// 声明1（加 inline，建议使用）
inline int functionName(int first, int second, ...);

// 声明2（不加 inline）
int functionName(int first, int second, ...);

// 定义
inline int functionName(int first, int second, ...){ /****/ };

// 类内定义，隐式内联
class A {
    int doA() { return 0; } // 隐式内联
}

// 类外定义，需要显式内联
class A {
    int doA();
} inline int A::doA() { return 0; } // 需要显式内联