# Inter-Process Communication Using PIPE

## **Theory Overview**

### **Definition**

A **pipe** is an **unnamed, unidirectional communication channel** used for **Inter-Process Communication (IPC)** between **related processes**, such as a **parent** and its **child**. It enables data to flow in one direction — one process writes into the pipe, and another reads from it.

When two pipes are used, they allow **full-duplex communication** (both-way data exchange).

### **Purpose**

The goal of using a pipe is to allow processes to exchange data without using intermediate files or shared memory, providing a fast and efficient communication mechanism.

### **Key Features**

* Works between **related processes** (created via `fork()`)
* Data flows in **First-In-First-Out (FIFO)** order
* **Unidirectional** by default (one-way communication)
* Exists **temporarily in memory** (not a file on disk)
* Can be made **full-duplex** using two pipes

---

## **Algorithm Steps**

1. **Create Pipe(s):** Use `pipe()` system call to create one or two pipes.
2. **Fork Process:** Create a child process using `fork()`.
3. **Close Unused Ends:** Each process closes the pipe ends it doesn’t use.

   * Parent closes the read end of the first pipe.
   * Child closes the write end of the first pipe.
4. **Communication:**

   * Parent writes data into pipe.
   * Child reads data, processes it, and can send a response back using another pipe.
5. **Display Result:** Parent displays the received response.
6. **Close Pipes:** Both processes close all pipe ends after communication.

---

## **System Calls Used**

| **System Call**     | **Purpose**                                                               |
| ------------------- | ------------------------------------------------------------------------- |
| `pipe(int fd[2])`   | Creates a unidirectional pipe. `fd[0]` is read end, `fd[1]` is write end. |
| `fork()`            | Creates a child process to communicate with parent.                       |
| `read(fd, buf, n)`  | Reads data from pipe into buffer.                                         |
| `write(fd, buf, n)` | Writes data into pipe.                                                    |
| `close(fd)`         | Closes a file descriptor to prevent deadlock.                             |

---

## **Example Explanation**

**1. Parent Process:**

* Creates two pipes for full-duplex communication.
* Sends a text message to the child process through the first pipe.
* Reads back the processed result from the second pipe.

**2. Child Process:**

* Reads the message sent by the parent.
* Processes it (for example, counts characters, words, and lines).
* Sends the analysis back to the parent using the second pipe.

---

## **Program Flow (Simplified)**

```
Parent Process           Child Process
     |                         |
   pipe()  -------------------> |
     |                         |
   fork()                      |
     |                         |
 write(fd1[1], msg)            |
 -----------------------------> |
     |                      read(fd1[0])
     |                         |
 read(fd2[0]) <---------------- |
     |                      write(fd2[1], response)
     |                         |
 Display Result                 |
     |                         |
   close all()                 close all()
```

---

## **Advantages**

* Simple and fast communication between parent and child processes.
* Avoids disk I/O by storing data in kernel memory.
* Lightweight compared to message queues or shared memory.

## **Disadvantages**

* Works **only between related processes**.
* Default communication is **half-duplex** (requires two pipes for full-duplex).
* Lacks synchronization mechanisms.

---

## **Viva Questions and Answers**

| **Question**                                  | **Answer**                                                                                                   |
| --------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| What is a Pipe in IPC?                        | A unidirectional communication channel between related processes.                                            |
| Is a Pipe full-duplex?                        | No, it’s half-duplex by default; needs two pipes for full-duplex.                                            |
| Which system call is used to create a pipe?   | `pipe()`                                                                                                     |
| What is the difference between PIPE and FIFO? | PIPE is unnamed and works between related processes; FIFO is named and can work between unrelated processes. |
| Where is PIPE data stored?                    | In kernel buffer (temporary memory).                                                                         |
| What happens if a pipe isn’t closed properly? | It can cause blocking or deadlock.                                                                           |
| What is the advantage of PIPE over FIFO?      | Faster communication as it avoids filesystem overhead.                                                       |

---

## **Conclusion**

The **PIPE IPC mechanism** provides a simple and efficient method for communication between related processes. By using two pipes, full-duplex communication can be achieved, making it a lightweight yet powerful tool for process synchronization and data exchange in Unix/Linux systems.
