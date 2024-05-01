# Project: Assembly-Line-Simulator

The purpose of this project is to apply advanced Object-Oriented concepts in C++ to simulate an assembly line with customizable stations. The initial demonstration depicts a line with three stations, as shown in the figure below.

## Demonstration of Assembly Line

<div align="center">

  ![Assembly Line](assemblyline.jpg)

</div>
The assembly line consists of a set of workstations each of which holds a set of stock items, which are specific to the station. A line manager moves customer orders along the line filling the orders at each station, as requested. Each customer order consists of a list of items that need to be filled. Each station processes a queue of orders by filling the next order in the queue if that order requests the station's item and that item is in stock. The line manager keeps moving the customer orders from station to station until all orders have been processed. Any station that has used all the items in stock cannot fill any more orders. At the end of the line orders are either completed or incomplete due to a lack of inventory at one or more stations. The simulator lists the completed orders and those that are incomplete once the line manager has finished processing all orders.

## Compiling and Testing The Program

To compile and test how this program works, use the following command:

```bash
g++ -Wall -std=c++11 -g -o assemblyLine file1.cpp file2.cpp ...
```

## Files To Use
Use the files mentioned below to compile the program:
```Text
Utilities.h
Utilities.cpp
Station.h
Station.cpp
CustomerOrder.h
CustomerOrder.cpp
Workstation.h
Workstation.cpp
LineManager.h
LineManager.cpp
```

## Important Note
To ensure the correct functioning of the application, please specify the provided text files as command line arguments:
```bash
  Command Line: assemblyLine Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
```