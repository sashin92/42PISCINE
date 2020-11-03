#!/bin/sh

find . -name "*.sh" | sed 's/\.sh//g' | sed 's/.*\///g'
