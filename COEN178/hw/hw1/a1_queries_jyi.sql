SELECT model, year, bodytype
FROM Car
order by bodytype;

SELECT *
FROM Car
WHERE status = 'available'
AND bodytype = 'van';

INSERT INTO Rental
(carId, date_rented, date_returned)
SELECT carId, SYSDATE, NULL
FROM Car
WHERE status = 'available';

UPDATE Rental
SET custId = 'asdf'
WHERE custId IS NULL;

SELECT *
FROM Rental;

UPDATE Car
SET status = 'out'
WHERE status = 'available';

SELECT *
FROM Car;

SELECT carId, model,  ROUND(TO_NUMBER(date_returned-date_rented) * 50) AS rental_amount
FROM Rental natural join Car
WHERE date_returned IS NOT NULL;

SELECT model
FROM Car
WHERE carId IN
(
  SELECT max(carId)
  FROM Rental
);

DELETE FROM Rental
WHERE carId in (
  SELECT carId
  FROM Car
  WHERE year < 2010
);

DELETE FROM Car
WHERE year < 2010;

SELECT *
FROM Car;
