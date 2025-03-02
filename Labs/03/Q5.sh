# Check if exactly two arguments are provided
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 <source_directory> <backup_directory>"
    exit 1
fi

src="$1"
base_dst="$2"

# Check if the source directory exists
if [[ ! -d "$src" ]]; then
    echo "Error: Source directory '$src' does not exist."
    exit 1
fi

# Create a timestamped backup folder inside the backup directory
timestamp=$(date +"%Y-%m-%d")
dst="$base_dst/backup_$timestamp"

# Ensure the backup directory exists
mkdir -p "$dst"

# Copy all files and subdirectories
cp -r "$src"/* "$dst"/

# Count the number of files and directories backed up
file_count=$(find "$src" -type f | wc -l)
dir_count=$(find "$src" -type d | wc -l)

# Summary of the backup process
echo " Backup completed successfully!"
echo " Source: $src"
echo " Destination: $dst"
echo " Files backed up: $file_count"
echo " Directories backed up: $dir_count"
