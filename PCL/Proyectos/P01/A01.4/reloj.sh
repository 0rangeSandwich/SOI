count=1

while [ -n "$1" ]; do
     sleep $1
     echo "$count"
     count=$(($count + 1))
done
