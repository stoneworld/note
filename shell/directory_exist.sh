#!/bin/bash
jump_directory=/home/arthur
if [ -d $jump_directory ]; then
    echo "The $jump_directory directory exists"
else
    echo "The $jump_directory directory does not exist"
fi

# for 循环
file="shell.md"
IFS.OLD=$IFS
IFS=$'\n'
for state in $(cat $file)
do
    echo "$state"
done
IFS=$IFS.OLD #重置IFS默认值

# while 循环

var1=10
while [ $var1 -gt 0 ]
do
    echo $var1
    var1=$[ $var1 - 1 ]
done
