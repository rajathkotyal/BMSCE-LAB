echo "\n---------------GREATEST OF 2---------------\n"

echo "Enter first number : "
read num1
echo "Enter second number : "
read num2

if [ $num1 -gt $num2 ]
then
    echo "\n$num1 is the greater than $num2"
else
    echo "\n$num2 is the greater than $num1"
fi
