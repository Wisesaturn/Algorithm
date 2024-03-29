-- Group By 사용
SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) > 1
ORDER BY USER_ID ASC, PRODUCT_ID DESC;

-- Group By 없이 사용
-- SELECT DISTINCT o1.USER_ID, o1.PRODUCT_ID
-- FROM ONLINE_SALE o1
-- INNER JOIN ONLINE_SALE o2
-- ON o1.USER_ID = o2.USER_ID AND o1.PRODUCT_ID = o2.PRODUCT_ID AND o1.ONLINE_SALE_ID <> o2.ONLINE_SALE_ID
-- ORDER BY o1.USER_ID ASC, o1.PRODUCT_ID DESC;