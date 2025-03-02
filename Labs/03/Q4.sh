# Check if exactly one argument is provided
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <file/dir name>"
    exit 1
fi

item="$1"

# Check if the file or directory exists
if [[ ! -e "$item" ]]; then
    echo "Error: $item does not exist."
    exit 1
fi

# Display file/directory properties
stat -c "Name: %n; Size: %s bytes; Owner: %U; Group: %G; Permissions: %A; Last modified: %y" "$item"

# If it's a directory, list its contents
if [[ -d "$item" ]]; then
    echo "Contents:"
    ls -l "$item"
fi
