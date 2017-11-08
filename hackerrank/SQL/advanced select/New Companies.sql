select  c.company_code, 
        c.founder,
        count(distinct l.lead_manager_code),
        count(distinct s.senior_manager_code),
        count(distinct m.manager_code),
        count(distinct e.employee_code) 
from Company c, Lead_Manager l, Senior_Manager s, Manager m, Employee e
where c.company_code=l.company_code and l.company_code=s.company_code and s.company_code=m.company_code and m.company_code=e.company_code
group by c.company_code, c.founder
order by c.company_code;