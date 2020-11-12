# Rajath MK - 1BM18CS079
# 123 Combinations

echo "Combinations for 123 :"
for ((i = 1; i <= 3; i++)); do
    for ((j = 1; j <= 3; j++)); do
        for ((k = 1; k <= 3; k++)); do
            echo $i $j $k
        done
    done
done
