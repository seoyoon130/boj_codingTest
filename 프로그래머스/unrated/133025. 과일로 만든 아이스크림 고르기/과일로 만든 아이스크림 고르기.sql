-- 코드를 입력하세요
SELECT F.FLAVOR
FROM FIRST_HALF AS F 
JOIN ICECREAM_INFO AS I
ON F.FLAVOR = I.FLAVOR
WHERE TOTAL_ORDER >= 3000 AND INGREDIENT_TYPE = 'fruit_based'
-- 상반기 총주문량 3000보다 높고, 주성분 과일, 총주문 순서대로 order
