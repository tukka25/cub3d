#! /bin/bash

make fclean

git commit -am "$1"
git push origin exec