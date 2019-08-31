# `makefile.txt` 书写规范

```makefile
# 指定运行此配置文件所需的 CMake 的最低版本
cmake_minimum_required (VERSION 3.8)

# 项目名称
project (leetcode_repos)

# 将源代码添加到此项目的可执行文件。
# 将源文件编译成一个名称为 leetcode_repos 的可执行文件
add_executable (leetcode_repos "couples.cpp" "leetcode_repos.h")

# TODO: 如有需要，请添加测试并安装目标。
```

```makefile
# 指定运行此配置文件所需的 CMake 的最低版本
cmake_minimum_required (VERSION 3.8)

# 项目名称
project (leetcode_repos)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(leetcode_repos ${DIR_SRCS})

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library (MathFunctions ${DIR_LIB_SRCS})
```

```makefile
#1.cmake verson，指定cmake版本
 cmake_minimum_required(VERSION 3.2)

 #2.project name，指定项目的名称，一般和项目的文件夹名称对应
 PROJECT(test_sqrt)

 #3.head file path，头文件目录
 INCLUDE_DIRECTORIES(include)

 #4.source directory，源文件目录
 AUX_SOURCE_DIRECTORY(src DIR_SRCS)

 #5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
 SET(TEST_MATH ${DIR_SRCS})

 #6.add executable file，添加要编译的可执行文件
 ADD_EXECUTABLE(${PROJECT_NAME} ${TEST_MATH})

 #7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
 TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)
 ```


## 编译步骤

```bash
$ cmake .
$ make
$ make install
```

## rules

1. 参数之间使用空格分隔
2. 函数名和参数之间使用空格分隔
3. makefile.txt 的语法比较简单，由命令、注释和空格组成
4. 命令是不区分大小写的
5. 符号 # 后面的内容被认为是注释。命令由命令名称、小括号和参数组成
6. 多目录 每个目录都要写一个 makefile.txt


## reference
1. [CMake 入门实战 | HaHack](https://www.hahack.com/codes/cmake/)
