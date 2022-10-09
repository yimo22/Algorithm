-- 코드를 입력하세요

# 강원도에 위치한 식품공장의 공장ID, 공장이름, 주소 를 조회
# 공장 ID를 기준으로 오름차순 정렬

SELECT FACTORY_ID, FACTORY_NAME, ADDRESS
FROM FOOD_FACTORY AS A
where A.ADDRESS LIKE '강원도%'
ORDER BY FACTORY_ID ASC;