echo "RECTANGLE AREA"

echo "\nEnter the length and breadth of the Rectangle"
read l
read b
area=$(echo "$l*$b"|bc)

echo "\nArea of rectangle is :\n$area \n"
