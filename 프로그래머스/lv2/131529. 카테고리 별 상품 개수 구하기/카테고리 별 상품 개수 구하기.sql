-- 코드를 입력하세요
SELECT left(PRODUCT_CODE, 2) as CATEGORY, count(product_id)
FROM PRODUCT
GROUP BY left(PRODUCT_CODE, 2)
order by category asc;
