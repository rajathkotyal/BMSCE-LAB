echo "\n---------------EMPLOYEE---------------\n"

echo "\nEnter name of Employee :"
read name

echo "\nEnter DA :"
read da

echo "\nEnter HRA:"
read hra

echo "\nEnter basic"
read basic

sal=$(( $da + $hra + $basic ))

echo "\nGross Salary of $name is $sal"
