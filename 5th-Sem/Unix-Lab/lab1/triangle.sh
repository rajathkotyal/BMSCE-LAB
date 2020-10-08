echo "TRIANGLE AREA"

echo "\nEnter the base and height of the triangle"
read b
read h
area=$(echo "0.5*$b*$h"|bc)

echo "\nArea of a triangle is :\n$area\n\n"
