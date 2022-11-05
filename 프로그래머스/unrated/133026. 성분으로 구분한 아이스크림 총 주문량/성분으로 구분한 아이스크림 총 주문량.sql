-- 코드를 입력하세요
# 상반기 동안, 각 성분타입과 성분타입에 대한 총 주문량
# Order by 총주문량 asc

SELECT INGREDIENT_TYPE, sum(TOTAL_ORDER) as TOTAL_ORDER
FROM FIRST_HALF as A join ICECREAM_INFO as B
on A.FLAVOR = B.FLAVOR
GROUP BY INGREDIENT_TYPE
order by sum(TOTAL_ORDER) asc;

