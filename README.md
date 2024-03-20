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
./integral.c
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
Description: 
