#!/bin/sh

ssh-keygen -A
adduser --disabled-password juhlee
echo "juhlee:juhlee" | chpasswd

rc-status && touch /run/openrc/softlevel
rc-service sshd start

nginx -g "daemon off;"
