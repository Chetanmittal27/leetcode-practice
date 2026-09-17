with cte as (
    select product_id , sum(unit) as units from Orders
    where DATE_FORMAT(order_date , '%Y-%m') = '2020-02'
    group by product_id
)

select p.product_name , c.units as unit from Products p
join
cte c on p.product_id = c.product_id
where c.units >= 100;