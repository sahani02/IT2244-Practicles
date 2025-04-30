//Exercise, read two numbers from user and print addition, substration, multiplications and division
echo "Enter number 1: "
read x
echo "Enter number 2: "
read y

addition=$(($x+$y))
substraction=$(($x-$y))
multiplication=$(($x*$y))
division=$(($x/$y))

echo "Addition: $addition"
echo "Substraction: $substraction"
echo "Multiplication: $multiplication"
echo "Division: $division"
