#!/bin/sh

ifconfig | grep -a "ether " | tr -d '[:blank:]' | sed 's/ether//g'
