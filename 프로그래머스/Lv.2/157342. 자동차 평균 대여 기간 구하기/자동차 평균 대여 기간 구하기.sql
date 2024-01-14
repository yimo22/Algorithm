-- 코드를 입력하세요
-- 평균대여기간이 7일 이상인 자동차들
-- 자동차 ID, 평균대여기간
-- 평균대여기간은 소수점 두번쨰 자리에서 반올림 
-- 평균대여기간 DESC, 자동차 ID DESC


-- 분석
-- 당일 대여 / 당일 반납 -> 1일
SELECT 
    CAR_ID, 
    ROUND(AVG(DATEDIFF(END_DATE, START_DATE) + 1), 1) as AVERAGE_DURATION
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
HAVING AVG(DATEDIFF(END_DATE, START_DATE) + 1) >= 7 
ORDER BY AVERAGE_DURATION DESC, CAR_ID DESC



