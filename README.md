

`sudo iptables -t nat -A OUTPUT -o lo -p tcp --dport 80 -j REDIRECT --to-port 8080`
sudo chmod +x /etc/rc.local

`@reboot (ssh -L 80:localhost:8080 -g -N jj22)`
