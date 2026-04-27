ifconfig -a | grep ether | grep -o -E '([0-9a-f]{2}:){5}[0-9a-f]{2}'

