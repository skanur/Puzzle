#!/bin/bash

set -e

if [ "$#" -ne 2 ]; then
    echo "The script needs 2 arguments"
    echo "Supply same arguments you give to puzzlediff_cpp"
    echo "Usage ./measure.sh ref_pic ref_pic_or_folder"
    exit 1
fi

use parallelstudio
export CC=icc CXX=icpc
rm -rf build
pushd .
mkdir -p build
cd build 
cmake ..
make
popd

build/puzzlediff_cpp/puzzlediff_cpp $1 $2 & # Wait until it finishes
pid=$!
pidstat -I -u -p $pid 1

# Additional info
# sysstat - http://sebastien.godard.pagesperso-orange.fr/documentation.html
# sar - http://sebastien.godard.pagesperso-orange.fr/man_sar.html
# LICENSE:
# This is free and unencumbered software released into the public domain.
# Anyone is free to copy, modify, publish, use, compile, sell, or
# distribute this software, either in source code form or as a compiled
# binary, for any purpose, commercial or non-commercial, and by any
# means.
# 
# In jurisdictions that recognize copyright laws, the author or authors
# of this software dedicate any and all copyright interest in the
# software to the public domain. We make this dedication for the benefit
# of the public at large and to the detriment of our heirs and
# successors. We intend this dedication to be an overt act of
# relinquishment in perpetuity of all present and future rights to this
# software under copyright law.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.
# For more information, please refer to <http://unlicense.org/>
