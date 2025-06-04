# Write your MySQL query statement below
Select 
   c.name as Customers
from Customers c
left join Orders o
on c.id=o.customerID 
where o.id is null;
