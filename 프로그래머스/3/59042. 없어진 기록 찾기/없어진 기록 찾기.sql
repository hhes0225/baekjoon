SELECT AOUT.ANIMAL_ID AS ANIMAL_ID, AOUT.NAME AS NAME
FROM ANIMAL_INS AS AIN RIGHT JOIN ANIMAL_OUTS AS AOUT
ON AIN.ANIMAL_ID = AOUT.ANIMAL_ID
WHERE INTAKE_CONDITION IS NULL