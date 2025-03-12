#!/bin/bash

# Prompt user for input
echo "Enter a sentence:"
read sentence

# Convert sentence to lowercase (optional, but makes matching easier)
sentence=$(echo "$sentence" | tr '[:upper:]' '[:lower:]')

# Initialize vowel count
vowel_count=0

# Loop through each character in the sentence
for (( i=0; i<${#sentence}; i++ )); do
    char=${sentence:$i:1}  # Extract each character
    if [[ "$char" =~ [aeiou] ]]; then
        ((vowel_count++))  # Increment count if it's a vowel
    fi
done

# Print the result
echo "Number of vowels in the sentence: $vowel_count"

