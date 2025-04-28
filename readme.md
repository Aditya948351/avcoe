<h1>DBMS Viva and Practical Preparation (SPPU Second Year IT)</h1>

<h1>Table of Contents</h1>
<ul>
<li><a href="#chit-1">Chit 1: ER/EER Diagram</a></li>
<li><a href="#chit-2">Chit 2: Normalization</a></li>
<li><a href="#chit-3">Chit 3: PK/FK, Alter, Drop</a></li>
<li><a href="#chit-4">Chit 4: Relational Operators</a></li>
<li><a href="#chit-5">Chit 5: Boolean Operators and Pattern Matching</a></li>
<li><a href="#chit-6">Chit 6: Arithmetic and Built-in Functions</a></li>
<li><a href="#chit-7">Chit 7: Date and Time Functions</a></li>
<li><a href="#chit-8">Chit 8: Set Operators</a></li>
<li><a href="#chit-9">Chit 9: Views</a></li>
<li><a href="#chit-10">Chit 10: Stored Procedures and Functions</a></li>
<li><a href="#chit-11">Chit 11: Triggers</a></li>
<li><a href="#chit-12">Chit 12: Cursors</a></li>
</ul>

<h1 id="chit-1">Chit 1: ER/EER Diagram</h1>
<p><strong>Theory:</strong> ER/EER diagrams are graphical representations that depict the entities in a database and the relationships between them. EER extends ER by including concepts like specialization, generalization, and aggregation for a more complex data modeling.</p>
<ul>
<li>Entities: Vehicle, Signal, Junction</li>
</ul>
<pre><code>CREATE TABLE Junction (
    junction_id INT PRIMARY KEY,
    junction_name VARCHAR(50),
    number_of_roads INT
);

CREATE TABLE Signal (
    signal_id INT PRIMARY KEY,
    location VARCHAR(100),
    status VARCHAR(20),
    junction_id INT,
    FOREIGN KEY (junction_id) REFERENCES Junction(junction_id)
);

CREATE TABLE Vehicle (
    vehicle_id INT PRIMARY KEY,
    type VARCHAR(30),
    registration_number VARCHAR(20)
);
</code></pre>

<h1 id="chit-2">Chit 2: Normalization</h1>
<p><strong>Theory:</strong> Normalization is a technique used to organize a relational database in such a way that it minimizes redundancy and dependency by dividing large tables into smaller ones. Common normalization forms include:
1NF: Atomic columns, 
2NF: Eliminate partial dependency, 
3NF: Eliminate transitive dependency.</p>
<pre><code>CREATE TABLE Student (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    course_id INT
);

CREATE TABLE Course (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50)
);
</code></pre>

<h1 id="chit-3">Chit 3: PK/FK, Alter, Drop</h1>
<p><strong>Theory:</strong> 
- A Primary Key (PK) uniquely identifies each record in a table.
- A Foreign Key (FK) is used to link two tables.
- ALTER command modifies the structure of an existing table.
- DROP command removes an entire table or database.</p>
<pre><code>CREATE TABLE Student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50),
    course_id INT,
    FOREIGN KEY (course_id) REFERENCES Course(course_id)
);

ALTER TABLE Student ADD marks INT;
ALTER TABLE Student MODIFY name VARCHAR(100);
DROP TABLE Student;
</code></pre>

<h1 id="chit-4">Chit 4: Relational Operators</h1>
<p><strong>Theory:</strong> Relational operators are used to compare values in SQL statements. These operators include '=', '<', '>', '<=', '>=', '<>' to check various relationships between values in the database.</p>
<pre><code>SELECT * FROM Student WHERE marks > 80;
SELECT * FROM Student WHERE marks <= 90;
SELECT * FROM Student WHERE marks <> 85;
</code></pre>

<h1 id="chit-5">Chit 5: Boolean Operators and Pattern Matching</h1>
<p><strong>Theory:</strong> 
- Boolean operators (AND, OR, NOT) combine multiple conditions.
- Pattern matching is done using the LIKE operator to perform wildcard searches in string data.</p>
<pre><code>SELECT * FROM Student WHERE marks > 80 AND name LIKE 'A%';
SELECT * FROM Student WHERE name LIKE '%a';
SELECT * FROM Student WHERE name LIKE '__d%';
</code></pre>

