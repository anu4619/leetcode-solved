# Write your MySQL query statement below
with cte as (
    select person_id, person_name,
    sum(weight) over(order by turn) as cumulative_sum, turn
    from queue
)

select person_name
from cte where cumulative_sum<=1000
order by turn desc
limit 1