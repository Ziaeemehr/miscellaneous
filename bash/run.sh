#!/bin/sh


#for i in `seq 1 5`
#do 
#   echo ${i}
#done

i=20
end=30
while [ $i -le $end ]
do
  echo $i
  i=$(($i+1))
done
