# ASCII Value Finder 
This is a simple GUI Application made in C with GTK which finds ASCII Value of the alphabet you choose

## Image
![Screenshot 2022-11-01 165650](https://user-images.githubusercontent.com/85222136/199222936-774690c6-e976-428c-a972-17419395a795.png)

## Languages Used
> C

## How to Use
* Download and install **C (gcc compiler)** *(if not installed)*
* Clone the repository
* Install **GTK** for gcc compiler - 
[Visit Here to know how to install and setup gtk](https://www.gtk.org/docs/installations/windows)
* Now Compile the application by -
```bash
cd src

gcc `pkg-config --cflags gtk+-3.0` main.c -o main `pkg-config --libs gtk+-3.0`
```
* After the .exe file is generated, you can run the application

#### Hope you enjoy