SELECT Supplier.sno, sname, city
FROM Supplier
WHERE NOT EXISTS (
  SELECT *
  FROM Parts
  WHERE NOT EXISTS (
    SELECT *
    FROM Shipment
    WHERE Supplier.sno = Shipment.sno
    AND Parts.pno = Shipment.pno) AND Parts.color IN ('blue'));
