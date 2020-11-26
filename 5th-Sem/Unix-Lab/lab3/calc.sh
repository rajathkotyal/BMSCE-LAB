echo "\n--------------------CALCULATOR--------------------\n"

echo "Enter 2 Numbers : "
read a
read b

echo "Enter Operation : \n"
echo "1) Addition"
echo "2) Subtraction"
echo "3) Multiplication"
echo "4) Division(Quotient)"
echo "5) Modulus(Remainder)\n"
read op

case $op in
   1)echo "scale=3; $a + $b" | bc -l
   ;;
   2)echo "scale=3; $a - $b" | bc -l
   ;;
   3)echo "scale=3; $a \* $b" | bc -l
   ;;
   4)echo "scale=3; $a / $b" | bc -l
   ;;
   5)echo "scale=3; $a % $b" | bc -l
   ;;
   *)echo "Choose a valid option"
esac
