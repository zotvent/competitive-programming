--WHERE CLAUSE
select s.name, g.grade, s.marks 
from students s, grades g 
where s.marks >= g.min_mark and s.marks <= g.max_mark and g.grade > 7 
order by grade desc, s.name;

select 'NULL', g.grade, s.marks 
from students s, grades g 
where s.marks >= g.min_mark and s.marks <= g.max_mark and g.grade < 8 
order by g.grade desc, s.marks asc;


--INNER JOIN
select (case g.grade > 7 when true then s.name else null end), g.grade, s.marks 
from students s 
inner join grades g on s.marks between g.min_mark and g.max_mark
order by g.grade desc, s.name, s.marks;
