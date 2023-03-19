#include<iostream>
using namespace std;

#define size 5			//size of queues
int k = 0;			//counter for Arrival Flight Details 
int l = 0;
int m = 0;			//initializing counters for storing information regarding flights arrivals and departures
int n = 0;

//functions decleration
bool isEmpty ();
bool isFull ();
bool enqueueFlights (int number, int status);
int dequeueFlights (int n);
void arrivalFlightsDetails ();
void departureFlightsDetails ();
void displayReports ();
void fuelCheck ();
void timeArrivalDeparture (int status);

//Struct used for information regarding flight arrival
struct arrivalDeparture
{
  int flightId, fuel, runwayId;
  char destination[10], flightStatus[10];
  struct Time
  {
    int hours, min;
  } arrivalTime, landingTime, waitingTime, scheduleTime, actualTime;

  struct Date
  {
    int day, mon;
  } arrivalDate, scheduleDate, actualDate;

} arrivalFlightDetails[5], departureFlightDetails[5];

//Stack for implementing Emergency queue/priority queue.
struct stack
{
  int queue1[size], queue2[size], top1, top2;
} stack;

// Queue for adding flights in queues.
struct queue
{
  int queues[size];
  int front, tail, counter;
}
landingQueue1 =
{
0}, landingQueue2 =

{
0}, takeoffQueue1 =

{
0}, takeoffQueue2 =

{
0}, emergencyQueue =

{
0};


// Main Method
int
main ()
{
  char ch;
  int flightId;

  cout << "-------FLIGHT MANAGEMENT SYSTEM--------------" << "\n";
a:
  cout << "\nPress...\n1.Arrival\n2.Departure\n3.Emergency\n4.Confirmation for Landing and Takeoff\n5.Display Reports\n6.Exit\n";	//Menu Displaying
  cout<<"Enter your choice:\t";
  cin >> ch;
  switch (ch)
    {
    case '1':
      {
	 cout << "\nPlease Enter Arrival Flight ID: " << "\t";
	 cin  >> flightId;
	 arrivalFlightDetails[k].flightId = flightId;
	 arrivalFlightsDetails ();
	 enqueueFlights (flightId, 1);
	 fuelCheck ();
	 break;
    }
    case '2':
      {
	  cout << "\nPlease Enter Departure Flight ID: " << "\t";
	  cin >> flightId;
	  departureFlightDetails[n].flightId = flightId;
	  departureFlightsDetails ();
      enqueueFlights (flightId, 2);
	  break;
    }
    case '3':
      {
	    cout << "\nPlease Enter the Flight ID that is in Emergency: " << "\t";
	    cin >> flightId;
	    enqueueFlights (flightId, 3);  
	    break;                       
      }
    case '4':
      {
	    cout << "\nPress-->\n1:Landing Confirmation\n2:Takeoff Confirmation\n" << "\n";	//dequeue flights from landing and takeoff queues
	    cin >> ch;
	    if (ch == '1')
	   {
	     dequeueFlights (1);
	   }
	  else if (ch == '2')
	   {
	     dequeueFlights (2);
	   }
	 break;
      }
     case '5':
      {
	   displayReports ();
	   break;
       }
    case '6':
      {
	cout << "\nDo you want to display today's Reports of Flights?(Y/N):"
	  << "\t";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	  {
	    displayReports ();
	  }
	else if (ch == 'N' || ch == 'n')
	  {
	    exit (0);
	  }
	break;
      }
    default:
      cout << "\nWrong Command!" << "\n";
    }
  goto a;			//using jump statement
}


void
fuelCheck ()
{				//Checking Fuel quantity
  if (k >= 0)
    {
      for (int i = 0; i <= k; i++)
	{
	  arrivalFlightDetails[i].fuel = arrivalFlightDetails[i].fuel - 10;
	  if (arrivalFlightDetails[i].fuel < 40)
	    {			//if fuel is less than 40 flight will be transferred to emergency/priority
	      cout <<
		"\nFlight is added to Emergency Queue due to less Fuel\n";
	      enqueueFlights (arrivalFlightDetails[i].flightId, 3);
	    }
	}
    }
  k++;
}


