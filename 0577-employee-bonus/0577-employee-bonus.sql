# Write your MySQL query statement below
Select 
    E.name as name ,
    B.bonus as bonus
from Employee  E
left join Bonus B
on E.empId = B.empId
where B.bonus<1000 OR B.bonus is null;