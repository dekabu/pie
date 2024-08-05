#!/bin/sh

addpath() {
	if [ `echo $1 | grep /$` ]; then
		echo $1$2
	else
		echo $1/$2
	fi
}

for x; do
	case $x in
		-v | --version)
			echo 0.1.0beta
			exit;;
		-h | --help)
			echo Бог спасёт.
			exit
	esac
done

for x; do
	if [ `echo $x | grep =` ]; then
		p1=`echo $x | cut -d = -f 1`
		p2=`echo $x | cut -d = -f 2`
		case $p1 in
			--prefix)
				prefix=$p2;;
			--bindir)
				bindir=$p2
		esac
	fi 
done

echo
if [ $TERMUX_VERSION ]; then
	system=Termux
elif [ `uname | grep -i mingw` ]; then
	system=MSYS
elif [ `uname` = Linux ]; then
	system=Linux
fi
echo "System = $system"

if [ ! $prefix ]; then
	if [ $system = Termux ]; then
		prefix=$PREFIX
	else
		prefix=/usr/local
	fi
fi

[ $bindir ] || bindir=`addpath $prefix bin`
echo "Bindir = $bindir"
echo

echo -n 'Generation config.h... '
echo -n '#define PIE_' > src/config.h
if [ $system = MSYS ]; then
	echo WINDOWS >> src/config.h
else
	echo UNIX >> src/config.h
fi
echo '#define PIE_COLOR 1' >> src/config.h
echo -n '#define PIE_ANSI  ' >> src/config.h
if [ $system = MSYS ]; then
	echo 0 >> src/config.h
else
	echo 1 >> src/config.h
fi
echo done.

echo -n 'Generation Makefile... '
echo "OBJ = src/obj/obj.o \\
      src/init/init.o \\
			src/main.o

pie: \$(OBJ)
	\$(CC) \$(OBJ) \$(CFLAGS) -o pie

run: pie
	./pie

install: pie
	mkdir -p $bindir
	install pie $bindir

uninstall: `addpath $bindir pie`
	rm `addpath $bindir pie`

clean:
	rm \$(OBJ)" > Makefile
echo done.
echo
