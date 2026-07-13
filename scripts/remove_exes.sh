#!/bin/bash
# Script to remove tracked *.exe files from the repository HEAD
# Run this in a local clone of the repository (from the repo root).
# It will remove all tracked .exe files, commit the change, and push to origin main.

set -euo pipefail

# Find tracked .exe files and remove them from git index
files=$(git ls-files '*.exe' || true)
if [ -z "$files" ]; then
  echo "No tracked .exe files found."
  exit 0
fi

echo "Tracked .exe files to remove:"
echo "$files"

# Remove them and commit
# Use --ignore-unmatch so the command succeeds even if some files aren't found
git rm --ignore-unmatch --quiet -- $files

git commit -m "Remove tracked build artifacts (*.exe) from HEAD"

echo "Pushing commit to origin main..."
git push origin main

echo "Done."
