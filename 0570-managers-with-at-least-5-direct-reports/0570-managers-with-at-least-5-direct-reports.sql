# Write your MySQL query statement below
select 
    e1.name as name 
from 
    Employee e1
join 
    Employee e2
on 
    e1.id = e2.managerId AND e1.id<>e2.id
Group by 
    e1.id 
HAVING count(*)>=5;

