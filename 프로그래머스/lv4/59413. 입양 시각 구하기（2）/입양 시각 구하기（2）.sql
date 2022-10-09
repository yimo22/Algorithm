-- 코드를 입력하세요

# 0~23 시 까지, 각 시간대별로 입양이 몇건이나 발생했는지 조회
# 시간대 순으로 정렬

SET @TMPHOUR = -1;


SELECT (@TMPHOUR := @TMPHOUR + 1) AS HOUR, (
    SELECT count(*)
    FROM ANIMAL_OUTS
    WHERE HOUR(DATETIME) = @TMPHOUR
) AS COUNT
FROM ANIMAL_OUTS
WHERE @TMPHOUR < 23 
ORDER BY HOUR ASC;
