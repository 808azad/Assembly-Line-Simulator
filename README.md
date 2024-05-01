# Project: Assembly-Line-Simulator

The purpose of this project is to apply advanced Object-Oriented concepts in C++ to simulate an assembly line with customizable stations. The initial demonstration depicts a line with three stations, as shown in the figure below:

<div align="center">

  ![Assembly Line](assemblyline.jpg)

</div>
The assembly line consists of a set of workstations each of which holds a set of stock items, which are specific to the station. A line manager moves customer orders along the line filling the orders at each station, as requested. Each customer order consists of a list of items that need to be filled. Each station processes a queue of orders by filling the next order in the queue if that order requests the station's item and that item is in stock. The line manager keeps moving the customer orders from station to station until all orders have been processed. Any station that has used all the items in stock cannot fill any more orders. At the end of the line orders are either completed or incomplete due to a lack of inventory at one or more stations. The simulator lists the completed orders and those that are incomplete once the line manager has finished processing all orders.