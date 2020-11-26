read -p "Enter number : " n

i=1
sum=0
echo "Digits : "
while [ $i -le $n ]
  do
   echo "$i"
   sum=$(( $sum + $i ))
        i=$(( $i + 1 ))
  done
echo  "Sum = $sum"
