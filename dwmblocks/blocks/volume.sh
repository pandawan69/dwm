#!/bin/sh

volume="$(amixer get Master | grep 'Front Right:' | awk '{print $5}' | tr -d '[%]')"

if [ $volume -gt 70 ] || [ $volume -eq 70 ]; then
	icon=""
elif [ $volume -lt 70 ] && [ $volume -gt 0 ]; then
	icon=""
else
	icon=""
fi

printf "$icon $volume%%"
