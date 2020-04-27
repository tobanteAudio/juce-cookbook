#!/usr/bin/env sh

# 1. Extract only the headers via grep (using $1 and $2 as first and last heading level)
grep -E "^#{${1:-1},${2:-2}} " |   \
# 2. Extract the header text via sed and created ':' separated records of the form '###:Full Text:Full Text'
sed -E 's/(#+) (.+)/\1:\2:\2/g' |   \
# 3. Compose each TOC line via awk by replacing '#' with '  ' and stripping spaces and caps of reference
awk -F ":" '{ gsub(/#/,"  ",$1); gsub(/[ ]/,"-",$3); print $1 "- [" $2 "](#" tolower($3) ")" }'
