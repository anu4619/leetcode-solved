# Write your MySQL query statement below
with cte as (
    select num,
    lag(num) over(order by id) as previous,
    lead(num) over(order by id) as post
    from logs
)

select distinct num as ConsecutiveNums
from cte where num=previous and num=post
