# Write your MySQL query statement below
select dept.name as Department,Employee.name as Employee, Employee.salary as Salary
from employee 
join department as dept
on employee.departmentid=dept.id
where (employee.departmentid,employee.salary) in (select departmentid,max(salary) from employee group by departmentid)