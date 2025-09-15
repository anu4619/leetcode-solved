-- # Write your MySQL query statement below
-- select r.contest_id,round(((select distinct user_id from register group by contest_id)/(select distinct user_id from users))*100) as percentage
-- from users u
-- right join register r
-- on u.user_id=r.user_id
-- order by percentage desc,r.contest_id asc

select contest_id, round(count(distinct user_id)*100/(select count(distinct user_id) from users),2) as percentage
from register
group by contest_id
order by percentage desc,contest_id asc