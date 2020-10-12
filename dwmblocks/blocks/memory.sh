#!/bin/sh

memoryString="$(free -h | grep Mem | awk '{printf $3"/"$2" ""%d", (100*$3)/$2}' | tr -t [i] [b])"

printf " $memoryString%%"
