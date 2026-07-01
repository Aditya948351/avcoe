# Optimal Page Replacement Algorithm

## **Program 7(B): Optimal Page Replacement**

### **Aim:**

To implement the **Optimal Page Replacement Algorithm** to find the number of **page faults** and the sequence of page replacements for a given reference string.

---

## **Theory**

The **Optimal Page Replacement Algorithm** replaces the page that will **not be used for the longest period of time** in the future. It is the most efficient page replacement technique because it results in the **minimum number of page faults**.

However, it is **impractical in real systems** because future page references are unknown. It is mainly used for theoretical comparison and performance evaluation of other algorithms like **FIFO** and **LRU**.

---

## **Algorithm Steps**

1. Initialize all frames to `-1` (empty).
2. For each page reference in the string:

   * If the page is already present in a frame → **Page Hit** (no replacement).
   * Else, if there is an empty frame → place the page directly.
   * Else → find the page that will **not be used for the longest time** in the future and replace it.
3. Increment the **page fault counter** for every page miss.
4. Display the content of frames after each replacement.
5. Display total page faults at the end.

---

## **Formulas**

* **Page Fault:** Occurs when a page is not found in memory.
* **Hit Ratio:** ( = \frac{\text{Page Hits}}{\text{Total References}} )
* **Miss Ratio:** ( = 1 - \text{Hit Ratio} )

---

## **Example**

**Input:**

```
Frames = 3
Reference String = 7 0 1 2 0 3 0 4 2 3 0 3
```

**Frame Status:**

```
7	-	-
7	0	-
7	0	1
2	0	1
2	0	1
2	3	1
2	3	0
4	3	0
4	3	2
4	3	2
0	3	2
0	3	2
```

**Total Page Faults:** 9

---

## **Advantages**

* Produces **minimum number of page faults** (theoretically optimal).
* Provides a performance benchmark for other algorithms.

## **Disadvantages**

* Requires **future knowledge** of page references (not practical for real systems).
* Used only for **simulation and comparison**.

---

## **Sample Output**

```
Enter number of frames: 3
Enter number of pages: 12
Enter page reference string: 7 0 1 2 0 3 0 4 2 3 0 3

-	-	-
7	-	-
7	0	-
7	0	1
2	0	1
2	3	1
2	3	0
4	3	0
4	3	2
4	3	2
0	3	2
0	3	2

Total Page Faults = 9
```

---

## **Viva Questions**

| **Question**                                    | **Answer**                                                                        |
| ----------------------------------------------- | --------------------------------------------------------------------------------- |
| What is the Optimal Page Replacement Algorithm? | It replaces the page that will not be used for the longest time in the future.    |
| Why is it called Optimal?                       | Because it results in the minimum number of page faults.                          |
| Is it used in real systems?                     | No, because future references are unknown.                                        |
| What are Page Hits and Page Faults?             | A hit means the page is already in memory; a fault means the page must be loaded. |
| Which algorithms are compared against Optimal?  | FIFO and LRU.                                                                     |

---

## **Conclusion**

The **Optimal Page Replacement Algorithm** provides the least number of page faults by selecting the page to be replaced based on future use. Though not practical for real-world systems, it serves as an **ideal reference** for evaluating other page replacement algorithms.
