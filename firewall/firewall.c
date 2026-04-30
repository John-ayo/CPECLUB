#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int serialNo; 
    int priority;
} Packet;

int compare(const void *a, const void *b) {
    Packet *p1 = (Packet *)a;
    Packet *p2 = (Packet *)b;

    if (p1->priority != p2->priority)
        return p1->priority - p2->priority;
    return p1->serialNo - p2->serialNo;
}

int main() {
    FILE *file = fopen("packets.txt", "r");
    if (!file) {
        printf("Error: could not open packets.txt\n");
        return 1;
    }

    Packet packets[10];
    int count = 0;

    while (count < 10 && fscanf(file, "%d, %d", &packets[count].serialNo, &packets[count].priority) == 2) {
        count++;
    }

    fclose(file);

    qsort(packets, count, sizeof(Packet), compare);

    printf("Filtered Packet Order:\n");
    for (int i = 0; i < count; i++) {
        printf("SerialNo: %d | Priority: %d\n", packets[i].serialNo, packets[i].priority);
    } 

    return 0;
}

