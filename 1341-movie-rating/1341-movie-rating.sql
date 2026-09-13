with cte as (
    select user_id, count(movie_id) as cnt from MovieRating
    group by user_id
),

cte2 as (
    select movie_id, avg(rating) as average_rating from MovieRating
    where DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
    group by movie_id
)


(select u.name as results from Users u
inner join
cte c on u.user_id = c.user_id
where c.cnt = (select max(cnt) from cte)
order by u.name asc
limit 1)

union all

(select m.title as results from Movies m
inner join
cte2 c2 on m.movie_id = c2.movie_id
where c2.average_rating = (select max(average_rating) from cte2) 
order by m.title asc
limit 1);