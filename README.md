# Multi-channel-splicing_new-method_version-1

1.	Linux 802.11n CSI Tool

1.1	I recommend installing the new version of Linux 802.11n CSI Tool (https://dhalperi.github.io/linux-80211n-csitool/installation.html) since it is easy and faster. It can also keep the Ethernet interface (eth0).

1.2	 If you install the old version of Linux 802.11n CSI Tool, the Ethernet interface (eth0) may be removed. You have to install the driver for Ethernet interface (https://downloadcenter.intel.com/download/15817/Intel-Network-Adapter-Driver-for-PCIe-Intel-Gigabit-Ethernet-Network-Connections-Under-Linux-) (https://blog.csdn.net/zhayushui/article/details/78610490) and add the eth0 (https://askubuntu.com/questions/31023/how-to-configure-eth0-manually).

2.	Set the static IP address

2.1 You can set the static IP address using the same way of adding eth0 (https://askubuntu.com/questions/31023/how-to-configure-eth0-manually)

2.2 Connect the transmitter and receiver with an Ethernet cable (you can test the connection using ping)

3.	Multi-channel splicing_new method

3.1	Run ./restart on both transmitter and receiver to restart the WiFi network

3.2	Run ./setup_scanning on both transmitter and receiver to the setup the CSI tool monitor mode. Note that the channel is 36 now.

3.3	To compile: make

3.4	To remove: make clean

3.5	To use: run ./server on the transmitter; run ./client on the receiver

3.6	On the receiver: open a new terminal and run sudo ./log_to_file csi.dat

3.7	On the transmitter: open a new terminal and run ./random_packets 100000 1 1
