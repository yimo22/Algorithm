-- 코드를 입력하세요
# 생산일자가 2022년 5월인 식품들의
# 식품ID, 이름, 총매출 조회
# 총매출 기준으로 내림차순, 식품 ID기준으로 오름차순

SELECT  A.PRODUCT_ID, PRODUCT_NAME, sum(amount) * A.PRICE as TOTAL_SALES
FROM FOOD_PRODUCT as A join FOOD_ORDER as B
on A.PRODUCT_ID = B.PRODUCT_ID
where DATE_FORMAT(B.PRODUCE_DATE, '%Y-%m') = '2022-05'
GROUP BY PRODUCT_ID
ORDER BY TOTAL_SALES DESC, PRODUCT_ID asc;
