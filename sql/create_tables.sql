CREATE DATABASE IF NOT EXISTS hotel_management;

USE hotel_management;

CREATE TABLE IF NOT EXISTS customers (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    phone VARCHAR(15),
    email VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS rooms (
    id INT AUTO_INCREMENT PRIMARY KEY,
    type VARCHAR(50),
    price DECIMAL(10, 2),
    isAvailable BOOLEAN DEFAULT TRUE
);

CREATE TABLE IF NOT EXISTS bookings (
    id INT AUTO_INCREMENT PRIMARY KEY,
    customerId INT,
    roomId INT,
    checkInDate DATE,
    checkOutDate DATE,
    FOREIGN KEY (customerId) REFERENCES customers(id),
    FOREIGN KEY (roomId) REFERENCES rooms(id)
);
