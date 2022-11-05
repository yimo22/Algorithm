
SELECT truncate(PRICE, -4) AS PRICE_GROUP, count(price)
FROM PRODUCT
GROUP BY truncate(PRICE, -4)
ORDER BY truncate(PRICE, -4);

