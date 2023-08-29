#!/bin/bash


target=$((RANDOM % 100 + 1))

echo "Welcome to the Number Guessing Game!"
echo "I have selected a random number between 1 and 100."
echo "Try to guess the number!"

while true; do
    read -p "Enter your guess: " guess

    if ((guess < target)); then
        echo "Your guess is too low. Try again."
    elif ((guess > target)); then
        echo "Your guess is too high. Try again."
    else
        echo "Congratulations! You guessed the correct number: $target"
        break
    fi
done
