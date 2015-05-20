#!/bin/bash
PWD=`pwd`
SNAKEPATH="${HOME}/.snake"

make

if [ ! -d ${SNAKEPATH} ]
then
    mkdir ${SNAKEPATH}
fi
echo "Snake wants to create a file score.txt at ${SNAKEPATH} if neccessary please give permission by inserting password"
sudo cp ${PWD}/score.txt ${SNAKEPATH}/score.txt
sudo chmod a+r ${SNAKEPATH}/score.txt
sudo chmod a+w ${SNAKEPATH}/score.txt


if [ ! -f /bin/snake ]
then
    sudo ln -s ${PWD}/SnakeGame /bin/snake
fi
echo
echo "Installed snake! You can now play console snake by simply typing 'snake' in the console"
