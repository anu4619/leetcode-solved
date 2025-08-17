# Write your MySQL query statement below
-- (select name
-- from customer
-- where referee_id in (select id from customer where id!=2))
-- union
-- (select name
-- from customer
-- where referee_id is null)

select name from customer
where referee_id is null or referee_id!=2