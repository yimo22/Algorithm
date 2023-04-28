-- 서울에 위치한 식당들의 (식당ID, 식당이름, 음식종류, 즐겨찾기 수, 주소, 리뷰평균점수) 조회
-- 리뷰평균점수는 소수점 세 번째 자리에서 반올림
-- 평균점수기준 내림차순, 즐겨찾기 수 내림차순

SELECT ri.`REST_ID`, ri.`REST_NAME`, ri.`FOOD_TYPE`, ri.`FAVORITES`, ri.`ADDRESS`, round(avg(rr.REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO ri join REST_REVIEW rr
on ri.REST_ID = rr.REST_ID
where ri.ADDRESS LIKE '서울%'
GROUP BY ri.REST_ID
ORDER BY avg(rr.REVIEW_SCORE) desc, ri.FAVORITES desc;


# select * 
# from rest_info ri
# where ri.address like '%서울%'