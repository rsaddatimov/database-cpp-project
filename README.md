# Key-value (date, event) database

## Description
This is my project where I implemented key-value database, which stores (date, event) and can perform some operations with conditions and predicates.
Database can store multiple events with same date.

## What database can
- **Add** *DATE EVENT* - store (date, event) pair in database.
- **Print** - prints all stored entries
- **Last** *DATE* - prints last stored event by DATE date
- **Find** *CONDITION* - finds and prints all entries which satisfy given CONDITION
- **Del** *CONDITION* - deletes from database entries which satisfy given CONDITION

*CONDITION* example: Del date == 2017-1-1 AND event == "test" OR date > 2018-1-1

## How to build
```
mkdir build
cd build
cmake ..
make
./database
```

## Stack
- C++ 17
- STL, Algorithms
- CMake
