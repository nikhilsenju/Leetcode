# Write your MySQL query statement belos
select max(salary) as SecondHighestSalary
from employee
where salary < (
        select 
            MAX(salary) as maxsalary 
        from employee
)