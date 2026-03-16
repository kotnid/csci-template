#!/bin/bash
filename=$1
if [ -z ${filename} ]
then
    echo "Please enter file name as function argument."
elif [[ ! -e "${filename}.h" || ! -e "${filename}.c" || ! -e "${filename}Main.c" ]]
then
    echo "Please ensure that ${filename}.h, ${filename}.c and ${filename}Main.c exist."
else
    gcc "${filename}.h" "${filename}.c" "${filename}Main.c" -o $filename -Wall -Wextra && "./${filename}"
fi