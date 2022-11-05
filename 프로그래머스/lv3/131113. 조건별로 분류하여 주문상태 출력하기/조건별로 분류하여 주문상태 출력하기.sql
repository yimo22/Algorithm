-- 코드를 입력하세요
# 5월 1일을 기준으로 주문 ID, 제품ID, 출고일자, 출고 여부를 조회하는 SQL
# 주문ID 오름차순
SELECT ORDER_ID, PRODUCT_ID, date_format(OUT_DATE, '%Y-%m-%d'), if(out_date <= '2022-05-01', '출고완료', if(out_date is null, '출고미정', '출고대기')) AS 출고여부
FROM FOOD_ORDER as A
order by order_id asc;

