#!/bin/bash

make

for  g1 in 0.05 0.06 0.07 0.08 0.09 0.10 0.11 0.12 0.13 0.15
do
    for g2 in 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.10
    do
        ./main ${g1}  ${g2}
    done
done
