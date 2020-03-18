

`sudo iptables -t nat -A OUTPUT -o lo -p tcp --dport 80 -j REDIRECT --to-port 8080`

`@reboot (ssh -L 80:localhost:8080 -g -N -i asdasd root@jj22.de)`
