-- SELECT 특정 Column 추가
-- FROM 어디 테이블에서 선택할 것인지
-- WHERE 어떤 조건을 두고 값을 잘라낼건지
-- ORDER BY 맨 앞부터 차례대로 정렬
  -- DESC 내림차순
  -- ASC 오름차순
  -- ORDERBY TABLE1 DESC, TABLE2 ASC

-- 조건문
-- 1. CASE WHEN
    -- CASE 
    --     WHEN TLNO IS NULL THEN 'NONE'
    --     ELSE TLNO
    -- END AS TLNO
-- 2. IFNULL
    -- IFNULL(TLNO, 'NONE') AS TLNO