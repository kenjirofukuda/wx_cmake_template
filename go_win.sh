#!/usr/bin/bash

top_dir=$(dirname $0)
cd "$top_dir"
entry_point=main
cmake -S . -B build -G "Visual Studio 16 2019" -A x64 
if [ $? -ne 0 ]; then
    echo "CMake Config fail"
    exit 1
fi

cmake --build build
if [ $? -ne 0 ]; then
    echo "CMake Build fail"
    exit 1
fi

$(find . -executable -name "${entry_point}.exe") &
