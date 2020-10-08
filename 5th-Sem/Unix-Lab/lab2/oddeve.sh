echo "\n---------------ODD or EVEN---------------\n"

echo "Enter a Number:"
read n

rem=$(( $n % 2 ))

if [ $rem -eq 0 ]
then
    echo "$n is even"
else
    echo "$n is odd"
fi
