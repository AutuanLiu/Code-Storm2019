﻿# CMakeList.txt: leetcode_repos 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 项目
project (leetcode_repos)

# 将源代码添加到此项目的可执行文件。
add_executable (leetcode_repos "subsets.cpp" "leetcode_repos.h")

# TODO: 如有需要，请添加测试并安装目标。
