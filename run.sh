#!/bin/bash

g++ -std=c++11 utaman.cpp -o p -lsfml-audio

if [ $? -ne 0 ]; then
  echo "Kesalahan saat kompilasi file C++"
  exit 1
fi

./p


