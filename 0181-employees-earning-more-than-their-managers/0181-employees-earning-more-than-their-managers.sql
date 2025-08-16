# Write your MySQL query statement below
select generalemployee.name as Employee
from employee as generalemployee
 join employee as manager
on generalemployee.managerid=manager.id
where generalemployee.salary>manager.salary