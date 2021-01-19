#!/bin/sh
# export EXTERNAL_IP=$(/tmp/get_external_ip_addresses.sh nginx)

ssh-keygen -A
adduser --disabled-password juhlee
echo "juhlee:juhlee" | chpasswd

rc-status && touch /run/openrc/softlevel
rc-service sshd start

nginx -g "daemon off;"
