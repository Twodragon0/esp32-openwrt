# esp32-openwrt
ESP32-MDF (ESP-Mesh) and OpenWrt Socket using python3

## Install

Install with python3 in OpenWrt:
```sh
opkg update
opkg install python3 git python3-pip
git clone -b v1.0 https://github.com/Twodragon0/esp32-openwrt.git
```
Install with pip:

```sh
pip3 install ipfshttpclient
```

raspberry pi USB storage in OpenWrt:
https://openwrt.org/docs/guide-user/storage/usb-drives

## Socket communication ESP-OpenWrt using python3

1. Socket Communication between ESP32 and OpenWrt
2. Gathering ESP data file
3. We can show ESP Mac address data and message in text file

```sh
python3 socket_server.py
```

## Connect OpenWrt-IPFS using python3

Convert txt file to IPFS (working)

1. Convert txt file to ipfs gateway using Python3
2. Can get IPFS data
3. Convert All ESP data to IPFS

```sh
python3 ipfs_http_client.py
```

Result: IPFS hash
Qm <hash> 
