#!/bin/bash
mkdir lib
cd lib

wget http://www.sfml-dev.org/files/SFML-2.4.0-linux-gcc-64-bit.tar.gz
wget http://www.sfml-dev.org/files/SFML-2.3.2-linux-gcc-64-bit.tar.gz

tar zxvf SFML-2.4.0-linux-gcc-64-bit.tar.gz
tar zxvf SFML-2.3.2-linux-gcc-64-bit.tar.gz

mkdir linux64
mkdir linux64/sfml
mkdir linux64/sfml/2.4.0
mkdir linux64/sfml/2.3.2

mv SFML-2.4.0/* linux64/sfml/2.4.0
mv SFML-2.3.2/* linux64/sfml/2.3.2

rm SFML-2.4.0-linux-gcc-64-bit.tar.gz
rm SFML-2.3.2-linux-gcc-64-bit.tar.gz
