SELECT  PT_NAME, PT_NO, GEND_CD, AGE,
    CASE 
        WHEN TLNO IS NULL THEN 'NONE'
        ELSE TLNO
    END AS TLNO
FROM PATIENT
WHERE GEND_CD LIKE 'W' AND AGE <= 12
ORDER BY AGE DESC, PT_NAME ASC;

-- 또는
-- SELECT  PT_NAME, PT_NO, GEND_CD, AGE,
--      IFNULL(TLNO, 'NONE') AS TLNO
-- FROM PATIENT
-- WHERE GEND_CD LIKE 'W' AND AGE <= 12
-- ORDER BY AGE DESC, PT_NAME ASC;