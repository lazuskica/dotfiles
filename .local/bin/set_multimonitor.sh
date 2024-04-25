#!/usr/bin/sh

xrandr --output  DisplayPort-0 --mode 1280x1024 --pos 0x0 &
sleep 2
xrandr --output HDMI-A-0 --mode 1920x1080 --pos 1280x0 &
sleep 2
nitrogen --restore &
