# Shell

A basic Shell that can run various Internal and Exeternal commands.

## Getting Started

### Prerequisites
* GCC Compiler

```sudo apt-get install gcc```
### Run
To fire up the Shell, type:
```
make
chmod +x shell
./shell
```

## Functions

Execute Internal and External Commands *with some flags*. A detailed description is given below:
* External Commands:
    * ```ls``` : List directory contents.
        * Flags: 
            * ```-a``` : Do not ignore entries starting with .
            * ```-m``` : Fill width with a comma separated list of entries
        * Implementation:
            * Using the ```opendir()``` and ```readdir()``` functions in the ```dirent.h``` library.
        * Usage:
            * ```ls -a```
            * ```ls```
    * ```mkdir``` : Make Directories.
        * Flags:
            * ```-v``` : Print a message for each created directory.
            * ```-m``` : Set file mode (as in chmod).
        * Implementation:
            * Using the ```mkdir()``` function in C.
        * Additional Features:
            * Any number of folders can be created in a single command (Along with the implementation of flags). Eg: ```mkdir -v dir1 dir2```
        * Usage:
            * ```mkdir -v new_folder```
            * ```mkdir temp```
    * ```rm``` : Remove Files or Directories.
        * Flags:
            * ```-v``` : Explain what is being done.
            * ```-d``` : Remove empty directories.
        * Implementation:
            * Using the ```remove()``` function in C.
        * Additional Features:
            * Any number of files/folders can be removed in a single command (Along with the implementation of flags). Eg: ```rm -v dir1 dir2```
        * Usage:
            * ```rm -d directory```
            * ```rm file```
    * ```cat``` : Concatenate files and print on the standard output
        * Flags:
            * ```-n``` : Number all output lines.
            * ```-E``` : display ```$``` at the end of each line.
            * ```-nE``` or ```-En``` : display ```$``` at the end of each line and Number all the output lines.
        * Implementation:
            * By simply parsing the input and reading the files using ```fopen()``` and ```fgetc()``` functions in C.
        * Additional Features:
            * ```cat <multiple files separated using space>``` will read out the contents of all the files mentioned.
        * Usage:
            * ```cat hello.txt```
            * ```cat -nE hello.txt``` 
    * ```date``` : Print the System Date and Time.
        * Flags:
            * ```-R``` : Output Date and Time in RFC 2822 format.
            * ```-u``` : Output Date and Time in UTC format.
        * Implementatin:
            * Using the ```asctime()``` and ```strftime()``` functions in ```time.h``` library.
        * Usage:
            * ```date -R```
            * ```date -u```
* Internal Commands:
    * ```cd``` : Change Directory.
        * Additional Features:
            * ```cd``` : Move to the Home Directory. The Home Directory location is read from the ```HOME``` Environment Variable.
            * ```cd /``` : Move to the Root Directory
            * ```cd -``` : Move to the previously visited directory. Implemented by reading (and altering) the ```OLDPWD``` Enviroment Variable.
            * ```cd ~``` : Move to the Home Directory. The Home Directory location is read from the ```HOME``` Environment Variable. 
        * Implementation:
            * Using the ```chdir()``` function.
        * Usage:
            * ```cd dirname```
            * ```cd ~```
    * ```echo``` : Display a line of text.
        * Flags:
            * ```-n``` : Do not output the trailing newline
            * ```-E``` : Disable interpretation of backslash escapes
        * Implementation:
            * By simply parsing the input and displaying the result. ```" or '``` in String is also taken care of.
        * Usage:
            * ```echo "Hello"```
            * ```echo -n Hello```
    * ```pwd``` : Print name of current/working directory.
        * Implementation:
            * Using the ```getcwd()``` function.
        * Usage:
            * ```pwd```
    * ```history``` : Display all the previously executed commands in the shell. 
        * Flags:
            * ```-c``` : Clear the contents of the Histort File.
            * ```<number>``` : Print the last ```<number>``` contents of the file.
        * Implementation:
            * By keeping a ```history_file.txt``` to which all of the commands executed are appended.
        * Usage:
            * ```history 10```
            * ```history -c```
    * ```exit``` : Exit from the Shell.

## Working

There is an outer ```while``` loop which keeps the Shell Running. The user input is first parsed and split into a ```char``` array which is passed onto the ```if``` conditions that execute the commands.
* Internal Commands
    * These commands are executed within the main file. The user input is parsed and then executed based on the source code in the ```shell.c``` file.

* External Commands
    * These commands are executed externall from the binaries that are stored in ```binaries/``` directory. The use of ```execvp()``` is done so as to create a child process and to execute the external binary.

* Other Commands
    * Commands other than the ones mentioned above can also be executed in the shell. The External Commands will be executed using the default binaries (used by the shell). Again, so as to execute these commands, a child process is created using ```execvp()``` and the command given by the user is executesd. After the completion, the control is given back to the shell.
Extensive error handling is done for each command.

### Note

* The main binary ```shell```, is to be kept in the same directory as the ```C``` files. The other binaries, are stored in the ```binaries``` folder. It is thus suggested to use the provied ```Makefile```, as it takes care of this. 
* Multiple flags in a single command will not execute.
* Commands like ```cd, rm, mkdir``` will not work if there are Spaces in the File/Directory Name.