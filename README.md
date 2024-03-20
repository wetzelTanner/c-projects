# C Showcase

Welcome to my C Showcase repository! This collection of C projects is designed to demonstrate my proficiency and experience with the C programming language, Makefiles, and Dockerfiles. Each project showcases different aspects of C development, including algorithm implementation, use of multiple data structures, memory allocation, and more.

## Table of Contents
- [Integral Calculator](https://github.com/wetzelTanner/c-projects/tree/main/integral-project)
- [Labs and In-Class Projects](https://github.com/wetzelTanner/c-projects/tree/main/lab-projects)
- [Linked List Memory Allocation Project](https://github.com/wetzelTanner/c-projects/tree/main/linked-list-malloc)
- [Rectangle Project](https://github.com/wetzelTanner/c-projects/tree/main/rectangle-project)
- [Basic C Shell](https://github.com/wetzelTanner/c-projects/tree/main/shell-project)
- [Basic Calculator](https://github.com/wetzelTanner/c-projects/tree/main/user-calc-project)

### Integral Calculator
Description: This project is a command-line calculator that takes three inputs, a low and high midpoint and a desired number of trapezoids, and uses the trapezoidal approximation method to find the integral between the two given inputs. This program includes input validation for both of the endpoint inputs and the number of trapezoids input, as well as the "yes" or "no" input for continuing the program.

Running the Project: This project includes both a Makefile and a Dockerfile.
#### Using Makefile: 
For this approach, the project files must be downloaded locally. After the files are downloaded, use the terminal to change directories to the folder containing the project files. Next, enter these two commands:
```bash
make
```
```bash
./integral
```
#### Using Dockerfile:
For this approach, I have already used the Dockerfile included with the project to create a Docker image, available [here](https://hub.docker.com/r/wetzelt07/integral-calculator). To run the application, run these two commands:
```bash
docker pull wetzelt07/integral-calculator
```
```bash
docker run -it wetzelt07/integral-calculator
```

### Labs and In-Class Projects
Description: This is a collection of a few projects and labs I completed in a Systems Programming class. The first project is a program to calculate voltage and current running through three circuits given an input voltage and resistance in ohms. The second project is a simple two player hangman game where one player inputs a word and the other player will try to guess the word.

Running the Circuit Lab: To run the circuit lab, download the source code and Makefile, then navigate to the directory where the source code is and enter these two commands:
```bash
make
```
```bash
./circuit_lab
```

Running the Hangman Lab: To run the circuit lab, download the source code and Makefile, then navigate to the directory where the source code is and enter these two commands:
```bash
make
```
```bash
./hangman_lab
```
