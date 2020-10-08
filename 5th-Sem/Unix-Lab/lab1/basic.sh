cat copy.txt
echo "\n1.Created text file  for copying \n"

cp copy.txt ~/Desktop/copied.txt
echo "2. Copied File to Desktop \n"

mkdir inside_lab1 && cd inside_lab1
echo "3.Created & changed to Directory the inside lab1 : \n"

echo "4.Present working Directory :"
pwd

echo "\nShowing inside directory : \n"
ls

echo "Home Dir"
echo $HOME
