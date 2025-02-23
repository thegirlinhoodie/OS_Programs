#!/bin/bash
declare -A X
declare -A Y
declare -A Z
echo "Enter matrix size (mxm)"
read m
echo "Enter matrix X"
for((i=0; i<m; i++))
do
 for((j=0; j<m; j++))
 do
  read X[$i,$j]
 done
done 
echo "Enter matrix Y"
for((i=0; i<m; i++))
do
 for((j=0; j<m; j++))
 do
  read Y[$i,$j]
 done
done 
echo "Matrix X"
for((i=0; i<m; i++))
do
 for((j=0; j<m; j++))
 do
  echo -ne ${X[$i,$j]}
  echo -ne " "
 done
 echo
done 
echo "Matrix Y"
for((i=0; i<m; i++))
do
 for((j=0; j<m; j++))
 do
  echo -ne ${Y[$i,$j]}
  echo -ne " "
 done
 echo
done 
echo "Sum of X and Y"
for((i=0; i<m; i++))
do
 for((j=0; j<m; j++))
 do
  Z[$i,$j]=$((${X[$i,$j]} + ${Y[$i,$j]}))
  echo -ne ${Z[$i,$j]}
  echo -ne " "
 done
 echo
done 