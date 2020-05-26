#!/bin/bash
TESTS=unit-tests.c
mkdir -p dist
cd test
mv $TESTS ../src
cd ../src

make -f ../makefile

mv $TESTS ../test
rm -rf *.o
