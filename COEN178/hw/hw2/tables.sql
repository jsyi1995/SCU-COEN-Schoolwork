Drop table Rental;
Drop table Customer;
Drop table Car;

Create table Car (
carId varchar(10) PRIMARY KEY,
model varchar(25),
year numeric(4),
bodytype char(5) check (bodytype in ('sedan', 'van', 'suv')),
status char(10) check (status in ('available', 'out')));

Create table Customer (
custId varchar(10) PRIMARY KEY,
first_name varchar(15),
last_name varchar(15),
phone numeric(10));

Create table Rental (
carId varchar(10),
custId varchar(10),
date_rented date,
date_returned date,
foreign key (carId) references Car,
foreign key (custId) references Customer);
