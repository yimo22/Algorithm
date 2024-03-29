-- 코드를 입력하세요

# 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회
# 결과는 장바구니의 아이디 순으로 


# 1차 정답
# SELECT distinct C.CART_ID
# FROM CART_PRODUCTS AS C
# WHERE C.CART_ID in (
#     SELECT A.CART_ID
#     FROM
#         (select cart_id
#         from cart_products
#         where name = 'Yogurt') AS A join 
#         (select cart_id
#         from cart_products
#         where name = 'Milk') AS B
#     ON A.CART_ID = B.CART_ID
# )
# ORDER BY CART_ID;

# 2차 정답
SELECT B.CART_ID
FROM (
    SELECT distinct CART_ID, NAME
    FROM CART_PRODUCTS
    WHERE NAME = 'Milk' or NAME = 'Yogurt'
    ) as B
GROUP BY B.CART_ID
HAVING count(B.CART_ID) >= 2
ORDER BY B.CART_ID ASC;