void
arrivalFlightsDetails ()
{				//Setting Reports for Flights Arrival
  cout << "\nPlease Enter the Following details of Arrival Flight" << "\n";
  cout << "\nFuel: " << "\t";
  cin >> arrivalFlightDetails[k].fuel;
  cout << "\nDestination: " << "\t";
  cin >> arrivalFlightDetails[k].destination;

b:
  cout << "\nArrival Date (Format D/M): " << "\n";
  cin >> arrivalFlightDetails[k].arrivalDate.day,
    arrivalFlightDetails[k].arrivalDate.mon;
  if (arrivalFlightDetails[k].arrivalDate.day > 31
      || arrivalFlightDetails[k].arrivalDate.mon > 12)
    {
      cout << "\nWRONG FORMAT ...PLEASE ENTER THE CORRECT ONE.." << "\n";
      goto b;
    }

a:
  cout << "\nArrival Time (Format H:M (24 Hours)): " << "\t";
  cin >> arrivalFlightDetails[k].arrivalTime.hours,
    arrivalFlightDetails[k].arrivalTime.min;
  if (arrivalFlightDetails[k].arrivalTime.hours > 24
      || arrivalFlightDetails[k].arrivalTime.min > 60)
    {				//Checking time format
      cout <<
	"\nYou entered wrong time in wrong format!,Enter time in the provided format (Format H:M (24 Hours))";
      goto a;
    }
}

void
departureFlightsDetails ()
{				//Setting Reports for Flights Departure
  cout << "\nPlease Enter the Following details:\n";
  cout << "\nFuel:\t";
  cin >> departureFlightDetails[n].fuel;
  cout << "\nDestination: \t";
  cin >> departureFlightDetails[n].destination;
  cout << "\nFlight Status: \t";
  cin >> departureFlightDetails[n].flightStatus;
c:
  cout << "\nScheduled Date (Format D/M): ";
  cin >> departureFlightDetails[n].scheduleDate.day,
    departureFlightDetails[n].scheduleDate.mon;
  if (departureFlightDetails[n].scheduleDate.day > 31
      || departureFlightDetails[n].scheduleDate.mon > 12)
    {				//checking date validity
      cout <<
	"\nYou entered date in wrong format! Please enter the correct one\n";
      goto c;
    }
b:
  cout << "\nScheduled Time (Format H:M):";
  cin >> departureFlightDetails[n].scheduleTime.hours,
    departureFlightDetails[n].scheduleTime.min;
  if (departureFlightDetails[n].scheduleTime.hours > 24
      || departureFlightDetails[n].scheduleTime.min > 60)
    {				//Checking time validity
      cout <<
	"\nYou entered time in wrong format!, Please enter time in the provided format (Format H:M (24 Hours))";
      goto b;
    }

}


void
timeArrivalDeparture (int status)
{				//Setting Report for landing and Waiting time for arrival flights
  if (status == 1)
    {
    a:
      cout << "\nEnter Landing Time(Format H:M):";
      cin >> arrivalFlightDetails[l].landingTime.hours,
	arrivalFlightDetails[l].landingTime.min;
      if (arrivalFlightDetails[k].landingTime.hours > 24
	  || arrivalFlightDetails[k].landingTime.min > 60)
	{			//Checking time validity
	  cout <<
	    "\nYou entered time in wrong format! please enter time in the provided format (Format H:M (24 Hours))";
	  goto a;
	}

      arrivalFlightDetails[l].waitingTime.hours = arrivalFlightDetails[l].arrivalTime.hours - arrivalFlightDetails[l].arrivalTime.hours;	//waiting time for flight arrival 
      arrivalFlightDetails[l].waitingTime.hours =
	arrivalFlightDetails[l].arrivalTime.min -
	arrivalFlightDetails[l].arrivalTime.min;
      l++;
    }
  else if (status == 2)
    {
    b:
      cout << "\nEnter Actual Time of Departure(Format H:M):";
      cin >> departureFlightDetails[m].actualTime.hours,
	departureFlightDetails[m].actualTime.min;
      if (arrivalFlightDetails[k].actualTime.hours > 24
	  || arrivalFlightDetails[k].actualTime.min > 60)
	{			//Checking time format
	  cout <<
	    "\nYou entered time in wrong format! Please enter time in the provided format (Format H:M (24 Hours))";
	  goto a;
	}
      departureFlightDetails[m].waitingTime.hours = departureFlightDetails[m].scheduleTime.hours - departureFlightDetails[m].scheduleTime.hours;	//waiting time for departure of flights
      departureFlightDetails[m].waitingTime.hours =
	departureFlightDetails[m].scheduleTime.min -
	departureFlightDetails[m].scheduleTime.min;
      m++;
    }
}

