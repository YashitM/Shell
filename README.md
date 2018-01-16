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

Execute Internal and External Commands *with some flags*. A detailed description is given below:
* External Commands:
    * ```ls``` : List directory contents
        * ```-a``` : Do not ignore entries starting with .
        * ```-m``` : Fill width with a comma separated list of entries

* Internal Commands:    
    * ```cd``` : Change Directory. Implemented using the ```chdir()``` function in C.
        * ```cd /``` : Move to the Root Directory
        * ```cd -``` : Move to the previously visited directory. Implemented by reading (and altering) the ```OLDPWD``` Enviroment Variable.
        * ```cd ~``` : Move to the Home Directory. The Home Directory location is read from the ```HOME``` Environment Variable. 
    * ```echo``` : Display a line of text. Implemented by simply parsing the input and displaying the result. 
        * ```-n``` : Do not output the trailing newline
        * ```-E``` : Disable interpretation of backslash escapes
    * ```pwd``` : Print name of current/working directory. This is implemented using the ```getcwd()``` function.
    * ```history``` : Display all the previously executed commands in the shell. Implemented by keeping a ```history_file.txt``` to which all of the commands executed are appended.
        * ```-c``` : Clear the contents of the Histort File.
    * ```exit``` : Exit from the Shell.
 
* mkdir
* rm
* cat
* date

## Working

* Internal Commands
    * These commands are executed within the main file. The user input is parsed and then executed based on the source code in the ```shell.c``` file.

* External Commands
    * These commands are executed externall from the binaries that are stored in ```binaries/``` directory. The use of ```execvp()``` is done so as to create a child process and to execute the external binary.

* Other Commands
    * Commands other than the ones mentioned above can also be executed in the shell. The External Commands will be executed using the default binaries (used by the shell). Again, so as to execute these commands, a child process is created using ```execvp()``` and the command given by the user is executesd. After the completion, the control is given back to the shell.

### Note

The main binary ```shell```, is to be kept in the same directory as the ```C``` files. The other binaries, are stored in the ```binaries``` folder.