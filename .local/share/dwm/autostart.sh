#!/bin/sh

picom &
dwmblocks &
dbus-run-session pipewire &
wireplumber &
pipewire-pulse &
dropbox start &
/home/lazar/.local/bin/set_multimonitor.sh &
volume_startup.sh &
