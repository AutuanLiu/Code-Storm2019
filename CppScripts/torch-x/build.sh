#!/bin/bash

#!/bin/bash

if [ -d build ]; then
    echo "building ..."
else
    echo "creating dir ..."
    mkdir build
    echo "building ..."
fi

# cmake
cd build
cmake -DCMAKE_PREFIX_PATH=/home/lyc/Softwares/libtorch ..
make

