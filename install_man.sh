#!/bin/bash

SOURCE_DIR="./man"

DEST_DIR="/usr/local/share/man"

if [ ! -d "$SOURCE_DIR" ]; then
    echo "Source directory $SOURCE_DIR does not exist."
    exit 1
fi

for section in "$SOURCE_DIR"/man*; do
    if [ -d "$section" ]; then
        section_name=$(basename "$section")
        install_dir="$DEST_DIR/$section_name"
        mkdir -p "$install_dir"
        cp -r "$section"/* "$install_dir"
    fi
done

echo "Manual pages installed successfully."
