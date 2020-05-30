#!/bin/bash
if [ -n "$1" ]; then
    TESTS=($1)
else
    TESTS=(array-list-tests linked-list-tests misc-tests queue-tests searching-tests sorting-tests stack-tests)
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
        if [ $? -ne 0 ]; then
            echo ./$TEST failed
            STATUS=1
        fi
    else
        echo ./$TEST failed
        STATUS=1
    fi
done

exit $STATUS
