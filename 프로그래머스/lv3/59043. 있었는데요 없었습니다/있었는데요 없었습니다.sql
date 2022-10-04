-- 코드를 입력하세요
# 보호 시작일 (INS.DATETIME) 보다 입양일(OUTS.DATETIME)이 더 빠른 동물의 아디이와 이름을 조회
# 결과는 보호 시작일이 빠른 순으로 조회

SELECT A.ANIMAL_ID, A.name
FROM ANIMAL_INS as A join ANIMAL_OUTS as B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.DATETIME > B.DATETIME
ORDER BY A.DATETIME asc;