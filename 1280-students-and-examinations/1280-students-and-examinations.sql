# Write your MySQL query statement below t2.student_id,t2.student_name,t3.subject_name,COUNT(*) AS 'attended_exams' 
SELECT 
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM Students s
JOIN Subjects sub
LEFT JOIN Examinations e
    ON s.student_id = e.student_id
   AND sub.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;


#GROUP BY student_id,student_name,subject_name