<h1 id="chit-6">Chit 6: Arithmetic and Built-in Functions</h1>
<p><strong>Theory:</strong> 
- Arithmetic operators (+, -, *, /) are used to perform calculations.
- Built-in functions like SUM(), AVG(), COUNT() summarize data or perform specific computations.</p>
<pre><code>SELECT name, marks + 5 AS BonusMarks FROM Student;
SELECT SUM(marks) AS TotalMarks FROM Student;
SELECT AVG(marks) AS AverageMarks FROM Student;
</code></pre>

<h1 id="chit-7">Chit 7: Date and Time Functions</h1>
<p><strong>Theory:</strong> 
Date functions like CURDATE(), NOW(), DATEDIFF() are used to retrieve and manipulate date values. These are helpful in situations where you need to compare dates or perform calculations involving date values.</p>
<pre><code>SELECT CURDATE();
SELECT NOW();
SELECT DATEDIFF('2025-05-10', '2025-05-01') AS DaysDifference;
</code></pre>

<h1 id="chit-8">Chit 8: Set Operators</h1>
<p><strong>Theory:</strong> 
Set operators combine the results of two SELECT queries:
- UNION: Combines the results of two queries and removes duplicates.
- INTERSECT: Returns only the common rows between two queries.
- MINUS: Returns rows from the first query that are not present in the second query (not supported in MySQL).</p>
<pre><code>SELECT name FROM Student
UNION
SELECT name FROM Alumni;

SELECT name FROM Student
INTERSECT
SELECT name FROM Alumni;
</code></pre>

<h1 id="chit-9">Chit 9: Views</h1>
<p><strong>Theory:</strong> 
A View is a virtual table that is based on the result of a SELECT query. Views help in simplifying complex queries, securing sensitive data, and encapsulating complex logic. Types of views:
- Simple View: Based on a single table.
- Complex View: Based on multiple tables or joins.
- Updatable View: Allows modifications to the underlying data.
- Non-updatable View: Does not allow modification of the underlying data.

Example of a simple view:</p>
<pre><code>CREATE VIEW HighScorers AS
SELECT name, marks FROM Student WHERE marks > 85;

SELECT * FROM HighScorers;

UPDATE HighScorers SET marks = 95 WHERE name = 'Aditya';
</code></pre>

<h1 id="chit-10">Chit 10: Stored Procedures and Functions</h1>
<p><strong>Theory:</strong> 
- A Stored Procedure is a set of SQL statements that can be executed as a unit.
- A Function is a piece of code that returns a value and can be called from SQL queries.</p>
<pre><code>DELIMITER //
CREATE PROCEDURE IncreaseMarks()
BEGIN
    UPDATE Student SET marks = marks + 5;
END;
//
DELIMITER ;

CALL IncreaseMarks();

DELIMITER //
CREATE FUNCTION GetMaxMarks()
RETURNS INT
DETERMINISTIC
BEGIN
    RETURN (SELECT MAX(marks) FROM Student);
END;
//
DELIMITER ;
</code></pre>

<h1 id="chit-11">Chit 11: Triggers</h1>
<p><strong>Theory:</strong> 
A Trigger is a stored procedure that automatically executes when a specified event (INSERT, UPDATE, DELETE) occurs on a table. Triggers can be used to enforce business rules, data integrity, and auditing.</p>
<pre><code>DELIMITER //
CREATE TRIGGER BeforeMarksUpdate
BEFORE UPDATE ON Student
FOR EACH ROW
BEGIN
    IF NEW.marks < OLD.marks THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Marks cannot be decreased';
    END IF;
END;
//
DELIMITER ;
</code></pre>

<h1 id="chit-12">Chit 12: Cursors</h1>
<p><strong>Theory:</strong> 
Cursors are used to retrieve data row by row and process it inside stored procedures. A cursor is useful when you need to perform complex operations on each row retrieved from a result set.</p>
<pre><code>DELIMITER //
CREATE PROCEDURE DisplayStudents()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE stud_name VARCHAR(50);
    DECLARE stud_cursor CURSOR FOR SELECT name FROM Student;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    
    OPEN stud_cursor;
    read_loop: LOOP
        FETCH stud_cursor INTO stud_name;
        IF done THEN
            LEAVE read_loop;
        END IF;
        SELECT stud_name;
    END LOOP;
    CLOSE stud_cursor;
END;
//
DELIMITER ;

CALL DisplayStudents();
</code></pre>