bool
enqueueFlights (int number, int status)
{				//Making queues for flights
  if (isFull ())
    {
      cout << "\nQueue is FULL!\n";
      return false;
    }
  if (status == 1)
    {
      if (landingQueue1.counter <= landingQueue2.counter)
	{			//Landing Queue 1
	  arrivalFlightDetails[k].runwayId = 1;
	  landingQueue1.queues[landingQueue1.tail++] = number;
	  landingQueue1.counter++;
	}
      else if (landingQueue1.counter > landingQueue2.counter)
	{			//Landing Queue 2
	  arrivalFlightDetails[k].runwayId = 2;
	  landingQueue2.queues[landingQueue2.tail++] = number;
	  landingQueue2.counter++;
	}

    }
  else if (status == 2)
    {
      if (takeoffQueue1.counter <= takeoffQueue2.counter)
	{			//Takingoff Queue 1
	  departureFlightDetails[n].runwayId = 1;
	  takeoffQueue1.queues[takeoffQueue1.tail++] = number;
	  takeoffQueue1.counter++;
	}
      else if (takeoffQueue1.counter > takeoffQueue2.counter)
	{			//Takingoff Queue 2
	  departureFlightDetails[n].runwayId = 2;
	  takeoffQueue2.queues[takeoffQueue2.tail++] = number;
	  takeoffQueue2.counter++;
	}
    }
  else if (status == 3)
    {				//Handling Emergency Queue/Priority Queue/
      int index, c1, c2;
      c1 = landingQueue1.counter;
      c2 = landingQueue2.counter;
      for (int j = 0; j < size; j++)
	{
	  if (landingQueue1.queues[j] == number
	      || landingQueue2.queues[j] == number)
	    {
	      emergencyQueue.queues[emergencyQueue.tail++] = number;
	      emergencyQueue.counter++;
	      index = j;
	      break;
	    }
	  else
	    {
	      if (c1 > 0)
		{
		  stack.queue1[stack.top1++] = landingQueue1.queues[j];
		  landingQueue1.front++;
		  c1--;
		}
	      if (c2 > 0)
		{
		  stack.queue2[stack.top2++] = landingQueue2.queues[j];
		  landingQueue2.front++;
		  c2--;
		}
	    }
	}
      while (stack.top1 > 0 && stack.top2 > 0)
	{
	  if (stack.top1 > 0)
	    {
	      landingQueue1.queues[--landingQueue1.front] =
		stack.queue1[--stack.top1];
	    }
	  if (stack.top2 > 0)
	    {
	      landingQueue2.queues[--landingQueue2.front] =
		stack.queue2[--stack.top2];
	    }
	}
      if (landingQueue1.queues[index] == number)
	{
	  for (int i = index; i < landingQueue1.counter; i++)
	    {
	      landingQueue1.queues[i] = landingQueue1.queues[i + 1];
	    }
	  landingQueue1.tail--;
	  landingQueue1.counter--;
	}
      else if (landingQueue2.queues[index] == number)
	{
	  for (int i = index; i < landingQueue2.counter; i++)
	    {
	      landingQueue2.queues[i] = landingQueue2.queues[i + 1];
	    }
	  landingQueue1.tail--;
	  landingQueue2.counter--;
	}
    }
  n++;				//Departure Flight Details counter
  return true;
}


