echo "PRIME RANGE"
read -p "Enter lower limit : " x
if [[ $x -le 1 ]]
then
    echo "Enter Lower Limit greater than 1"
    exit
fi
read -p "Enter upper limit : " y

echo "\nPrime Numbers : "
while [[ $x -le $y ]]
do

let LIMIT=$x-1

for ((a=2; a <= LIMIT ; a++))
        do
                let check=$x%$a
                if [[ $check -eq 0 ]]
                then
                        break
                fi
        done

if [[ $a -gt $LIMIT ]]
then
        echo "$x"
fi
let x=$x+1
done
