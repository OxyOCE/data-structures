#!/bin/bash
if [ -n "$1" ]
then
    TESTS=($1)
else
    TESTS=(array-list-tests misc-tests quicksort-tests simple-algorithms-tests)
fi

cd dist

for TEST in ${TESTS[@]}; do
    ./$TEST
done
