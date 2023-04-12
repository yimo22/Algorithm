-- '네비게이션' 옵션이 포함된 자동차 리스트를 출력
-- 자동차ID 내림차순
SELECT * 
FROM car_rental_company_car
WHERE locate('네비게이션', options) > 0
ORDER BY CAR_ID DESC;