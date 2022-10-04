-- 코드를 입력하세요

# 입양을 간 동물 중, 보호 기간이 가장 길었던 동물 중 두마리의 아디와 이름을 조회
# 보호 기간이 긴 순으로 조회

SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_INS AS A join ANIMAL_OUTS AS B
ON A.ANIMAL_ID = B.ANIMAL_ID
ORDER BY (B.DATETIME - A.DATETIME) DESC
LIMIT 2;