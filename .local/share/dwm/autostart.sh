#!/bin/sh

picom -b &
dwmblocks &
dbus-run-session pipewire &
wireplumber &
pipewire-pulse &
dropbox start &
/home/lazar/.local/bin/set_multimonitor.sh &
volume_startup.sh &
eval "$(ssh-agent -s)" &
export WEBOTS_HOME=/home/username/webots
