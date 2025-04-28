<h1>Database Management systems</h1>


#1. Study of MySQL

<p>MySQL is an open-source, fast, scalable RDBMS supporting ACID properties.
  <h2>ACID Properties are as follows: </h2>
   <li> 1.Atomicity   : All the operations within a tractions must either succeed fully or fail entirely. If one side fails other side also fails.
   <li> 2.Consistency : The database remains valid and follows all rules. like using constraints like Primary Key and foreign Key.
   <li> 3.Isolation   : Transactions happening at same time dont affect each other.Two different users working on a database at a time.
   <li> 4.Durability  : Once the transaction is committed, Its changes are permanent. Achieved by write ahead logs or Backups.
</p>
#2. Install and Configure MySQL :
<p> 
  (wsl --install)- in windows to run ubuntu terminal in windows.
  To install MySQL Server on Linux:
  1. Update the package list: `sudo apt update`
  
  2. Install MySQL Server: `sudo apt install mysql-server`
  
  3. Start the MySQL service: `sudo systemctl start mysql`
  
  4. Secure the installation: `sudo mysql_secure_installation`
  
  5. Log in as the MySQL root user: `sudo mysql -u root -p`

</p>
