# `CMakeLists.txt` 书写规范

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

## 编译步骤

```bash
$ cmake .
$ make
$ make install
```

## rules

1. 参数之间使用空格分隔
2. 函数名和参数之间使用空格分隔
3. CMakeLists.txt 的语法比较简单，由命令、注释和空格组成
4. 命令是不区分大小写的
5. 符号 # 后面的内容被认为是注释。命令由命令名称、小括号和参数组成
6. 多目录 每个目录都要写一个 CMakeLists.txt


## reference
1. [CMake 入门实战 | HaHack](https://www.hahack.com/codes/cmake/)