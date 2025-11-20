# Write your MySQL query statement below
with cte as (
    select
    case when income<20000 then 1 else 0 end as low,
    case when income between 20000 and 50000 then 1 else 0 end as medium,
    case when income>50000 then 1 else 0 end as high
    from accounts
)
select 'High Salary' as category,sum(high) as accounts_count from cte

union all
select 'Low Salary' as category,sum(low) as accounts_count from cte
union all
select 'Average Salary' as category,sum(medium) as accounts_count from cte