// for landing and takingoff flight and removing flights from queue
int
dequeueFlights (int status)
{
  int emergencyFlight, regularFlight1, regularFlight2, fl = 0;
  if (isEmpty ()) //checking if the queue is empty or not
    {
      cout << "\nNo Flight left\n";
      return -99999;
    }
  if (status == 1)
    {
      if (emergencyQueue.counter > 0)
	{
	  emergencyFlight = emergencyQueue.queues[emergencyQueue.front];
	  for (int i = 0; i < emergencyQueue.counter; i++)
	    {			//dequeue emergency flights
	      emergencyQueue.queues[i] = emergencyQueue.queues[i + 1];
	    }
	  emergencyQueue.counter--;
	  emergencyQueue.tail--;
	  cout << "\nEmergency Flight No" << emergencyFlight <<
	    "is Landed Successfully";
	  timeArrivalDeparture (1);
	}
      else
	{
	  regularFlight1 = landingQueue1.queues[landingQueue1.front];	//dequeue landing queue 1 flight
	  for (int i = 0; i < landingQueue1.counter; i++)
	    {
	      landingQueue1.queues[i] = landingQueue1.queues[i + 1];
	    }
	  landingQueue1.counter--;
	  landingQueue1.tail--;
	  cout << "\nFlight No" << regularFlight1 <<
	    "is Landed Successfully on Runway Id:" <<
	    arrivalFlightDetails[fl++].runwayId << "\n";
	  timeArrivalDeparture (1);
	  regularFlight2 = landingQueue2.queues[landingQueue2.front];	//dequeue landing queue2 flight
	  for (int i = 0; i < landingQueue2.counter; i++)
	    {
	      landingQueue2.queues[i] = landingQueue2.queues[i + 1];
	    }
	  landingQueue2.counter--;
	  landingQueue2.tail--;
	  cout << "\nFlight No" << regularFlight2 <<
	    " is Landed Successfully on Runway Id :" <<
	    arrivalFlightDetails[fl].runwayId << "\n";
	  timeArrivalDeparture (1);
	}

    }
  else if (status == 2)
    {
      regularFlight1 = takeoffQueue1.queues[takeoffQueue1.front];
      for (int i = 0; i <= takeoffQueue1.tail; i++)
	{
	  takeoffQueue1.queues[i] = takeoffQueue1.queues[i + 1];	//dequeue takeoff queue 1 flight
	  takeoffQueue1.tail--;
	}
      cout << "\nFlight No" << regularFlight1 <<
	" is Takeoff Successfully from Runway Id :" <<
	departureFlightDetails[fl++].runwayId << "\n";
      timeArrivalDeparture (2);
      regularFlight2 = takeoffQueue2.queues[takeoffQueue2.front];
      for (int i = 0; i <= takeoffQueue2.tail; i++)
	{
	  takeoffQueue2.queues[i] = takeoffQueue2.queues[i + 1];	//dequeue takeoff queue 2 flight
	  takeoffQueue2.tail--;
	}
      cout << "\nFlight No" << regularFlight2 <<
	" is Takeoff Successfully from Runway Id:" <<
	departureFlightDetails[fl].runwayId << "\n";
      timeArrivalDeparture (2);
    }

}

