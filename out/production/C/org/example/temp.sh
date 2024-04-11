#!/bin/bash

# Basic Arithmetic operations
a=10
b=5
sum=$((a + b))
sub=$((a - b))
mul=$((a * b))
div=$((a / b))

echo "Sum: $sum"
echo "Subtraction: $sub"
echo "Multiplication: $mul"
echo "Division: $div"

# Command line arguments
echo "First Argument: $1"
echo "Second Argument: $2"

# Control statements - if else
if [ $a -gt $b ]; then
    echo "$a is greater than $b"
else
    echo "$b is greater than $a"
fi

# Loops - for, while, until, break, continue
for ((i=1; i<=5; i++)); do
    echo "For Loop Iteration $i"
done

num=1
while [ $num -le 5 ]; do
    echo "While Loop Iteration $num"
    ((num++))
done

num=1
until [ $num -gt 5 ]; do
    echo "Until Loop Iteration $num"
    ((num++))
done

for ((i=1; i<=10; i++)); do
    if [ $i -eq 6 ]; then
        break
    fi
    echo "Break Loop Iteration $i"
done

for ((i=1; i<=10; i++)); do
    if [ $i -eq 5 ]; then
        continue
    fi
    echo "Continue Loop Iteration $i"
done

# Functions
greet() {
    echo "Hello, $1!"
}

greet "Alice"
greet "Bob"

# Arrays
fruits=("Apple" "Banana" "Orange")
echo "Fruits: ${fruits[@]}"

# String functions
string="Hello, World!"
echo "Length of string: ${#string}"
echo "Substring: ${string:7:5}"
echo "Uppercase: ${string^^}"
echo "Lowercase: ${string,,}"
