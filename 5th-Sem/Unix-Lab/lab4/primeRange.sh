echo "This progrm will generate prime number from range x to y"
echo "Enter number x"
read x
echo "Enter number y"
read y
echo -e  "\nLets Generate Prime Number"
while [[ $x -le $y ]]
do
if [[ $x -le 2 ]]
then
    continue
fi

let LIMIT=$x-1

for ((a=2; a <= LIMIT ; a++))
        do
                let check=$x%$a
                if [[ $check -eq 0 ]]
                then
                        #echo "$x is not prime"
                        break
                fi
        done

if [[ $a -gt $LIMIT ]]
then
        echo "$x is a prime number"
fi
let x=$x+1
done
