#!/bin/bash

# Get the directory and filename from the arguments
dir=$1
filename=$2
# first char of file name
fc=${filename:0:1}



# Navigate to the specified directory
cd "$dir" || exit

# Compile the .cpp file
g++ -std=c++17 "$filename.cpp" -Wall -DONPC -o "$filename"

# Run the tests
cnt=1
for i in "IO/${fc}_in"*.txt; do
    ./"$filename" < "$i" > "IO/${fc}_out$cnt.txt"
    sed -i 's/[ \t]*$//' "IO/${fc}_out$cnt.txt"
    if ! cmp -s "IO/${fc}_out$cnt.txt" "IO/${fc}_exp$cnt.txt"; then
        echo -e "\e[101mError in test $cnt!\e[0m"
        echo -e "\e[103;100mInput\e[0m"
        cat "$i"
        echo -e "\e[41mWrong Output\e[0m"
        cat "IO/${fc}_out$cnt.txt"
        echo -e "\e[44;33mCorrect Output\e[0m"
        cat "IO/${fc}_exp$cnt.txt"
    else
        echo -e "\e[42;97mPassed $cnt\e[0m"
    fi
    cnt=$((cnt+1))
done

# all the file created by this script will be deleted
rm "IO/${fc}_out"*.txt
rm "$filename"
