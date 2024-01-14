-- 코드를 입력하세요
-- 20222'10'5 등록된 중고거래 ID, 작성자ID, 게시글 제목, 가격, 거래상태 조회
-- 거래상태 SALE : 판매중, RESERVED : 예약중, DONE : 거래완료
-- 게시글 ID 기준 내림차순

SELECT 
    BOARD_ID,
    WRITER_ID,
    TITLE,
    PRICE,
    CASE STATUS
        WHEN 'SALE'   THEN '판매중'
        WHEN 'RESERVED' THEN '예약중'
        WHEN 'DONE' THEN '거래완료'
    END AS STATUS
FROM USED_GOODS_BOARD 
WHERE CREATED_DATE = '20221005'
ORDER BY BOARD_ID DESC