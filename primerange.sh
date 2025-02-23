#!/bin/bash
echo "Enter the range for prime numbers" 
read n1 
read n2
echo "Lower range: $n1"
echo "Upper range: $n2"
echo "The prime numbers between $n1 and $n2 is:"
for((n=$n1; n<=$n2; n++))
do
 flag=0
 for((i=2; i<=$(($n / 2)); i++))
 do
 if [ $(($n % i)) -eq 0 ]; then
   flag=1
   break
  fi
 done
 if [ $flag -eq 0 ]; then
  echo "$n"
 fi
 done   
   