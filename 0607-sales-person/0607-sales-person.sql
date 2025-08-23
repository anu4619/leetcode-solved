# Write your MySQL query statement below
select s.name 
from salesperson s
where sales_id not in (select o.sales_id from orders O
join company c
on O.com_id=c.com_id
where c.name='RED')