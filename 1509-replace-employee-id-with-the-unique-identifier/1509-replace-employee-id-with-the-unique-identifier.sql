# Write your MySQL query statement below
select a.unique_id ,b.name
from EmployeeUNI as a
right JOIN Employees as b
on  b.id = a.id;