# Vehicle_Parking_Management_System
My first C++ project based on OOP.
The Vehicle Management System (VMS) is a C++ console-based application designed to manage vehicle parking records, complaints, and total earnings generated from different types of vehicles.
It provides separate interfaces for Admin and Customer, offering smooth management and easy record handling.
Features:
  Admin Panel:-
    Add new vehicle records
    Search vehicle details
    Update vehicle information
    Delete vehicle entries
    View list of all vehicles
    Register complaints
    Check total earnings
    Secure login system (password-protected access)

  Customer Panel:-
    Park a vehicle
    Search parked vehicle
    Register a complaint
    Logout with a clean exit message
    
  Vehicle Categories & Charges:-
    The system tracks earnings based on vehicle type:
    Vehicle Type	Parking Fee
    Car	100
    Bus	200
    Truck	400
    Bike	50
    Cycle	20
All earnings are stored in EarnedMoney.txt.

  Data Storage:-
The project uses file handling to store and manage vehicle data:
Files Used:
  VehicleData.txt – Stores all vehicle records
  EarnedMoney.txt – Tracks total earnings
Stored Information Includes:
  Vehicle Number
  Short & Full Description
  Created/Updated by
  Date & Time of record
  Complaint history
  Unique complaint counter

  Core Functionalities:-
    Implemented Using OOP Concepts
    Structures (struct)
    Functions and modular programming
    File handling (read/write/update/delete)
    Menu-driven program
    Separate admin/customer views
    Data parsing using stringstream
    Use of <chrono> for timestamps
