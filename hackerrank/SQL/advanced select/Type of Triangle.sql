select 
    case 
        when a >= b+c or b >= a+c or c >= a+b 
            then 'Not A Triangle'
        else
            case 
                when a = b and b = c
                    then 'Equilateral'
                else
                    case
                        when a = b or b = c or a = c
                            then 'Isosceles'
                        else 'Scalene'
                    end
            end
    end
from triangles;