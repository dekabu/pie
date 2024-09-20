#!/bin/sh

addpath() {
	if [ $(echo $1 | grep /$) ]; then
		echo $1$2
	else
		echo $1/$2
	fi
}

unset bindir prefix name

for x; do
	if [ $(echo $x | grep =) ]; then
		p1=$(echo $x | cut -d = -f 1)
		p2=$(echo $x | cut -d = -f 2)
		case $p1 in
			--name)
				name=$p2;;
			--prefix)
				prefix=$p2;;
			--bindir)
				bindir=$p2;;
		esac
	fi
done

echo
[ $name ] || name=pie
echo "Name   = $name"

if [ $TERMUX_VERSION ]; then
	system=Termux
elif [ $(uname -a | grep -i mingw) ]; then
	system=MSYS
elif [ $(uname) = Linux ]; then
	system=Linux
else
	echo "Error: unknown system"
fi
echo "System = $system"

if [ ! $prefix ]; then
	if [ $system = Termux ]; then
		prefix=$PREFIX
	else
		prefix=/usr/local
	fi
fi

[ $bindir ] || bindir=$(addpath $prefix bin)
echo "Bindir = $bindir"
echo

echo -n 'Generation Makefile... '

echo "OBJ = src/main.o

$name: \$(OBJ)
	\$(CC) \$(OBJ) \$(CFLAGS) -o $name

run: $name
	./$name

install: $name
	mkdir -p $bindir
	install $name $bindir

uninstall:
	rm $(addpath $bindir $name)

clean:
	rm \$(OBJ)" > Makefile
echo done.

echo
