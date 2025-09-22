# Write your MySQL query statement below
select m.employee_id as employee_id,m.name as name,count(e.employee_id) as reports_count,round(avg(e.age),0) as average_age
from employees as m
inner join employees as e
on m.employee_id=e.reports_to
group by m.employee_id
order by m.employee_id