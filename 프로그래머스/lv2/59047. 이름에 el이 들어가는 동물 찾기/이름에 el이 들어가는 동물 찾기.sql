-- 코드를 입력하세요
SELECT animal_id, name FROM ANIMAL_INS
where lower(name) LIKE '%el%' and ANIMAL_TYPE = 'Dog'
ORDER BY name ASC;