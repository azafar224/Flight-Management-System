**Flight Management System**

This is a Flight Management System implemented in C++ that allows you to manage the arrival, departure, and emergency handling of flights. The system uses queues and a priority queue (emergency queue) to organize and process the flights.

**Features**

Arrival of flights: You can enter the details of an arriving flight, including fuel quantity, destination, arrival date, and arrival time.
Departure of flights: You can enter the details of a departing flight, including fuel quantity, destination, flight status, scheduled date, and scheduled time.
Emergency handling: If a flight has low fuel (less than 40 units), it will be automatically added to the emergency queue.
Confirmation for landing and takeoff: You can confirm the landing or takeoff of flights. The system dequeues flights from the landing or takeoff queues accordingly.
Display reports: You can view reports of the flights, including arrival and departure details.
User-friendly menu: The system provides a menu with options to perform various operations.

**Requirements**

C++ compiler

**Getting Started**

Clone the repository and navigate to the project directory.
Compile the code using a C++ compiler.
Run the compiled executable file.

**Usage**

Upon running the program, you will be presented with a menu displaying the available options.
Enter the corresponding number to select an option:

1: Arrival - Enter the arrival flight ID and its details.

2: Departure - Enter the departure flight ID and its details.

3: Emergency - Enter the flight ID of an emergency situation.

4: Confirmation for Landing and Takeoff - Confirm the landing or takeoff of flights.

5: Display Reports - View reports of the flights.

6: Exit - Exit the program.

Follow the prompts to provide the required information for each option.

Continue selecting options until you choose to exit the program.

**Notes**

The system uses two landing queues (landingQueue1 and landingQueue2) and two takeoff queues (takeoffQueue1 and takeoffQueue2) to manage the incoming and outgoing flights.
Flights with low fuel are automatically added to the emergency queue for priority handling.

The system keeps track of various flight details, such as fuel quantity, destination, flight status, arrival time, departure time, waiting time, and runway ID.

Feel free to explore and enhance this Flight Management System according to your requirements!
