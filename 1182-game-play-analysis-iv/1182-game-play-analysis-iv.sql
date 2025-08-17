# Write your MySQL query statement below
select round(count(*)/(select distinct count(distinct player_id) from activity),2) as fraction
from Activity
-- join Activity a2
-- on a1.player_id=a2.player_id and a1.event_date<a2.event_date
-- on datediff(a2.player_id,a1.player_id)=1
where (player_id,date_sub(event_date,interval 1 day))
in (select player_id,min(event_date) from activity as first_login group by player_id)