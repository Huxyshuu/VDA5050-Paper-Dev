raspberrypi@raspberrypi:~ $ ip route
default via 192.168.1.1 dev eth0 proto dhcp src 192.168.1.115 metric 1002 
default via 192.168.0.1 dev wlan0 src 192.168.0.116 metric 3003 
10.210.1.12 via 192.168.0.1 dev wlan0 
192.0.0.0/8 dev eth0 proto dhcp scope link src 192.168.1.115 metric 1002 
192.168.0.0/24 dev wlan0 proto dhcp scope link src 192.168.0.116 metric 3003 

raspberrypi@raspberrypi:~ $ cat /lib/dhcpcd/dhcpcd-hooks/99-custom-routes
#!/bin/sh

case "$reason" in
    BOUND|STATIC|REBOOT|REBIND|RENEW)
        [ "$interface" = "wlan0" ] || exit 0

        ip route replace 10.210.1.12/32 via 192.168.0.1 dev wlan0
        ;;
esac

raspberrypi@raspberrypi:~ $ sudo chmod +x /lib/dhcpcd/dhcpcd-hooks/99-custom-routes
raspberrypi@raspberrypi:~ $ sudo systemctl restart dhcpcd
