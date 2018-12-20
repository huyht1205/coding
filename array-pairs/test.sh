#!/bin/bash

INPUT=input/input00.txt
OUTPUT=output/output00.txt

cat ${INPUT} | ./array-pairs
echo "Expected output: $(cat ${OUTPUT})"
