#!/bin/sh

picom -b &
dwmblocks &
dbus-run-session pipewire &
/home/lazar/.local/bin/set_multimonitor.sh &
wireplumber &
pipewire-pulse &
dropbox start &
volume_startup.sh &
#pkill xfce4-notifyd &
eval "$(ssh-agent -s)" &
export WEBOTS_HOME=/home/username/webots &
setxkbmap -layout "us,rs,rs" -variant "basic,basic,latin" -option grp:alt_shift_toggle &
ferdium &

