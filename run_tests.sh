#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
TEST_DIR="$ROOT_DIR/myTest"

usage() {
  echo "Usage: $0 [file.cc]"
  echo "If no file given, runs all *-clean.cc files in $TEST_DIR"
}

if [[ "${1:-}" == "-h" || "${1:-}" == "--help" ]]; then
  usage
  exit 0
fi

FILES=()
if [[ -n "${1:-}" ]]; then
  FILES=("$1")
else
  shopt -s nullglob
  FILES=("$TEST_DIR"/*-clean.cc)
fi

if [[ ${#FILES[@]} -eq 0 ]]; then
  echo "No test files found." >&2
  exit 1
fi

echo "Found ${#FILES[@]} test(s) to run."

passed=0
failed=0

for f in "${FILES[@]}"; do
  if [[ ! -f "$f" ]]; then
    echo "File not found: $f" >&2
    ((failed++))
    continue
  fi

  echo "\n==> Running test file: $f"
  exe="${f%.*}.test"

  echo "Compiling..."
  if ! g++ -O2 -std=c++17 -Wall -Wextra "$f" -o "$exe"; then
    echo "Compile failed: $f" >&2
    ((failed++))
    continue
  fi

  echo "--- Output ---"
  if "$exe"; then
    echo "--- End ---"
    echo "Result: PASS"
    ((passed++))
  else
    echo "--- End ---"
    echo "Result: FAIL (non-zero exit)"
    ((failed++))
  fi

done

echo "\nSummary: $passed passed, $failed failed"

if [[ $failed -gt 0 ]]; then
  exit 2
fi

exit 0