void
displayReports ()
{				//Displaying all the Reports
  char option, option1;
  cout <<
    "\nPress to Generate Reports for...\n1.For Landing Queue Reports\n2.For Takeoff Queues Reports\n3.For Emergency Queue Report\n4.All Arrival Flights Information\n5.All Departure Flights Information\n";
  cout<<"Enter your choice:\t";
  cin >> option;
  if (option == '1')
    {
      cout << "\n---Landing Queue 1---\n";
      for (int i = 0; i < landingQueue1.counter; i++)
	{			//Reports of Flights that are in Landing Queue 1
	  cout << landingQueue1.queues[i];
	}
      cout << "\n---Landing Queue 2---\n";	//Reports of Flights that are in Landing Queue 2
      for (int i = 0; i < landingQueue2.counter; i++)
	{
	  cout << landingQueue2.queues[i];
	}

    }
  else if (option == '2')
    {
      cout << "\n---Takingoff Queue 1---\n";
      for (int i = 0; i < takeoffQueue1.counter; i++)
	{			//Reports of Flights that are in Takeoff Queue 1
	  cout << takeoffQueue1.queues[i];
	}
      cout << "\n---Takingff Queue 2---\n";	//Reports of Flights that are in Takeoff Queue 2
      for (int i = 0; i < takeoffQueue2.counter; i++)
	{
	  cout << takeoffQueue2.queues[i];
	}
    }
  else if (option == '3')
    {
      cout << "\n---!EMERGENCY Queue!---\n";	//Reports of Flights that are in Emergency
      for (int i = 0; i < emergencyQueue.counter; i++)
	{
	  cout << emergencyQueue.queues[i];
	}
    }
  else if (option == '4')
    {
      cout << "\n---Arrival Flights Details---\n";
      for (int i = 0; i < k; i++)
	{			//For displaying all details of arrival information

	  cout << "\nFlight ID=" << arrivalFlightDetails[i].flightId;
	  cout << "Fuel=" << arrivalFlightDetails[i].fuel;
	  cout << "Destination=\n" << arrivalFlightDetails[i].destination;
	  cout << "Flight Status\n";
	  cout << "Arrival Date=\n" << arrivalFlightDetails[i].arrivalDate.
	    day - arrivalFlightDetails[i].arrivalDate.mon;
	  cout << "Arrival Time=\n" << arrivalFlightDetails[i].arrivalTime.
	    hours, arrivalFlightDetails[i].arrivalTime.min;
	  if (arrivalFlightDetails[i].landingTime.hours != 0)
	    {
	      cout << "Landing Time=/n" << arrivalFlightDetails[i].
		landingTime.hours, arrivalFlightDetails[i].landingTime.min;
	    }
	  if (arrivalFlightDetails[i].waitingTime.min != 0)
	    {
	      cout << "Waiting Time=\n" << arrivalFlightDetails[i].
		waitingTime.hours, arrivalFlightDetails[i].waitingTime.min;
	    }
	  cout << "Runway Id=\n" << arrivalFlightDetails[i].runwayId;
	  cout << "\n---------------------\n";
	}
    }
  else if (option == '5')
    {

      cout << "\n---Departure Flights Details---\n";

      for (int i = 0; i < n; i++)
	{			//For displaying all details of Departure information

	  cout << "\nFlight ID=\n" << departureFlightDetails[i].flightId;
	  cout << "Fuel=\n" << departureFlightDetails[i].fuel;
	  cout << "Destination=\n" << departureFlightDetails[i].destination;
	  cout << "Flight Status=\n" << departureFlightDetails[i].
	    flightStatus;
	  cout << "Schedule Date=" << departureFlightDetails[i].scheduleDate.
	    day - departureFlightDetails[i].scheduleDate.mon;
	  cout << "Schedule Time=\n" << departureFlightDetails[i].
	    scheduleTime.hours, departureFlightDetails[i].scheduleTime.min;
	  if (departureFlightDetails[i].actualTime.hours != 0)
	    {
	      cout << "Actual Time=\n" << departureFlightDetails[i].
		actualTime.hours, departureFlightDetails[i].actualTime.min;
	    }
	  if (departureFlightDetails[i].waitingTime.min != 0)
	    {
	      cout << "Waiting Time=\n" << departureFlightDetails[i].
		waitingTime.hours, departureFlightDetails[i].waitingTime.min;
	    }
	  cout << "Runway Id=\n" << departureFlightDetails[i].runwayId;
	 
	}
    }

}

bool
isFull ()
{				//Checking if the queues are full or not
  if (takeoffQueue1.counter >= size && takeoffQueue2.counter >= size
      && emergencyQueue.counter >= size || landingQueue1.counter >= size
      && landingQueue2.counter >= size && emergencyQueue.counter >= size)
    {
      return true;
    }
  return false;
}

bool
isEmpty ()
{				// Checking if the queues are empty or not
  if (landingQueue1.counter <= 0 && landingQueue2.counter <= 0
      || takeoffQueue1.counter <= 0 && takeoffQueue2.counter <= 0)
    {
      return true;
    }
  return false;
}
