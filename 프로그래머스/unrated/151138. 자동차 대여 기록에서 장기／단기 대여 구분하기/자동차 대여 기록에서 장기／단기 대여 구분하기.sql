-- 대여 시작일 2022-09
-- 30일 이상 : 장기대여, 30일 미만 : 단기대여
-- 대여기록 ID 내림차순
SELECT history_id as HISTORY_ID,
car_id as CAR_ID, 
DATE_FORMAT(start_date, '%Y-%m-%d') as START_DATE, 
DATE_FORMAT(end_date, '%Y-%m-%d') as END_DATE, 
if(DATEDIFF(END_DATE, START_DATE) + 1 >= 30, '장기 대여', '단기 대여') as RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE YEAR(START_DATE) = '2022' and MONTH(START_DATE) = '09'
ORDER BY history_id desc;