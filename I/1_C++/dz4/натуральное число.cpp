bool year_is_leap(int year){ while(year % 100 == 0){ year /= 100; } if(year % 4 == 0){ return true; } return false; } 
