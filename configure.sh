#!/bin/sh

addpath() {
	if [ $(echo $1 | grep /$) ]; then
		echo $1$2
	else
		echo $1/$2
	fi
}

for x in $@; do
	if [ $(echo $x | grep =) ]; then
		case $(echo $x | cut -d = -f 1) in
			--prefix)
				prefix=$(echo $x | cut -d = -f 2)
				;;
			--bindir)
				bindir=$(echo $x | cut -d = -f 2)
		esac
	else
		case $x in
			-v | --version)
				echo 0.0.1
				exit
		esac
	fi
done

echo -n 'system = '
if [ $TERMUX_VERSION ]; then
	system=Termux
elif [ $(uname | grep Linux) ]; then
	system=Linux
elif [ $(uname | grep MSYS) ]; then
	system=MSYS
fi
echo $system

echo -n 'prefix = '
if [ ! $prefix ]; then
	if [ $system = Termux ]; then
		prefix=$PREFIX
	else
		prefix=/usr/local
	fi
fi
echo $prefix

echo -n 'bindir = '
if [ ! $bindir ]; then
	bindir=$(addpath $prefix bin)
fi
echo $bindir

echo 'config.h generation...'
echo -n '#define ' > src/config.h
if [ $system = MSYS ]; then
	echo 'WINDOWS' >> src/config.h
else
	echo 'LINUX' >> src/config.h
fi
echo "
#define COLOR_INPUT 1" >> src/config.h
echo "#define PROMPT1     \"In [%n] >> \"" >> src/config.h
echo "#define PROMPT2     \"Out[%n] >> \"" >> src/config.h

echo 'Makefile generation...'
echo "OBJ = src/base/base.o \\
       src/life/life.o \\
       src/lex/lex.o \\
			 src/main/main.o

pie: \$(OBJ)
	\$(CC) \$(OBJ) -o pie

run: pie
	./pie

install: pie
	mkdir -p $bindir
	install pie $bindir

clean:
	rm \$(OBJ)

remove:
	rm pie

allclean: clean remove
	rm src/config.h
	rm Makefile

uninstall:
	rm $(addpath $bindir pie)" > Makefile

echo Successfully!
