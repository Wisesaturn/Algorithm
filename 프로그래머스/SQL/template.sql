-- SELECT 특정 Column 추가
   -- DISTINCT 중복 컬럼 제거

-- FROM 어디 테이블에서 선택할 것인지

-- INNER JOIN (JOIN) 특정 행과 연결
  -- ON 어떤 조건으로 연결해서 특정 행만 보이도록
-- RIGHT OUTER JOIN 오른쪽 테이블의 모든 행 포함 왼쪽 테이블은 조건만
  -- ON 어떤 조건으로 연결해서 특정 행만 보이도록
-- LEFT OUTER JOIN 왼쪽 테이블의 모든 행 포함 왼쪽 테이블은 조건만
  -- ON 어떤 조건으로 연결해서 특정 행만 보이도록

-- WHERE 어떤 조건을 두고 값을 잘라낼건지

-- GROUP BY 특정 값을 기준으로 묶기
  -- HAVING 얼마나 카운트하냐 (WHERE와 차이 있음)

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