SELECT custid, first_name || last_name "fullname", city 
FROM Customer;

SELECT * 
FROM Customer 
order by last_name;

SELECT * 
FROM Schedule 
order by serviceid, custid desc;

SELECT serviceid 
FROM DeliveryService 
MINUS 
SELECT serviceid 
FROM Schedule;

SELECT first_name || last_name "fullname" 
FROM Customer 
WHERE custid in 
(select custid 
from Schedule 
where Schedule.day = 'm');

SELECT last_name 
FROM Customer 
WHERE custid in 
(select custid 
from Schedule);

SELECT max (servicefee) as highest_Servicefee 
FROM DeliveryService;

SELECT day, count (day) 
FROM Schedule 
GROUP BY day;

SELECT A.custid, B.custid, A.city 
FROM Customer A, Customer B 
WHERE A.city = B.city 
minus (select A.custid, B.custid, A.city 
from Customer A, Customer B 
where A.custid = B.custid);

SELECT first_name || last_name "fullname", city 
FROM Customer inner join Schedule on Customer.custid = Schedule.custid, DeliveryService 
where city = DeliveryService.location; 
 
 