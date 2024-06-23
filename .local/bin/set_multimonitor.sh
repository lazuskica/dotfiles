#!/usr/bin/sh

xrandr --output  DisplayPort-0 --mode 1920x1080 --pos 0x0 -r 100 & 
sleep 1
xrandr --output HDMI-A-0 --mode 1920x1080 --pos -1920x0 &
#sleep 2
nitrogen --restore &
