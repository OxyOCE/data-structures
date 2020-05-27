#!/bin/bash
if [ -n "$1" ]; then
    TESTS=($1)
else
    TESTS=(array-list-tests misc-tests sorting-tests searching-tests)
fi

if [ -d dist ]; then
    cd dist
else
    exit 1;
fi

STATUS=0

for TEST in ${TESTS[@]}; do
    if [ -f $TEST ]; then
        ./$TEST
    else
        echo ./$TEST failed
        STATUS=1
    fi
done

exit $STATUS
