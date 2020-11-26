echo "FIBONACCI"
read -p "Enter a number : " N

a=0
b=1

echo "The Fibonacci series is : "

for (( i=0; i<N; i++ ))
do
    echo "$a"
    fib=$((a + b))
    a=$b
    b=$fib

done
