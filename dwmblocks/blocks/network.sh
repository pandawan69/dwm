#!/bin/sh

ethStatus="$(cat /sys/class/net/enp0*/operstate)"
# wifiStatus="$(cat /sys/class/net/w*/operstate)"

if [ $ethStatus = "up" ]; then
	printf " Ethernet"
else
	printf " Disconnected"	
fi

