Acceptance Criteria:
employee_hours.txt:
    John Smith,40
    Mary Jones,38
    Carlos Garcia,45
    Emily Brown,32
    Robert Johnson,40
    Linda Williams,36
    Michael Davis,42
    Patricia Miller,40
    James Wilson,37
    Jennifer Moore,44
    David Taylor,40
    Barbara Anderson,35
    William Thomas,41
    Susan Jackson,39
    Richard White,40
    Karen Harris,38
    Joseph Martin,43
    Nancy Thompson,40
    Thomas Garcia,36
    Lisa Martinez,42
Output: numbered_hours.txt
    1. John Smith,40
    2. Mary Jones,38
    3. Carlos Garcia,45
    4. Emily Brown,32
    5. Robert Johnson,40
    6. Linda Williams,36
    7. Michael Davis,42
    8. Patricia Miller,40
    9. James Wilson,37
    10. Jennifer Moore,44
    11. David Taylor,40
    12. Barbara Anderson,35
    13. William Thomas,41
    14. Susan Jackson,39
    15. Richard White,40
    16. Karen Harris,38
    17. Joseph Martin,43
    18. Nancy Thompson,40
    19. Thomas Garcia,36
    20. Lisa Martinez,42

The actual run of the program:
student@9b36e72c8c17:/workspace/c/CCR4-Precision-Payroll-Services$ ./CCR4-Precision
================================
Precision Payroll Services
File Processing Summary
================================
Input File: employee_hours.txt
Output File: numbered_hours.txt

Lines Copied: 20
Characters Copied: 417

File Copied and numbered Successfully. Thank you!


test-cases:

- What if the first line is blank:
EX:
BLANK
John doe, 40
- Hmm it causes a problem and adds a number index where a number does not exist
- added lines with no conetnt get ignored
==================================================================================
