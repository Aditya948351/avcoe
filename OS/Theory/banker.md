# Banker's Algorithm (Deadlock Avoidance)

## **Theory Overview**

### **Definition**

The **Banker's Algorithm** is a **deadlock avoidance algorithm** that checks resource allocation safety by simulating resource allocation before granting a request. It ensures the system remains in a **safe state**, meaning that all processes can complete without leading to deadlock.

### **Purpose**

The algorithm prevents deadlock by ensuring that resource allocation does not lead the system into an unsafe state. It is named "Banker’s Algorithm" because it was originally used by bankers to check whether granting loans would leave the bank in a safe position.

---

## **Key Concepts**

| Term                        | Description                                                               |
| --------------------------- | ------------------------------------------------------------------------- |
| **Processes (P1, P2, ...)** | Entities that request and release resources.                              |
| **Resources (R1, R2, ...)** | Different types of resources such as memory, printers, etc.               |
| **Available[]**             | Vector indicating how many instances of each resource are available.      |
| **Max[][]**                 | Maximum demand of each process for each resource.                         |
| **Allocation[][]**          | Resources currently allocated to each process.                            |
| **Need[][]**                | Remaining resources required by each process (`Need = Max - Allocation`). |

---

## **Algorithm Steps**

### **Step 1: Calculate Need Matrix**

[ Need[i][j] = Max[i][j] - Allocation[i][j] ]

### **Step 2: Initialize**

* `Work = Available`
* `Finish[i] = false` for all i

### **Step 3: Find a Process (Pᵢ)**

Find an index `i` such that:

* `Finish[i] == false`
* `Need[i] <= Work`

### **Step 4: Resource Allocation Simulation**

If such a process is found:

* `Work = Work + Allocation[i]`
* `Finish[i] = true`
* Add Pᵢ to the **safe sequence**.

### **Step 5: Repeat Steps 3–4**

Repeat until all processes are finished (system safe) or no such process exists (system unsafe).

### **Step 6: Safe State Check**

* If all `Finish[i] = true`, the system is in **safe state**.
* Otherwise, the system is **in deadlock**.

---

## **Example**

**Given:**

Number of Processes = 5
Number of Resources = 3

**Allocation Matrix:**

| P  | R1 | R2 | R3 |
| -- | -- | -- | -- |
| P0 | 0  | 1  | 0  |
| P1 | 2  | 0  | 0  |
| P2 | 3  | 0  | 2  |
| P3 | 2  | 1  | 1  |
| P4 | 0  | 0  | 2  |

**Maximum Matrix:**

| P  | R1 | R2 | R3 |
| -- | -- | -- | -- |
| P0 | 7  | 5  | 3  |
| P1 | 3  | 2  | 2  |
| P2 | 9  | 0  | 2  |
| P3 | 2  | 2  | 2  |
| P4 | 4  | 3  | 3  |

**Available Vector:** 3 3 2

**Need Matrix (Max - Allocation):**

| P  | R1 | R2 | R3 |
| -- | -- | -- | -- |
| P0 | 7  | 4  | 3  |
| P1 | 1  | 2  | 2  |
| P2 | 6  | 0  | 0  |
| P3 | 0  | 1  | 1  |
| P4 | 4  | 3  | 1  |

**Safe Sequence:** P1 → P3 → P4 → P0 → P2
**System State:** SAFE ✅

---

## **Advantages**

* Prevents deadlock by maintaining a safe state.
* System safety is checked before granting resources.

## **Disadvantages**

* Requires advance knowledge of maximum resource needs.
* Not suitable for systems with frequent resource changes.
* Involves complex and time-consuming calculations.

---

## **Viva Questions and Answers**

| **Question**                         | **Answer**                                                                        |
| ------------------------------------ | --------------------------------------------------------------------------------- |
| What is Banker’s Algorithm?          | A deadlock avoidance algorithm ensuring system safety before resource allocation. |
| Why is it called Banker’s Algorithm? | Because it models resource allocation like a banker granting loans safely.        |
| What is a Safe State?                | A condition where all processes can complete execution without causing deadlock.  |
| What are the matrices used?          | Allocation, Max, Need, and Available.                                             |
| What happens in an Unsafe State?     | The system may enter deadlock if resources are allocated further.                 |
| What is the formula for Need?        | `Need[i][j] = Max[i][j] - Allocation[i][j]`.                                      |
| How is a Safe Sequence determined?   | By simulating allocations and checking if all processes can finish.               |

---

## **Conclusion**

The **Banker’s Algorithm** is a reliable method for **deadlock avoidance** by checking the system’s safety before resource allocation. Though computationally intensive, it ensures that the system never enters a deadlock, making it crucial in critical resource management environments.
