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
   1)res=$(( $a + $b ))
   ;;
   2)res=$(( $a - $b ))
   ;;
   3)res=$(( $a * $b ))
   ;;
   4)res=$(( $a / $b ))
   ;;
   5)res=$(( $a % $b ))
   ;;
esac
echo "Result : $res"
