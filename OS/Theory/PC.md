# Producer-Consumer Problem Using Semaphores and Mutex

## **Program 4(A): Thread Synchronization Using Counting Semaphores**

### **Aim:**

To implement the **Producer-Consumer Problem** using **POSIX threads**, **counting semaphores**, and **mutex locks** for synchronization.

---

## **Theory**

The **Producer-Consumer problem** is a classic example of a **multi-process synchronization problem**. It describes two processes — **Producer** and **Consumer** — that share a **fixed-size buffer**. The producer generates data and places it into the buffer, while the consumer retrieves data from it.

The key challenge is ensuring that:

* The **producer** doesn’t add data into a **full buffer**.
* The **consumer** doesn’t remove data from an **empty buffer**.

To handle this, synchronization tools like **semaphores** and **mutex locks** are used to control access to the shared buffer and avoid **race conditions**.

---

## **Algorithm**

1. Initialize semaphores:

   * `empty` = total buffer slots.
   * `full` = 0 (initially, no items to consume).
   * Initialize `mutex` for mutual exclusion.
2. Create **Producer** and **Consumer** threads.
3. **Producer Process:**

   * Wait on `empty` (wait if buffer is full).
   * Lock `mutex`.
   * Produce an item and add it to the buffer.
   * Unlock `mutex`.
   * Signal `full` (item available for consumption).
4. **Consumer Process:**

   * Wait on `full` (wait if buffer is empty).
   * Lock `mutex`.
   * Consume an item from the buffer.
   * Unlock `mutex`.
   * Signal `empty` (space available for new item).
5. Repeat until 10 items are produced and consumed.
6. Destroy semaphores and mutex after completion.

---

## **Key Functions Used**

| **Function**             | **Purpose**                                          |
| ------------------------ | ---------------------------------------------------- |
| `pthread_create()`       | Creates producer and consumer threads.               |
| `sem_init()`             | Initializes semaphores.                              |
| `sem_wait()`             | Decrements semaphore value; blocks if value ≤ 0.     |
| `sem_post()`             | Increments semaphore value (signals another thread). |
| `pthread_mutex_lock()`   | Locks critical section for mutual exclusion.         |
| `pthread_mutex_unlock()` | Unlocks critical section.                            |
| `pthread_join()`         | Waits for threads to finish.                         |

---

## **Sample Output**

```
Producer produced 1
Consumer consumed 1
Producer produced 2
Consumer consumed 2
Producer produced 3
Consumer consumed 3
...
Producer produced 10
Consumer consumed 10
```

---

## **Explanation**

* The **buffer** acts as the shared resource of fixed size.
* The **Producer thread** adds items to the buffer until it’s full, and then waits.
* The **Consumer thread** removes items from the buffer until it’s empty, and then waits.
* **Semaphores** `empty` and `full` manage buffer status.
* **Mutex** ensures only one thread accesses the buffer at a time, avoiding race conditions.

---

## **Advantages**

* Prevents race conditions and ensures proper synchronization.
* Demonstrates correct use of semaphores and mutexes for thread communication.

## **Disadvantages**

* Works only for single producer and single consumer in this simple implementation.
* Increased overhead due to thread synchronization.

---

## **Viva Questions**

| **Question**                                            | **Answer**                                                                                 |
| ------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| What is the Producer-Consumer problem?                  | A synchronization problem involving shared buffer access by producer and consumer threads. |
| Why use semaphores?                                     | To synchronize producer and consumer activities and manage buffer availability.            |
| What is the role of `mutex`?                            | Ensures mutual exclusion while accessing shared resources.                                 |
| What are `sem_wait()` and `sem_post()` used for?        | `sem_wait()` decrements semaphore (wait), `sem_post()` increments semaphore (signal).      |
| What happens if `sem_wait()` is called when value is 0? | The thread is blocked until the semaphore becomes positive.                                |
| How does this program prevent race conditions?          | By locking critical sections with `pthread_mutex_lock()` and unlocking after operations.   |

---

## **Conclusion**

The **Producer-Consumer program** using semaphores and mutex successfully demonstrates **thread synchronization**. It ensures that the producer and consumer operate in a coordinated manner, preventing buffer overflow and underflow while maintaining mutual exclusion.
