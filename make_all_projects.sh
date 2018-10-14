#!/bin/bash
set -e
dirlist=$(find . -mindepth 1 -maxdepth 1 -type d)

for dir in $dirlist
do
(
    if [ "$dir" = "./.circleci" ] || [ "$dir" = "./.git" ] || [ "$dir" = "./.vscode" ]; then
        continue
    fi
    cd $dir
    echo $dir
    if [ "$1" == "clean" ]; then
        make clean
    else
        find . -name "CMakeLists.txt" -exec cmake . \;
        make
    fi

    if [ $? -ne 0 ]; then
        echo "break!"
        exit 1
    fi
)
done
echo "done"

