# Write your MySQL query statement below
select id,
case
when p_id is NULL then 'Root'
when id not in (select p_id from Tree WHERE P_ID is NOT NULL) then 'Leaf'
else 'Inner' 
end as type
from Tree;