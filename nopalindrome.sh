#!/bin/bash
read -r -p "Enter a number(atleast two digits): " n
echo "Number: $n"
temp=$n
len=${#n}
rev=0

for((i=$len-1; i>=0; i--))
do
 rem=$(($n % 10))
 n=$(($n / 10))
 rev=$(($rev * 10 + $rem))
done
echo "Reverse: $rev"
if [ $temp -eq $rev ]; then
 echo "$temp is a palindrome"
else
 echo "$temp is not a palindrome"
fi  