# 1BM18CS079 - Rajath MK
# Power of a number

echo "POWER PROGRAM"
read -p "Enter the base number : " a
read -p "Enter the power : " b

res=1

for ((i = 1; i <= b; i++)); do
    res=$(expr $res \* $a)
done

echo $res
