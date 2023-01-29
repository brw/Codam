#!/bin/bash
architecture=$(uname -a)
physical_cpu=$()
ram_usage="$(free -m | awk 'FNR == 2 { printf("%d/%dMB", $3, $2) }') $(free | awk 'FNR == 2 { printf("(%.2f%%)", $3/$2*100) }')"
disk_usage="$(df -m / | awk 'FNR == 2 { print $3 }')/$(df -B 1GB / | awk 'FNR == 2 { print $2 }')GB"
cpu_load=$(top -bn2 | grep "%Cpu(s):" | tail -n1 | grep -Po '\d+\.\d+(?= id)' | echo -n "$(awk '{print 100 - $1}')%")
last_boot=$(who -b | tr -s ' ' | cut -d' ' -f4-5)
lvm_active=$(df | grep -q mapper && echo -n 'yes' || echo -n 'no')
active_connections=$(ss -tu | tail +2 | wc -l)
active_users=$(who | cut -d " " -f 1 | uniq | wc -l)
net_address=$(hostname -I | cut -d' ' -f1)
mac_address=$(cat /sys/class/net/enp0s3/address)
sudo_commands=$(grep -a sudo ~/.bash_history | wc -l)

cat <<EOF
# Architecture: $architecture
# Physical CPU: $physical_cpu
# RAM usage: $ram_usage
# Disk usage: $disk_usage
# CPU load: $cpu_load
# Last boot: $last_boot
# LVM active: $lvm_active
# Active connections: $active_connections
# Active users: $active_users
# Local network address: $net_address ($mac_address)
# sudo commands executed: $sudo_commands
EOF
