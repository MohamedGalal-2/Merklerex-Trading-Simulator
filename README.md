# Merklerex Trading Simulator

## Table of Contents
- [About the Course](#About-the-Course)
- [Description](#Description)
- [Resources](#Resources)
- [Repository Structure](#Repository-Structure)
- [Features](#Features)
- [Prerequisites](#Prerequisites)
- [Getting Started](#Getting-Started)
  - [Cloning the Repository](#Cloning-the-Repository)
  - [Compiling the Code](#Compiling-the-Code)
  - [Running the Simulator](#Running-the-Simulator)
- [Usage](#Usage)
- [Contribution](#Contribution)
- [License](#License)

### About the Course
The Object Oriented Programming Specialization offered on Coursera by the University of London is a series of courses that aim to teach the fundamental concepts and techniques of object-oriented programming using the C++ programming language. The specialization consists of five courses.

### Description
This GitHub repository serves as a home for all the code done by me to this project. It includes a step-by-step guide, along with all the necessary code, documentation, and additional resources. The project follows a top-down approach, making it accessible for individuals with various levels of programming knowledge.

### Resources

* [Coursera](https://www.coursera.org/specializations/object-oriented-programming-s12n)

### Repository Structure
* Source Files: This folder contains the .cpp files that contain the code of the project.
* Header Files: This folder contains the .h files that contain the headers of the .cpp files.
* orderBookDataSet.csv: This file is a comma separated values data that's is used to test the project with.

### Features
* Simulate trading activities on the Merklerex platform
* View account balance and market status.
* Perform buy/sell orders.
* Simulate real-time market price fluctuations

### Prerequisites
1. C++ development environment
2. C++ compiler (e.g., GCC, Visual Studio, XCode)
3. Git (optional, for cloning the repository)

### Getting Started
#### Cloning the Repository
To clone the repository, run the following command:

    git clone https://github.com/MohamedGalal-2/Merklerex-Trading-Simulator.git
#### Compiling the Code
Navigate to the project directory and compile the code using the following command:

    g++ -o simulator main.cpp orderBook.cpp MekelMain.cpp colors.cpp orderBookEntry.cpp CSVReader.cpp -std=c++11

#### Running the Simulator
To run the simulator, execute the compiled binary:
    
    ./simulator

### Usage
The simulator provides a command-line interface (CLI) for interacting with the trading platform. Once the simulator is running, you can use various commands to perform trading activities. Here are some examples:
<pre>
1. Print help:
2. Print exchange stats: View the current order book
3. Make an offer: Place a sell order
4. Make a bid: Place a buy order
5. Print wallet: View account balance
6. Jump to the next time frame:
7. Exit: Close the program.
</pre>

### Contribution
Contributions to this repository are always welcome. If you would like to add a new solution or improve an existing one, feel free to submit a pull request. Please ensure that the code adheres to the repository's coding standards.

### License
This repository contains contains my own work during studying this course. Feel free to use for any purpose.
