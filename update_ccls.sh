#!/usr/bin/env bash

dir=$(dirname $0)
ccls="$dir/.ccls"

echo "clang" > "$ccls"
wx-config --cflags | tr ' ' '\n' >> "$ccls"
