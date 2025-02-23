#!/bin/bash
read -r -p "Enter the size of array" n
echo "Enter array of size $n"
for((i=0; i<n; i++))
do
 read arr[i]
done
echo "${arr[*]}"
max=${arr[0]}
for((i=1; i<n; i++))
do
 if [ ${arr[$i]} -gt $max ]; then
  max=${arr[$i]}
 fi
done
echo "Largest: $max"  