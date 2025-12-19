# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from activity),2) as fraction
from activity
-- inner join activity a2
-- on a1.player_id = a2.player_id
-- and datediff(a2.event_date,a1.event_date)=1
-- group by a1.player_id
where (player_id,date_sub(event_date,interval 1 day)) in
(select player_id, min(event_date) from activity group by player_id)