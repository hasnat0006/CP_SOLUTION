#!/bin/bash

dir=$1
cd "$dir" || exit

filename=$2
# first char of file name
fc=${filename:0:1}

cnt=1
for i in IO/${fc}_in*.txt; do
	if [ -e "$i" ]; then
		cnt=$((cnt + 1));
	fi
done;

echo -e "\e[31m"[Save and Exit: Enter + Ctrl + D]"\e[0m"
echo -e "\e[42;91mInput $cnt:\e[0m"
cat > tempInp.txt 

echo -e "\e[4mExpected $cnt:\e[0m"
cat > tempExp.txt

cat tempInp.txt > IO/${fc}_in$cnt.txt
cat tempExp.txt > IO/${fc}_exp$cnt.txt

rm tempInp.txt tempExp.txt