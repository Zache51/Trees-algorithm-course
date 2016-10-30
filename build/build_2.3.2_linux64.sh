mkdir target_2.3.2_linux64
cp makefile target_2.3.2_linux64

cd target_2.3.2_linux64

mkdir lib
mkdir lib/sfml

cp -R ../lib/linux64/sfml/2.3.2/* lib/sfml

make

rm makefile
