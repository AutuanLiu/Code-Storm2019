#!/bin/bash

if [ -d build ]; then
    echo "building ..."
else
    echo "creating dir ..."
    mkdir build
    echo "building ..."
fi

if [ -d data ]; then
    echo " Mnist is exist."
else
    echo "download mnist."
    mkdir data
    cd data

    # download mnist
    urls=(
        "http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz"
        "http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz"
        "http://yann.lecun.com/exdb/mnist/t10k-images-idx3-ubyte.gz"
        "http://yann.lecun.com/exdb/mnist/t10k-labels-idx1-ubyte.gz"
        )

    for item in ${urls[@]}; do
        curl -O ${item}
    done

    # 解压
    for item in `ls`; do
        gunzip ${item}
    done

    # 退出
    cd ..
fi


# cmake
cd build
cmake -D CMAKE_PREFIX_PATH=/home/lyc/Softwares/libtorch ..
make
