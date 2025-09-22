# Write your MySQL query statement below
-- select num
-- from mynumbers

-- where num in
select max(num) as num from 
(select num from mynumbers
group by num
having count(*)=1) as abc

-- group by num