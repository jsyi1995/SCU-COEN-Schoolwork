Drop table Schedule;
Drop table Customer;
Drop table DeliveryService;

Create table Customer (
custid varchar(10) PRIMARY KEY,
first_name varchar(10),          
last_name varchar(15),           
city varchar(10));               

Create table DeliveryService (
serviceid varchar(10) PRIMARY KEY,
item varchar(15),                 
location varchar(15),             
servicefee NUMERIC(5,2));         


Create table Schedule (
serviceid varchar(10), 
custid varchar(10),  
day char(2) CHECK (day in ('m', 't', 'w', 'r', 'f')),
foreign key (custid) references Customer,            
foreign key (serviceid) references DeliveryService);