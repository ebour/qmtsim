## Introduction ##

The present version of code available for download was compiled and tested on Ubuntu 8.10 with Qt 4.4 using QDevelop as the IDE. The required project files for compiling in QDevelop are included in the tar.gz file.

Please feel free to communicate the success or failure of compilation/working on other platforms etc.


# Details #

> ## INSTALLING Qt/X11 Version 4.4.0 ##

1.  If you have the commercial edition of Qt, install your license
> file as $HOME/.qt-license.

> For the open source version you do not need a license file.

2.  Unpack the archive if you have not done so already:

> cd /tmp
> gunzip qt-x11-opensource-src-4.4.0.tar.gz        # uncompress the archive
> tar xvf qt-x11-opensource-src-4.4.0.tar          # unpack it

> This creates the directory /tmp/qt-x11-opensource-src-4.4.0 containing the files
> from the archive. We only support the GNU version of the tar
> archiving utility. Note that on some systems it is called gtar.

3.  Building

> To configure the Qt library for your machine type, run the
> ./configure script in the package directory.

> By default, Qt is configured for installation in the
> /usr/local/Trolltech/Qt-4.4.0 directory, but this can be
> changed by using the -prefix option. Alternatively, the
> -prefix-install option can be used to specify a "local"
> installation within the source directory.

> cd /tmp/qt-x11-opensource-src-4.4.0
> ./configure

> Type "./configure -help" to get a list of all available options.

> To create the library and compile all the demos, examples, tools,
> and tutorials, type:

> make

> If you did not configure Qt using the -prefix-install option,
> you need to install the library, demos, examples, tools, and
> tutorials in the appropriate place. To do this, type:

> su -c "make install"

> and enter the root password.

> Note that on some systems the make utility is named differently,
> e.g. gmake. The configure script tells you which make utility to
> use.

> If you need to reconfigure and rebuild Qt from the same location,
> ensure that all traces of the previous configuration are removed
> by entering the build directory and typing

> make confclean

> before running the configure script again.

4.  Environment variables

> In order to use Qt, some environment variables needs to be
> extended.

> PATH               - to locate qmake, moc and other Qt tools

> This is done like this:

> In .profile (if your shell is bash, ksh, zsh or sh), add the
> following lines:

> PATH=/usr/local/Trolltech/Qt-4.4.0/bin:$PATH
> export PATH

> In .login (in case your shell is csh or tcsh), add the following line:

> setenv PATH /usr/local/Trolltech/Qt-4.4.0/bin:$PATH

> If you use a different shell, please modify your environment
> variables accordingly.

> For compilers that do not support rpath you must also extended the
> LD\_LIBRARY\_PATH environment variable to include
> /usr/local/Trolltech/Qt-4.4.0/lib. On Linux with GCC this step
> is not needed.

5.  That's all. Qt is now installed.


## Installing QDevelop ##

**To install QDevelop on Ubuntu, go to the Synaptic Package Manager and find QDevelop   through the find option and select QDevelop and the dependencies to be installed.**

**Installing QDevelop from respository run command:
sudo apt-get install qdevelop**


**To install QDevelop on your Fedora operating system, juste type as root :**

# yum install qdevelop

QDevelop and its dependancies will be installed.

**Installing and building from source
Download is available from http://qdevelop.org, the official website. You need Qt (from Trolltech) at least version 4.2 to be able to compile QDevelop. Most Linux distributions normally already package the latest version of Qt, so it is likely that you don't need to worry about this. However, you need the development package as well (sometimes named as qt-devel or qt4-devel, it varies depending on the distribution). The simplest way to compile QDevelop package is:**

1. Extract the source zip.
2.`cd' to the directory containing the package's source code and type `qmake' (`qmake -recursive' with Qt 4.2.x) to generate the Makefile for your system.
3. Type `make' on Linux or `mingw32-make` on Windows to compile the package.
4. The executable file QDevelop (QDevelop.exe under Windows) is built on bin/ directory. Copy it where you want. It's works alone without other file.

External tools
Required tool
To build QDevelop and after to develop with it, the GNU Compiler Collection, gcc must be installed. Under Linux, simply install the development packages. Under Windows, MinGW - Minimalist GNU for Windows is needed.
Optional tools
External tools used by QDevelop are optional but are strongly recommended to have all functionalities:
Gdb
If you want to have debugging functionalities, you must install gdb. Gdb is normally installed with development packages under Linux. gdb for Windows is available here : http://www.mingw.org/download.shtml/

Ctags
Ctags generates an index (or tag) file of language objects found in source files that allows these items to be quickly and easily located by a text editor or other utility. In QDevelop, Ctags is required to have code completion and class browser. Under Linux, ctags is normally installed with development packages. Under Windows, ctags is available here : http://prdownloads.sourceforge.net/ctags/ec554w32.zip?download. Put the executable in a directory accessible by variable the PATH (the source files are not useful). On some Linux distributions, /usr/bin/ctags is a link to Emacs ctags who is not a good version. In this case, in "External Tools" dialog, set the command to /usr/bin/exuberant-ctags for the ctags field.



## Compiling QMTSim ##

Unpack the tar.gz file.

Open the QMTSim.pro file from QDevelop and ReBuild ALL.

The project should compile smoothly :)

" The wiki will be updated as and when required "
