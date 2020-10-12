#!/bin/sh

volumeString="$(amixer get Master | grep 'Front Right:' | awk '{print $5}' | tr -d '[]' | sed 's/%/%%/g')"

printf "$volumeString"
