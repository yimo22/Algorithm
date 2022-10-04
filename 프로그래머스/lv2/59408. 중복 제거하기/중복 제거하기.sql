-- 코드를 입력하세요


# 동물 보호소에 들어온 동물의 이름은 몇개인지 조회하는 SQL
# 이름이 NULL 인 경우는 집계하지 않으며 중복 제거
select count(distinct name) as count
FROM ANIMAL_INS;