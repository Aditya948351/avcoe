# Address Book Using Shell Script

## **Program 1(B): Address Book**

### **Aim:**

To write a shell script that implements an **Address Book** with options to create, view, insert, delete, and modify records.

---

## **Theory (Short)**

A **shell script** automates system tasks using Linux commands. This program demonstrates **file handling**, **loops**, and **conditional statements** to manage an address book. Data is stored in a text file (`addressbook.txt`), where each record contains `LastName, FirstName, Email, Phone`.

The script provides a menu-driven interface allowing the user to:

1. Create a new address book file
2. View existing records
3. Insert a new record
4. Delete an existing record
5. Modify any record
6. Exit the program

It uses fundamental shell commands like `touch`, `grep`, `sed`, `cat`, and `read` to perform all operations.

---

## **Key Commands Used**

| **Command** | **Purpose**                            |
| ----------- | -------------------------------------- |
| `touch`     | Creates a new file if it doesn’t exist |
| `cat`       | Displays the contents of a file        |
| `grep`      | Searches for text within the file      |
| `sed`       | Edits or deletes lines in the file     |
| `read`      | Takes input from the user              |

---

## **Algorithm**

1. Display a menu with choices for different operations.
2. Based on user input, call respective functions:

   * **Create:** Check if file exists, else create it.
   * **View:** Display file content if not empty.
   * **Insert:** Append new record to the file.
   * **Delete:** Search and remove record using `sed`.
   * **Modify:** Find and update record using `sed`.
   * **Exit:** Terminate the program.
3. Continue the loop until user selects **Exit**.

---

## **Sample Output**

```
1. Create Address Book
2. View Address Book
3. Insert a Record
4. Delete a Record
5. Modify a Record
6. Exit
==============================
Enter your choice: 3
Enter record in format: LastName,FirstName,Email,Phone
Doe,John,john.doe@gmail.com,9876543210
Record inserted.
```

---

## **Viva Questions**

| **Question**                                  | **Answer**                                               |
| --------------------------------------------- | -------------------------------------------------------- |
| What is the purpose of `grep` in this script? | To search for matching records (name/email) in the file. |
| Which command modifies or deletes records?    | `sed`                                                    |
| How is the address book stored?               | As plain text in `addressbook.txt`.                      |
| Why is `touch` used?                          | To create a file if it doesn’t already exist.            |

---

## **Conclusion**

This shell script demonstrates simple **file handling and automation** in Linux using Bash. It provides a basic menu-driven **Address Book Management System**, showcasing practical use of commands, loops, and conditionals in shell scripting.
