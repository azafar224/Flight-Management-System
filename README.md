Flight Management System

This program is a flight management system that allows users to create, view, update, and delete flights. The program stores flight information in an array and flight data in a file.

How to use
The program menu provides the following options:

Create Flight
Delete Flight
Update Flight
View Flights
Exit
To create a flight, select option 1 and enter the flight information, including flight number, origin, destination, departure time, and arrival time. The program will store the flight information in an array.

To delete a flight, select option 2 and enter the flight number of the flight you want to delete. The program will delete the flight from the array.

To update a flight, select option 3 and enter the flight number of the flight you want to update. The program will prompt you to enter the new flight information and update the flight in the array.

To view the list of flights, select option 4. The program will display the flight information of all the flights that have been created.

To exit the program, select option 5.

The program also includes a file management system that allows users to store and retrieve flight data. The file management system menu provides the following options:

Create file
Delete file
View files
Exit
To create a file, select option 1 and enter the file name, file extension, and file data. The program will store the file information and file data in separate arrays. The program can store up to 10 files.

To delete a file, select option 2 and enter the file name and file extension of the file you want to delete. The program will delete the file and its associated data from the arrays.

To view the list of files, select option 3. The program will display the file names and file extensions of all the files that have been created.

To exit the file management system, select option 4.

Code explanation
The program is written in C++ and consists of a main function and several helper functions. The helper functions include:

FlightInfo: Initializes the flight information array with -1 values.
createFlight: Creates a new flight and stores the flight information in the array.
deleteFlight: Deletes a flight from the array.
updateFlight: Updates a flight in the array.
viewFlights: Displays the list of flights that have been created.
saveToFile: Saves flight data to a file.
readFromFile: Reads flight data from a file.
FileInfo: Initializes the file information array with -1 values.
FileData: Initializes the file data array with -1 values.
createFile: Creates a new file and stores the file information and file data in the arrays.
deleteFile: Deletes a file and its associated data from the arrays.
viewFile: Displays the list of files that have been created.
The program uses two structures to store flight information and file information. The FlightInfo structure includes the flight number, origin, destination, departure time, and arrival time. The FileInfo structure includes the file name, file extension, starting index, and file index.

The program limits the number of flights that can be created to 10 and limits the amount of data that can be stored in a file to 1000 characters. If the program runs out of space in either array, it will display an error message.
