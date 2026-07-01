# Demonstration of Fork System Call – Orphan and Zombie Processes

## **Program 2(A): Fork, Orphan, and Zombie Process Demonstration**

### **Aim:**

To implement a C program that uses the **`fork()`** system call to create a child process. Both parent and child processes perform sorting, demonstrating **Zombie** and **Orphan** process states.

---

## **Theory**

In UNIX/Linux, the **`fork()`** system call is used to create a new process. The created process is called a **child process**, and the original one is the **parent process**. Both processes execute the same code but operate independently.

This program demonstrates two special process states:

1. **Zombie Process** – A process that has finished execution but still has an entry in the process table because its parent has not yet called `wait()`.
2. **Orphan Process** – A process whose parent terminates before it does. The orphaned process is then adopted by the `init` or `systemd` process.

---

## **Algorithm**

1. Accept `n` integers from the user and store them in an array.
2. Call the **`fork()`** system call to create a child process.
3. If **`pid == 0`** (Child process):

   * Sort the array and display the result.
   * Use `sleep(5)` to delay termination so that the parent exits first (creating an orphan).
   * Print its new parent PID using `getppid()`.
4. If **`pid > 0`** (Parent process):

   * Sort the array and display the result.
   * Use `sleep(5)` to delay calling `wait()`, creating a temporary zombie.
   * Call `wait()` to clean up the zombie process.
5. End both processes.

---

## **System Calls Used**

| **System Call** | **Description**                                                  |
| --------------- | ---------------------------------------------------------------- |
| `fork()`        | Creates a new child process.                                     |
| `getpid()`      | Returns the process ID of the current process.                   |
| `getppid()`     | Returns the parent process ID.                                   |
| `sleep()`       | Suspends process execution temporarily.                          |
| `wait()`        | Makes parent wait for child completion and removes zombie state. |

---

## **Sample Output**

```
Enter count: 5
Enter 5 integers:
5 3 1 4 2

Parent PID: 1025
Sorted by Parent: 1 2 3 4 5
Creating Zombie... Child will finish and become zombie for 5 seconds

Child PID: 1026
Sorted by Child: 1 2 3 4 5
Child became orphan. New parent PID = 1

Zombie cleared using wait(). Parent exiting now.
```

---

## **Explanation**

* The **parent** process sorts the data and delays calling `wait()` to let the child become a zombie temporarily.
* The **child** process also sorts data and calls `sleep(5)` to continue execution after the parent terminates, becoming an orphan.
* The output shows both process IDs and demonstrates how process states transition between **running → zombie → cleaned**, and **orphan → adopted by init**.

---

## **Viva Questions**

| **Question**                  | **Answer**                                                    |
| ----------------------------- | ------------------------------------------------------------- |
| What does `fork()` do?        | Creates a new process called a child process.                 |
| What is returned by `fork()`? | 0 to the child, child's PID to the parent, and -1 on failure. |
| What is a Zombie process?     | A finished process whose parent hasn’t called `wait()`.       |
| What is an Orphan process?    | A process whose parent terminated before it finished.         |
| How do you remove a zombie?   | By calling `wait()` or `waitpid()` in the parent.             |
| Who adopts an orphan process? | The `init` (or `systemd`) process.                            |

---

## **Conclusion**

This program effectively demonstrates how the **`fork()`** system call creates concurrent processes and how improper synchronization leads to **Zombie** and **Orphan** process states. It provides practical insight into process management and UNIX system calls.
