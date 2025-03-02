# Check if two arguments are provided
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 <num1> <num2>"
    exit 1
fi

# Perform multiplication and print the result
echo "The product of $1 and $2 is: $(( $1 * $2 ))"
