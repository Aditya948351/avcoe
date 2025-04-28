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
<p><strong>Theory:</strong> 
    ER (Entity-Relationship) and EER (Enhanced Entity-Relationship) diagrams represent the relationships between entities in a database system. 
    - **Entity:** Represents a real-world object, like a vehicle or a student.
    - **Attributes:** Properties of an entity. For example, a vehicle may have attributes like vehicle_id, vehicle_type, etc.
    - **Relationship:** An association between entities. For example, a vehicle may be associated with a particular junction through a signal.
    - **EER Enhancements:** These include specialization, generalization, and aggregation, which help represent more complex relationships.
</p>
<p><strong>Example:</strong></p>
<pre><code>
CREATE TABLE Junction (
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
<p><strong>Theory:</strong>
    Normalization is the process of organizing data to minimize redundancy and dependency. It ensures that the database is efficient, with well-structured relationships. 
    - **1NF (First Normal Form):** Ensures that all columns contain atomic (indivisible) values.
    - **2NF (Second Normal Form):** Ensures that there are no partial dependencies, meaning that non-key attributes are fully dependent on the primary key.
    - **3NF (Third Normal Form):** Ensures that there are no transitive dependencies, where non-key attributes depend on other non-key attributes.
</p>
<p><strong>Example:</strong></p>
<pre><code>
CREATE TABLE Student (
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
    - **Primary Key (PK):** Uniquely identifies each row in a table. It must be unique and non-null.
    - **Foreign Key (FK):** A field in one table that refers to the primary key of another table. It establishes a relationship between two tables.
    - **ALTER:** Used to modify the structure of an existing table (add/drop columns, change data types).
    - **DROP:** Used to delete an existing table or database.
</p>
<p><strong>Example:</strong></p>
<pre><code>
CREATE TABLE Student (
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
<p><strong>Theory:</strong> Relational operators are used to compare data in SQL queries. Common relational operators are:
    - **= (Equal)**
    - **< (Less than)**
    - **> (Greater than)**
    - **<= (Less than or equal to)**
    - **>= (Greater than or equal to)**
    - **<> (Not equal to)**
</p>
<p><strong>Example:</strong></p>
<pre><code>
SELECT * FROM Student WHERE marks > 80;
SELECT * FROM Student WHERE marks <= 90;
SELECT * FROM Student WHERE marks <> 85;
</code></pre>

<h1 id="chit-5">Chit 5: Boolean Operators and Pattern Matching</h1>
<p><strong>Theory:</strong>
    - **Boolean Operators:** Used to combine multiple conditions.
        - **AND:** Returns rows that satisfy all conditions.
        - **OR:** Returns rows that satisfy at least one condition.
        - **NOT:** Reverses the result of a condition.
    - **Pattern Matching:** Uses the LIKE operator to search for patterns in data.
        - **% (Wildcard):** Represents zero or more characters.
        - **_ (Wildcard):** Represents exactly one character.
</p>
<p><strong>Example:</strong></p>
<pre><code>
SELECT * FROM Student WHERE marks > 80 AND name LIKE 'A%';
SELECT * FROM Student WHERE name LIKE '%a';
SELECT * FROM Student WHERE name LIKE '__d%';
</code></pre>

<h1 id="chit-6">Chit 6: Arithmetic and Built-in Functions</h1>
<p><strong>Theory:</strong> 
    - **Arithmetic Operators:** Perform mathematical calculations like addition (+), subtraction (-), multiplication (*), and division (/).
    - **Built-in Functions:** SQL provides various functions for data aggregation, such as SUM(), AVG(), COUNT(), MAX(), and MIN().
</p>
<p><strong>Example:</strong></p>
<pre><code>
SELECT name, marks + 5 AS BonusMarks FROM Student;
SELECT SUM(marks) AS TotalMarks FROM Student;
SELECT AVG(marks) AS AverageMarks FROM Student;
</code></pre>

<h1 id="chit-7">Chit 7: Date and Time Functions</h1>
<p><strong>Theory:</strong>
    - **CURDATE():** Returns the current date.
    - **NOW():** Returns the current date and time.
    - **DATEDIFF():** Returns the difference between two dates.
</p>
<p><strong>Example:</strong></p>
<pre><code>
SELECT CURDATE();
SELECT NOW();
SELECT DATEDIFF('2025-05-10', '2025-05-01') AS DaysDifference;
</code></pre>

<h1 id="chit-8">Chit 8: Set Operators</h1>
<p><strong>Theory:</strong>
    Set operators are used to combine the results of two or more SELECT queries.
    - **UNION:** Combines the results of two queries and removes duplicates.
    - **INTERSECT:** Returns only the rows that exist in both queries (Note: Not available in MySQL).
    - **MINUS:** Returns rows from the first query that do not exist in the second (Not available in MySQL).
</p>
<p><strong>Example:</strong></p>
<pre><code>
SELECT name FROM Student
UNION
SELECT name FROM Alumni;
</code></pre>

<h1 id="chit-9">Chit 9: Views</h1>
<p><strong>Theory:</strong>
    A **View** is a virtual table based on the result of a query. It simplifies complex queries and enhances security by restricting direct access to data.
    - **Types of Views:**
        - **Simple View:** Based on a single table and does not include any complex calculations or joins.
        - **Complex View:** Can include multiple tables, joins, and aggregate functions.
        - **Updatable View:** Allows modification of data through the view.
        - **Non-Updatable View:** Data cannot be modified directly via the view.
</p>
<p><strong>Example:</strong></p>
<pre><code>
CREATE VIEW HighScorers AS
SELECT name, marks FROM Student WHERE marks > 85;

SELECT * FROM HighScorers;

UPDATE HighScorers SET marks = 95 WHERE name = 'Aditya';
</code></pre>

<h1 id="chit-10">Chit 10: Stored Procedures and Functions</h1>
<p><strong>Theory:</strong>
    - **Stored Procedure:** A precompiled collection of SQL statements that can be executed as a unit.
    - **Function:** A SQL function that returns a value.
</p>
<p><strong>Example:</strong></p>
<pre><code>
DELIMITER //
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
<p><strong>Theory:</strong> A **Trigger** is an automatic action initiated in response to certain events (INSERT, UPDATE, DELETE) on a table.
</p>
<p><strong>Example:</strong></p>
<pre><code>
DELIMITER //
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
<p><strong>Theory:</strong> A **Cursor** is a database object that allows row-by-row processing in stored procedures.
</p>
<p><strong>Example:</strong></p>
<pre><code>
DELIMITER //
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

<h1>Executing SQL Commands in Ubuntu Terminal</h1>
<p><strong>To execute SQL commands in Ubuntu Terminal, follow these steps:</strong></p>
<pre><code>
1. Install MySQL server (if not already installed):
   sudo apt update
   sudo apt install mysql-server

2. Log into MySQL:
   mysql -u root -p

3. To execute SQL commands from a file:
   mysql -u root -p < /path/to/your/sqlfile.sql

4. Alternatively, execute SQL commands directly from the MySQL shell:
   mysql> USE your_database;
   mysql> CREATE TABLE ...;
   mysql> SELECT * FROM ...;
</code></pre>

