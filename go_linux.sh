#!/usr/bin/bash

if [ $(uname -o) != "GNU/Linux" ]; then
  echo "only linux!"
  exit 1
fi

top_dir=$(dirname $0)
cd "$top_dir"
entry_point=main
cmake -S . -B build
if [ $? -ne 0 ]; then
    echo "CMake Config fail"
    exit 1
fi

cmake --build build 
if [ $? -ne 0 ]; then
    echo "CMake Build fail"
    exit 1
fi
# https://github.com/microsoft/vscode/issues/179274
(unset GTK_PATH;
$(find . -executable -name "${entry_point}")) &

