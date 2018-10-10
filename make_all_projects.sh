#!/bin/bash
dirlist=$(find $1 -mindepth 1 -maxdepth 1 -type d)

for dir in $dirlist
do
(
    if [ "$dir" = ".circleci" ]; then
        continue
    fi
    cd $dir
    echo $dir
    make
)
done
