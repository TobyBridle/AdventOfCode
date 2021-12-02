#!/bin/bash

# Compile Our Program
clear && gcc -o main.o main.c

# Curl into ./input.txt if doesn't exist
FILE=./input.txt
if [[ ! -f "$FILE" ]]; then
  echo "Fetching from https://adventofcode.com/2021/day/1/input"
  curl 'https://adventofcode.com/2021/day/1/input' \
    -H 'authority: adventofcode.com' \
    -H 'pragma: no-cache' \
    -H 'cache-control: no-cache' \
    -H 'sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="96", "Google Chrome";v="96"' \
    -H 'sec-ch-ua-mobile: ?0' \
    -H 'sec-ch-ua-platform: "macOS"' \
    -H 'upgrade-insecure-requests: 1' \
    -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.55 Safari/537.36' \
    -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9' \
    -H 'sec-fetch-site: same-origin' \
    -H 'sec-fetch-mode: navigate' \
    -H 'sec-fetch-user: ?1' \
    -H 'sec-fetch-dest: document' \
    -H 'referer: https://adventofcode.com/2021/day/1' \
    -H 'accept-language: en-GB,en-US;q=0.9,en;q=0.8' \
    -H 'cookie: session=SESSION_CODE' \
    --compressed > $FILE
fi
# Run Code with Input as File
# If you want to copy the output, run ./build.sh | pbcopy 
./main.o input.txt
