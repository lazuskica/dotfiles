#!/bin/bash

# Get current keyboard layout
layout=$(setxkbmap -v | awk -F + '/symbols/ {print $2}')

# Depending on the keyboard layout, run one of three commands
case $layout in
    "us")
        echo "eng"
        ;;
    "rs")
	echo "срб"
        ;;
    "rs(latin)")
        echo "srb"
        ;;
esac
