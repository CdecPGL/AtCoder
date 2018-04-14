#!/bin/bash

clang++ -I/usr/local/include/c++/v1 -L/usr/local/lib -I/opt/boost/clang/include -L/opt/boost/clang/lib -std=c++14 -stdlib=libc++ -O2 -o o $1
