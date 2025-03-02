echo "Enter a sentence:"
read sentence

# Convert sentence to lowercase to handle uppercase vowels
sentence=$(echo "$sentence" | tr 'A-Z' 'a-z')

# Count vowels using grep and wc
vowel_count=$(echo "$sentence" | grep -o '[aeiou]' | wc -l)

echo "Number of vowels in the sentence: $vowel_count"

