# Quantum
![GitHub last commit](https://img.shields.io/github/last-commit/ProgGoose5/Quantum)
![GitHub issues](https://img.shields.io/github/issues/ProgGoose5/Quantum)
![GitHub pull requests](https://img.shields.io/github/issues-pr/ProgGoose5/Quantum)
![GitHub repo size](https://img.shields.io/github/repo-size/ProgGoose5/Quantum)

Quantum, its a file manager meant to be similar to dolphin but using a Text User Interface.
My main objetive is to push myself as far I can before starting to use GUIs. 
As Goosey, this will be build almost completly in C.

Installation:

First, Clone the repo.
```
$ git clone https://github.com/ProgGoose5/Quantum 
```
Then, go to the Quantum file and create the "build" directory.
```
$ cd ~/Quantum && mkdir build
```
Done that, enter into build and call Cmake.
```
$ cd ~/Quantum/build && cmake .. 
```
Finally, call make.
```
$ sudo make
```
You can use quantum by calling it in your terminal
```
$ Quantum
```
Buttons are:
F1= Going back a Dir
F3= Entering a Dir
F5= Change selected area
