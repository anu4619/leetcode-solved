# Write your MySQL query statement below
select distinct l.num as ConsecutiveNums from logs l
inner join logs prev
on l.num=prev.num and l.id-prev.id=1
inner join logs next
on l.num=next.num and next.id-l.id=1
