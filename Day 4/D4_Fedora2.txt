echo "Who are you?"
read name
echo "Enter Number 1"
read x
echo "Enter Number 2" 
read y
echo "Enter Number 3"
read z

sum=$(($x + $y + $z))
avg=$((sum/3))

echo "Hi" $name
echo "Summation: $sum" 
echo "Average: $avg"