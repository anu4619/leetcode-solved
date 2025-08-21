# Write your MySQL query statement below

-- select * from Orders 
-- where rownum = 1 
-- select customer_number from orders
-- group by customer_number
-- order by count(Order_number) asc

-- select customer_number from orders
-- group by customer_number
-- -- having count(order_number)=(select max(count(order_number)) from orders group by customer_number)
-- having count(order_number)>1


select customer_number from orders
group by customer_number
order by count(order_number) desc
limit 1 