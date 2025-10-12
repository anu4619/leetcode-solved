# Write your MySQL query statement below
(select u.name as results from users u
join MovieRating m
on u.user_id=m.user_id
group by m.user_id
order by count(u.user_id) desc, u.name
limit 1)
union all
(
select mo.title from movies mo
join movierating m on mo.movie_id=m.movie_id
where m.created_at between '2020-02-01' and '2020-02-29'
group by mo.movie_id
order by avg(m.rating) desc,mo.title
limit 1  
)