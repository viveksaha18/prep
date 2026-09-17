CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    name VARCHAR(50),
    department VARCHAR(50),
    salary INT,
    hire_date DATE,
    city VARCHAR(50)
);

INSERT INTO employees
(employee_id, name, department, salary, hire_date, city)
VALUES
(1, 'Rahul', 'IT', 60000, '2022-01-15', 'Bhubaneswar'),
(2, 'Priya', 'HR', 45000, '2021-06-10', 'Cuttack'),
(3, 'Amit', 'IT', 75000, '2023-03-20', 'Bhubaneswar'),
(4, 'Neha', 'Sales', 50000, '2022-08-05', 'Pune'),
(5, 'Raj', 'IT', 65000, '2021-11-12', 'Delhi'),
(6, 'Sneha', 'HR', 55000, '2024-01-08', 'Bangalore'),
(7, 'Vikas', 'Sales', 70000, '2020-05-18', 'Mumbai'),
(8, 'Anjali', 'IT', 80000, '2023-07-22', 'Pune'),
(9, 'Rohit', 'Finance', 62000, '2022-12-01', 'Delhi'),
(10, 'Pooja', 'IT', 55000, '2024-02-14', 'Cuttack');

-- Question: 1
-- Write a SQL query to find the names and salaries of employees who work in the IT department 
-- and earn more than 60,000.

Select name, salary
from employees
where department = 'IT' and salary > 60000


-- Question 2

-- Find the average salary for each department.

-- Write only your SQL query. No hints.

Select department, AVG(salary) as average_salary
from employees
GROUP BY department

-- Question 3
Using the same employees table:

Find the departments whose average salary is greater than 60,000.

Select department, AVG(salary) as avg_salary from employees GROUP BY department HAVING AVG(salary) > 60000

-- Using nested query
SELECT department, avg_salary
FROM (
    SELECT department, AVG(salary) AS avg_salary
    FROM employees
    GROUP BY department
) AS t
WHERE avg_salary > 60000;


Question 4 — Medium

Using the same employees table:

Find the employee(s) who have the highest salary in the company.

There may be more than one employee with the highest salary.

Write the SQL query.


Declare @highest_salary INT;

Select @highest_salary = salary

from employees

ORDER BY salary DESC

OFFSET 0 ROWS

FETCH NEXT 1 ROW ONLY;

Select name, salary

from employees

where salary = @highest_salary


--- INTERVIEW TYPE QUERY 

Select name, salary 
from employees
where salary = (
  Select Max(salary)
  from employees
);
-- INNER QUERY RUNS FIRST


-- Question 5 
-- Find second highest salary


Select DISTINCT name, salary
from employees
ORDER BY salary DESC 
OFFSET 1 ROWS
FETCH NEXT 1 ROW ONLY



-- Question 6 — Medium

-- Using the same employees table:

-- Find the employee(s) 
-- whose salary is greater than the average salary of the entire company.

Select name, salary 
from employees
where salary > (
  Select AVG(salary) as average_salary
  from employees
)

-- Question 7 — Medium

-- Find the department that has the highest average salary.

Select TOP 1 department, AVG(salary) as avg_salary
from employees
GROUP BY department
ORDER BY AVG(salary) DESC