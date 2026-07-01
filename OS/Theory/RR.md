# Round Robin (RR) and Shortest Job First (SJF) CPU Scheduling Algorithms

## **Round Robin (RR) Scheduling**

### **Overview**

Round Robin (RR) is a **preemptive scheduling algorithm** primarily used in **time-sharing systems**. Each process is assigned a **fixed time quantum (TQ)** and executed cyclically. If a process is not completed within its time quantum, it is placed at the end of the ready queue.

### **Key Features**

* **Type:** Preemptive
* **Basis:** Fixed time quantum
* **Goal:** Fair CPU allocation and reduced starvation
* **Common Use:** Time-sharing operating systems

### **Algorithm Steps**

1. Place all processes in the ready queue by their arrival order.
2. Assign CPU for one time quantum (TQ) to the first process.
3. If the process finishes → remove it; else → move it to the end of the queue.
4. Repeat until all processes complete.

### **Formulas**

* Turnaround Time (TAT) = Completion Time - Arrival Time
* Waiting Time (WT) = Turnaround Time - Burst Time
* Average WT = ΣWT / n
* Average TAT = ΣTAT / n

### **Example**

Processes: P1, P2, P3, P4
Arrival Time: 0, 1, 2, 3
Burst Time: 5, 4, 2, 1
Time Quantum: 3

**Gantt Chart:** P1 → P2 → P3 → P4 → P1 → P2

| Process | AT | BT | WT | TAT |
| ------- | -- | -- | -- | --- |
| P1      | 0  | 5  | 6  | 11  |
| P2      | 1  | 4  | 6  | 10  |
| P3      | 2  | 2  | 2  | 4   |
| P4      | 3  | 1  | 1  | 2   |

**Avg WT = 3.75**, **Avg TAT = 6.75**

### **Advantages**

* Simple and fair scheduling
* Reduces starvation by giving each process CPU access

### **Disadvantages**

* High context switching if TQ is small
* If TQ is too large, behaves like FCFS

### **Viva Questions**

* What type of scheduling is RR? → Preemptive
* What is the main parameter? → Time Quantum
* What happens if TQ is small? → More context switches
* What if TQ is large? → Becomes like FCFS
