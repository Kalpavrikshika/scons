# SCons
Hacking with SCons 

## What's SCons?

> SCons is an Open Source software construction tool—that is, a next-generation build tool. Think of SCons as an improved, cross-platform substitute for the classic Make utility with integrated functionality similar to autoconf/automake and compiler caches such as ccache. In short, SCons is an easier, more reliable and faster way to build software.

## Setting up SCons

### Building from source - Ubuntu.

At the time of this writing the latest version of SCons is 3.0.1

Ensure Python is installed locally

```bash
sudo mkdir /opt/src   
cd /opt/src/
sudo wget http://prdownloads.sourceforge.net/scons/scons-3.0.1.tar.gz 
sudo tar -xvzf scons-3.0.1.tar.gz
cd scons-3.0.1/
sudo python setup.py install
```

Other installation options can be found from [this link](http://scons.org/doc/HTML/scons-user.html#chap-build-install)

```bash
scons -v 
# SCons by Steven Knight et al.:
#        script: v3.0.1.74b2c53bc42290e911b334a6b44f187da698a668, 2017/11/14 13:16:53, by bdbaddog on hpmicrodog
#       engine: v3.0.1.74b2c53bc42290e911b334a6b44f187da698a668, 2017/11/14 13:16:53, by bdbaddog on hpmicrodog
#        engine path: ['/usr/local/lib/scons-3.0.1/SCons']
# Copyright (c) 2001 - 2017 The SCons Foundation
```

### Up and Running

```bash
cd /myproject && sudo mkdir helloscons && cd helloscons
echo '#include <stdio.h> int main(){ printf("Hello SCons\n");}' > app.c
echo "Program('app.c')" > SConstruct
scons
# scons: Reading SConscript files ...
# scons: done reading SConscript files.
# scons: Building targets ...
# gcc -o app.o -c app.c
# gcc -o app app.o
# scons: done building targets. 
./app 
# Hello SCons

```

### Deep dives 

Learn more from the user guide from [this link](http://scons.org/doc/HTML/scons-user.html)