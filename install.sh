#!/bin/bash
PWD=`pwd`
make
sudo ln -s ${PWD}/SnakeGame /bin/snake
