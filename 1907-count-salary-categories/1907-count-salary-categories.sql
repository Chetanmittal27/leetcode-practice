with cte as(

    select account_id , income , case 
                                    when income < 20000 then "Low Salary"
                                    when income >= 20000 and income <= 50000 then "Average Salary"
                                    when income > 50000 then "High Salary"
                                    end as category

    from Accounts
)

select "Low Salary" as category , coalesce(count(account_id) , 0) as accounts_count from cte 
where category = "Low Salary"

Union

select "Average Salary" as category , coalesce(count(account_id) , 0) as accounts_count from cte
where category = "Average Salary"

Union

select "High Salary" as category , coalesce(count(account_id) , 0) as accounts_count from cte 
where category = "High Salary";