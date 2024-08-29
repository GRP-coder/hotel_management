USE hotel_management;

INSERT INTO customers (name, phone, email) VALUES
('John Doe', '1234567890', 'john@example.com'),
('Jane Smith', '0987654321', 'jane@example.com');

INSERT INTO rooms (type, price, isAvailable) VALUES
('Single', 100.00, TRUE),
('Double', 150.00, TRUE),
('Suite', 250.00, TRUE);
