-- 코드를 입력하세요

-- 2022'04'13 취소되지 않은 CS 진료예약내역
-- 예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시
-- 진료예약일시 ASC

SELECT
    APNT_NO,
    p.PT_NAME,
    p.PT_NO,
    d.MCDP_CD,
    d.DR_NAME,
    a.APNT_YMD
FROM    
    APPOINTMENT a
    JOIN PATIENT p ON a.PT_NO = p.PT_NO
    JOIN DOCTOR d ON a.MDDR_ID = d.DR_ID
WHERE
    (YEAR(a.APNT_YMD) = '2022' AND MONTH(a.APNT_YMD) = '04' AND DAY(a.APNT_YMD) = '13') AND 
    APNT_CNCL_YN = 'N' AND 
    a.MCDP_CD = 'CS'
ORDER BY
    APNT_YMD ASC