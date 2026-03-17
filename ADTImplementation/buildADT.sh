#!/bin/bash
ADT=$1
if [[ -z "./${ADT}" ]]
then
    echo "Please enter file name as function argument."
    exit 1
fi
cd "./${ADT}"
if [[ ! -e "${ADT}.h" || ! -e "${ADT}.c" || ! -e "${ADT}Main.c" ]]
then
    echo "Please ensure that ${ADT}.h, ${ADT}.c and ${ADT}Main.c exist."
    exit 1
else
    gcc "${ADT}.h" "${ADT}.c" "${ADT}Main.c" -o $ADT -Wall -Wextra && "./${ADT}"
    cd ..
fi