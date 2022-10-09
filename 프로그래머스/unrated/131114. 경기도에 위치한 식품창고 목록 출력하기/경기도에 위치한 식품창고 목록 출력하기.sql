-- 코드를 입력하세요

# 경기도에 위치한 창고의 ID, 이름, 주소, 냉동시설 여부를 조회
# 냉동시설 여부가 NULL 일경우, N
# 결과는 창고ID asc

SELECT  WAREHOUSE_ID, WAREHOUSE_NAME, ADDRESS, IFNULL(FREEZER_YN, 'N')
FROM FOOD_WAREHOUSE AS A
WHERE A.ADDRESS LIKE '경기도%'
ORDER BY WAREHOUSE_ID;

# Select * from FOOD_WAREHOUSE;