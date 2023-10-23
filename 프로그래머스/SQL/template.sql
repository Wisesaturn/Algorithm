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
  -- ORDER BY TABLE1 DESC, TABLE2 ASC

-- 값 계산
  -- SUM(TABLE) : 모든 값 더하기
  -- SUM((TABLE) / COUNT(*) : 평균
     -- AVG(TABLE)도 같은 역할이다
  -- ROUND(TABLE, DECIMAL) : 반올림 (decimal은 소수 몇 번째까지 반 올림 할건가요?)

-- 날짜 계산
  -- DATE_FORMAT(TABLE, '%Y-%m-%d') : TABLE 형태에서 yyyy-mm-dd의 형태로 추출
  -- %Y : yyyy, %y : yy
  -- %M : 월 (영어로)
  -- %m : 달 숫자
  -- %d : 일 수

  -- YEAR/MONTH/DAY(COLUMN) : 년/월/일의 값

-- 서브 쿼리 병합
  -- JOIN 말고 각각의 SELECT 후 합치기
  -- UNION ALL 사용 (+ 느낌)

  -- 예시)
  -- SELECT DATE_FORMAT(o1.SALES_DATE, '%Y-%m-%d') AS SALES_DATE, o1.PRODUCT_ID, o1.USER_ID, o1.SALES_AMOUNT
  -- FROM (
  --     SELECT SALES_DATE, PRODUCT_ID, NULL AS USER_ID, SALES_AMOUNT
  --     FROM OFFLINE_SALE
  --     WHERE MONTH(SALES_DATE) = 3 AND YEAR(SALES_DATE) = 2022
      
  --     UNION ALL
      
  --     SELECT SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
  --     FROM ONLINE_SALE
  --     WHERE MONTH(SALES_DATE) = 3 AND YEAR(SALES_DATE) = 2022
  -- ) AS o1
  -- ORDER BY o1.SALES_DATE ASC, o1.PRODUCT_ID ASC, o1.USER_ID ASC;

-- 특정 상위 컬럼을 출력할 때
   -- LIMIT (갯수);

-- 누적합
   -- SUM(COLUMNS) OVER(ORDER BY ID) 또는 OVER(PARTITION BY ID)
   -- PARTITION BY는 누적합에만 쓰이고, ORDER BY는 정렬까지 적용

-- 조건문
-- 1. CASE WHEN
    -- CASE 
    --     WHEN TLNO IS NULL THEN 'NONE'
    --     ELSE TLNO
    -- END AS TLNO
-- 2. IFNULL
    -- IFNULL(TLNO, 'NONE') AS TLNO