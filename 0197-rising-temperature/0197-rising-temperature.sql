# Write your MySQL query statement below
WITH temp_cte AS (
    SELECT id , recordDate , temperature , 
    LAG(recordDate , 1) OVER (ORDER BY recordDate) AS prev_date , 
    LAG(temperature , 1) OVER (ORDER BY recordDate) AS prev_temp FROM Weather
)

SELECT Id FROM temp_cte
WHERE temperature > prev_temp AND DATEDIFF(recordDate , prev_date) = 1;