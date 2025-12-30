# Write your MySQL query statement below
with cte as
(select person_id,person_name,weight,turn,
sum(weight) over(order by turn) as cumsum
from queue)

select person_name from cte where cumsum<=1000 and turn=(select max(turn) from cte where cumsum<=1000)