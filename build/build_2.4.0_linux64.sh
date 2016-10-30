mkdir target_2.4.0_linux64
cp makefile target_2.4.0_linux64

cd target_2.4.0_linux64

mkdir lib
mkdir lib/sfml

cp -R ../lib/linux64/sfml/2.4.0/* lib/sfml

make

rm makefile
