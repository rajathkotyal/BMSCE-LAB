echo "CIRCLE AREA & CIRCUMFERENCE"

echo "\nEnter the radius of a circle : "
read r
d=$(echo "scale=2;2 * $r"|bc) #Diameter

area=$(echo "scale=2; 22/7 * ($r * $r)" | bc)

circumference=$(echo "scale=2; 22/7 * $d"| bc)

echo "\nArea of circle is : $area"
echo "\nCircumference of circle is : $circumference \n"
