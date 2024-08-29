# Hotel Management Application

This project is a simple hotel management system implemented in C++ with MySQL integration. The application allows users to manage customers, rooms, and bookings through a command-line interface (CLI).

## Features
- Customer Management: Add, update, delete, and view customers.
- Room Management: Add, remove, update status, and view rooms.
- Booking Management: Book, cancel, and view bookings by customer.
- MySQL Database Integration: Persistent storage of customer, room, and booking data.
- Basic Input Validation and Authentication.

## Folder Structure
- `include/`: Header files for the project.
- `src/`: Source files for the project.
- `config/`: Configuration files for database and application settings.
- `sql/`: SQL scripts for database creation and seeding.
- `build/`: Directory for compiled binaries.

## Build and Run
1. Install MySQL and create a database using the provided SQL scripts in the `sql/` directory.
2. Configure the database connection in `config/database.cfg`.
3. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
