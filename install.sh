#!/bin/bash
PWD=`pwd`
make

if [ ! -d /home/.snake ]
then
    sudo mkdir /home/.snake
fi
sudo cp score.txt /home/.snake/score.txt
sudo chmod a+r /home/.snake/score.txt
sudo chmod a+w /home/.snake/score.txt


if [ -f /bin/snake ]
then
    sudo rm /bin/snake
fi
sudo ln -s ${PWD}/SnakeGame /bin/snake
