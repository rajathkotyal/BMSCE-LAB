# 1BM18CS079 - Rajath MK
# Even Numbers Sum

sum=0
read -p "Enter maximum limit of Even Numbers : " m


for ((i = 0; i < m; i++)); do
    if [[ $i%2 -eq 0 ]]; then
        sum=$(expr $sum + $i)
    fi
done

echo $sum
