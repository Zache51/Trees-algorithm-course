mkdir target_linux64
cp makefile target_linux64

cd target_linux64

mkdir lib

wget http://www.sfml-dev.org/files/SFML-2.3.2-linux-gcc-64-bit.tar.gz
tar xzvf SFML-2.3.2-linux-gcc-64-bit.tar.gz
mv SFML-2.3.2 lib/sfml
rm SFML-2.3.2-linux-gcc-64-bit.tar.gz

make

rm makefile
