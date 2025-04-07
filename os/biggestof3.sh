

echo "enter 3 number"
read num1
read num2
read num3

if (( num1 > num2 && num1 > num3));then
    echo "num1 greater"
elif (( num2 > num3 ));then
    echo "num2 greater"
else
    echo "num3 greater"
fi