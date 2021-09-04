#!/usr/bin/env bash 
sudo systemctl start docker
docker container start -i sonix-qmk
