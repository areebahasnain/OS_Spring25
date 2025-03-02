# Check if exactly one argument is provided
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"

# Check if the file exists
if [[ ! -f "$filename" ]]; then
    echo "Error: File does not exist."
    exit 1
fi

# Append current date and time to the file
echo "$(date)" >> "$filename"
echo "Date and time appended to $filename"
