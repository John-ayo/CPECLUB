## Mini Firewall (Packet Filtering)

### Objective
A firewall that filters and orders network packets based on priority and sequence.

### How it works
- Reads 10 packets from a `packets.txt` file
- Each packet has a serial number and a priority (1 being highest, 10 being lowest)
- Outputs serial numbers ordered by highest priority, then by lowest serial number for ties

### How to run
bash
gcc firewall.c -o firewall
./firewall

### Input format (packets.txt)
1, 5
10, 1
3, 2
7, 1
4, 3

### Output
Filtered Packet Order:
SerialNo: 7  | Priority: 1
SerialNo: 10 | Priority: 1
SerialNo: 3  | Priority: 2
SerialNo: 4  | Priority: 3
SerialNo: 1  | Priority: 5

---
