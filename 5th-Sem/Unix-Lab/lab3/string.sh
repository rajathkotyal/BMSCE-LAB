echo "\n--------------------STUDENT MARKS--------------------\n"
read -p "Enter first string: " s1
read -p "Enter second string: " s2

if [[ "$s1" == "$s2" ]]; then
    echo "Strings are equal."
else
    echo "Strings are not equal."
fi
