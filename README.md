# Shell

A basic Shell that can run various Internal and Exeternal commands.

## Getting Started

### Prerequisites
* GCC Compiler
```
sudo apt-get install gcc
```

To fire up the Shell, type:
```
make
chmod +x shell
./shell
```

## Functions

Execute Internal and External Commands *with some flags*. Some of them are mentioned below:
* ls
    * Flags Implemented:
        * ```-a```: Do not ignore entries starting with .
        * ```-m```: Fill width with a comma separated list of entries

* cd
* mkdir
* rm
* cat   
* pwd
* history
* date
* echo
* exit

### Note

The main binary ```shell```, is to be kept in the same directory as the ```C``` files. The other binaries, are stored in the ```binaries``` folder.