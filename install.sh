#!/bin/bash
PWD=`pwd`
make

if [ -f /bin/snake ]
then
    sudo rm /bin/snake
fi
sudo ln -s ${PWD}/SnakeGame /bin/snake
