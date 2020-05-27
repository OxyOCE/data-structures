#!/bin/bash

if [ "$1" == "clean" ]
then
    rm -rf dist
    rm -rf src/*.o
    exit 0
fi

if [ -n "$1" ]
then
    TESTS=($1)
else
    TESTS=(array-list-tests misc-tests sorting-tests searching-tests)
fi

mkdir -p dist
cd test

for TEST in ${TESTS[@]}; do
    mv $TEST.c ../src
done

cd ../src

for TEST in ${TESTS[@]}; do
    make TEST=$TEST -f ../makefile
done

for TEST in ${TESTS[@]}; do
    mv $TEST.c ../test
done
