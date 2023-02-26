#!/bin/bash
architecture=$(uname -a)
lscpu=$(lscpu -p | grep -Ev '^#')
cpu_sockets=$(echo "$lscpu" | sort -u -t, -k 3,3 | wc -l)
cpu_physical=$(echo "$lscpu" | sort -u -t, -k 2,2 | wc -l)
cpu_logical=$(echo "$lscpu" | wc -l)
ram_usage="$(free -m | awk 'FNR == 2 { printf("%d/%dMB", $3, $2) }') $(free | awk 'FNR == 2 { printf("(%.2f%%)", $3/$2*100) }')"
disk_usage_root=$(df -h / | awk 'FNR == 2 { printf("%s/%s (%s)", $3, $2, $5) }')
disk_usage_home=$(df -h /home | awk 'FNR == 2 { printf("%s/%s (%s)", $3, $2, $5) }')
#cpu_util=$(top -bn2 | grep '%Cpu(s):' | tail -n1 | grep -Po '\d+\.\d+(?= id)' | awk '{printf("%s%%", 100 - $1) }')
cpu_util=$(mpstat 2 1 | awk 'END {printf("%s%%", 100 - $12) }')
last_boot=$(who -b | tr -s ' ' | cut -d' ' -f4-5)
lvm_active=$(df | grep -Eq '^/dev/mapper' && echo -n 'yes' || echo -n 'no')
active_connections=$(ss -tu | grep -c 'ESTAB')
#active_users=$(who | cut -d ' ' -f 1 | uniq | wc -l)
active_users=$(who | wc -l)
net_address=$(hostname -I | cut -d' ' -f1)
default_iface=$(ip route show default | cut -d' ' -f5)
mac_address=$(cat /sys/class/net/"$default_iface"/address)
sudo_commands=$(grep -c 'sudo.*COMMAND' /var/log/auth.log)

cat <<EOF
# Architecture: $architecture
# CPU sockets: $cpu_sockets
# CPU cores (physical): $cpu_physical
# CPU cores (logical/virtual): $cpu_logical
# RAM usage: $ram_usage
# Disk usage (/): $disk_usage_root
# Disk usage (/home): $disk_usage_home
# CPU utilization: $cpu_util
# Up since: $last_boot
# LVM active: $lvm_active
# Active network connections: $active_connections
# Active users: $active_users
# Local network address: $net_address ($mac_address)
# sudo invocations: $sudo_commands
EOF
