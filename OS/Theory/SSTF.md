# SSTF (Shortest Seek Time First) Disk Scheduling Algorithm

## **Program 8: SSTF Disk Scheduling**

### **Aim:**

To implement the **Shortest Seek Time First (SSTF)** Disk Scheduling Algorithm to calculate the total head movement and sequence of servicing disk I/O requests.

---

## **Theory**

In disk scheduling, when multiple I/O requests are waiting, an algorithm decides the **order in which requests are serviced** to minimize seek time.

The **SSTF (Shortest Seek Time First)** algorithm selects the **pending request closest to the current head position**. This reduces the total head movement compared to the **FCFS (First Come First Serve)** method.

However, SSTF may lead to **starvation** for requests that are far from the current head position.

---

## **Algorithm Steps**

1. Input the number of disk requests and their track positions.
2. Input the initial head position.
3. Calculate the **absolute distance** between the head and each pending request.
4. Select the request with the **minimum distance** (shortest seek time).
5. Move the head to that position and mark it as visited.
6. Repeat until all requests are serviced.
7. Compute the total head movement as the sum of all seek distances.

---

## **Formulas**

* **Seek Time (ST)** = | Current Head – Next Request |
* **Total Head Movement (THM)** = Σ(ST)

---

## **Example**

**Input:**
Requests: 82, 170, 43, 140, 24, 16, 190
Initial Head: 50

**Sequence of Execution:** 50 → 43 → 24 → 16 → 82 → 140 → 170 → 190
**Total Head Movement:** 236 cylinders

---

## **Advantages**

* Less total head movement compared to FCFS.
* Reduces average response time.

## **Disadvantages**

* Causes **starvation** for distant requests.
* Complex to implement compared to FCFS.

---

## **Sample Output**

```
Enter number of disk requests: 7
Enter disk requests: 82 170 43 140 24 16 190
Enter initial head position: 50

--- SSTF (Shortest Seek Time First) Disk Scheduling ---
Sequence: 50 -> 43 -> 24 -> 16 -> 82 -> 140 -> 170 -> 190
Total head movement: 236
```

---

## **Viva Questions**

| **Question**                    | **Answer**                                                                  |
| ------------------------------- | --------------------------------------------------------------------------- |
| What is SSTF Scheduling?        | An algorithm that selects the request closest to the current head position. |
| What is the main goal of SSTF?  | To minimize total seek time (head movement).                                |
| What is the drawback of SSTF?   | Starvation of faraway requests.                                             |
| How does SSTF differ from FCFS? | SSTF chooses nearest request; FCFS serves in arrival order.                 |
| Is SSTF preemptive?             | No, it’s a non-preemptive scheduling algorithm.                             |

---

## **Conclusion**

The **SSTF Disk Scheduling Algorithm** effectively reduces the total head movement by selecting the nearest request at each step. While efficient, it can cause starvation for distant requests if nearby ones keep arriving.
