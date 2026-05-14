#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// == Constants == //
#define MAX_STUDENTS 100
#define COURSES_PER_STUDENT 5
#define IMPORT_FILE "students.txt"
#define EXPORT_FILE "database_backup.txt"
 
// == Struct Definition (as specified in the project doc) == //
struct sinfo {
    char fname[50];
    char lname[50];
    int  roll;
    float cgpa;
    int  cid[COURSES_PER_STUDENT];
};
 
// == Global storage == //
struct sinfo students[MAX_STUDENTS];
int student_count = 0;
 
// == UTILITY: Print a single student record neatly == //
void print_student(struct sinfo *s) {
    printf("  Name       : %s %s\n", s->fname, s->lname);
    printf("  Roll No.   : %d\n", s->roll);
    printf("  CGPA       : %.2f\n", s->cgpa);
    printf("  Courses    : ");
    for (int i = 0; i < COURSES_PER_STUDENT; i++) {
        printf("%d", s->cid[i]);
        if (i < COURSES_PER_STUDENT - 1) printf(", ");
    }
    printf("\n");
}
 
// == UTILITY: Find student index by roll number == //
// == ALGORITHM: Simple/Linear Search - O(n) == //
// == From Grokking Ch.1: check each element one at a time. == //
// == Returns index if found, -1 if not found. == //
int find_by_roll(int roll) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll == roll) {
            return i; /* O(1) array access at found position */
        }
    }
    return -1;
}
 
// == FUNCTION 1: Add Student (Manual Input) //
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("[ERROR] Storage full. Maximum %d students reached.\n", MAX_STUDENTS);
        return;
    }
 
    struct sinfo *s = &students[student_count];
 
    printf("\n--- Add New Student ---\n");
    printf("First Name  : "); scanf("%49s", s->fname);
    printf("Last Name   : "); scanf("%49s", s->lname);
    printf("Roll Number : "); scanf("%d", &s->roll);
 
    /* Check for duplicate roll number - linear search O(n) */
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll == s->roll) {
            printf("[ERROR] Roll number %d already exists.\n", s->roll);
            return;
        }
    }
 
    printf("CGPA        : "); scanf("%f", &s->cgpa);
    printf("Enter 5 Course IDs:\n");
    for (int i = 0; i < COURSES_PER_STUDENT; i++) {
        printf("  Course %d ID: ", i + 1);
        scanf("%d", &s->cid[i]);
    }
 
    student_count++;
    printf("[SUCCESS] Student '%s %s' added. Total records: %d\n",
           s->fname, s->lname, student_count);
}
 
// == FUNCTION 2: Bulk Import from .txt file == //
// == Uses fscanf in a while loop as specified in the project doc. == //
// == File format: FirstName LastName RollNumber CGPA C1 C2 C3 C4 C5 == //
void bulk_import() {
    FILE *file = fopen(IMPORT_FILE, "r");
 
    /* Always check file pointer - prevents segmentation fault */
    if (file == NULL) {
        printf("[ERROR] Could not open '%s'. Make sure the file exists.\n", IMPORT_FILE);
        return;
    }
 
    int imported = 0;
 
    // fscanf returns the number of fields successfully read.
    // We expect 9 fields per record. The loop runs as long as fscanf reads all 9 fields successfully.
    while (student_count < MAX_STUDENTS) {
        struct sinfo temp;
        int fields_read = fscanf(file,
            "%49s %49s %d %f %d %d %d %d %d",
            temp.fname, temp.lname, &temp.roll, &temp.cgpa,
            &temp.cid[0], &temp.cid[1], &temp.cid[2],
            &temp.cid[3], &temp.cid[4]);
 
        if (fields_read != 9) break; // end of file or malformed line
 
        // Skip duplicates 
        if (find_by_roll(temp.roll) != -1) {
            printf("[SKIP] Roll %d already exists in memory.\n", temp.roll);
            continue;
        }
 
        students[student_count++] = temp;
        imported++;
    }
 
    fclose(file);
    printf("[SUCCESS] Imported %d student(s). Total records: %d\n",
           imported, student_count);
}
 
// == FUNCTION 3: Download All Students to .txt file == //
// == Mirrors the import format so the file can be re-imported later. == //
void download_all() {
    if (student_count == 0) {
        printf("[INFO] No records in memory to export.\n");
        return;
    }
 
    FILE *file = fopen(EXPORT_FILE, "w");
    if (file == NULL) {
        printf("[ERROR] Could not create '%s'.\n", EXPORT_FILE);
        return;
    }
 
    // Scan the array from index 0 to student_count - 1 
    for (int i = 0; i < student_count; i++) {
        struct sinfo *s = &students[i];
        fprintf(file, "%s %s %d %.2f %d %d %d %d %d\n",
            s->fname, s->lname, s->roll, s->cgpa,
            s->cid[0], s->cid[1], s->cid[2], s->cid[3], s->cid[4]);
    }
 
    fclose(file);
    printf("[SUCCESS] %d student record(s) exported to '%s'.\n",
           student_count, EXPORT_FILE);
}
 
// == FUNCTION 4: Find Student by Roll Number == //
// == Linear Search O(n) - from Grokking Ch.1 (simple search) == //
void find_by_roll_ui() {
    int roll;
    printf("\n--- Find by Roll Number ---\n");
    printf("Enter roll number: ");
    scanf("%d", &roll);
 
    int idx = find_by_roll(roll);
    if (idx == -1) {
        printf("[NOT FOUND] No student with roll number %d.\n", roll);
    } else {
        printf("[FOUND] Student record:\n");
        print_student(&students[idx]);
    }
}
 

// == FUNCTION 5: Find Student by First Name == //
// == Linear Search O(n) - checks every record for a name match. == //
// == Can return multiple results (unlike roll number which is unique). == //
void find_by_name() {
    char name[50];
    printf("\n--- Find by First Name ---\n");
    printf("Enter first name: ");
    scanf("%49s", name);
 
    int found = 0;
    for (int i = 0; i < student_count; i++) {
        // Case-sensitive comparison using strcmp from string.h 
        if (strcmp(students[i].fname, name) == 0) {
            printf("[FOUND] Record #%d:\n", found + 1);
            print_student(&students[i]);
            found++;
        }
    }
 
    if (found == 0) {
        printf("[NOT FOUND] No student with first name '%s'.\n", name);
    } else {
        printf("Total matches: %d\n", found);
    }
}
 
// == FUNCTION 6: Delete Student by Roll Number == //
// == From Grokking Ch.2 (Arrays): deleting from an array requires == //
// == shifting all subsequent elements one position back. O(n). == //
void delete_student() {
    int roll;
    printf("\n--- Delete Student ---\n");
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
 
    int idx = find_by_roll(roll);
    if (idx == -1) {
        printf("[NOT FOUND] No student with roll number %d.\n", roll);
        return;
    }
 
    printf("Deleting: %s %s (Roll: %d)\n",
           students[idx].fname, students[idx].lname, roll);
 
    /*
     * SHIFT LEFT: Fill the gap by moving every element
     * after the deleted one back by one index position.
     * This is O(n) in the worst case (deleting first element).
     */
    for (int i = idx; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
 
    student_count--;
    printf("[SUCCESS] Student deleted. Total records: %d\n", student_count);
}
 
// == FUNCTION 7: Update Student by Roll Number == //
// == Find with O(n) search, then O(1) in-place update. == //
void update_student() {
    int roll;
    printf("\n--- Update Student ---\n");
    printf("Enter roll number to update: ");
    scanf("%d", &roll);
 
    int idx = find_by_roll(roll);
    if (idx == -1) {
        printf("[NOT FOUND] No student with roll number %d.\n", roll);
        return;
    }
 
    struct sinfo *s = &students[idx];
    printf("Current record:\n");
    print_student(s);
 
    printf("\nEnter new values (leave roll number unchanged):\n");
    printf("First Name  : "); scanf("%49s", s->fname);
    printf("Last Name   : "); scanf("%49s", s->lname);
    printf("CGPA        : "); scanf("%f", &s->cgpa);
    printf("Enter 5 Course IDs:\n");
    for (int i = 0; i < COURSES_PER_STUDENT; i++) {
        printf("  Course %d ID: ", i + 1);
        scanf("%d", &s->cid[i]);
    }
 
    printf("[SUCCESS] Student record updated.\n");
    printf("Updated record:\n");
    print_student(s);
}
 
// == Display all students in memory == //
void display_all() {
    if (student_count == 0) {
        printf("[INFO] No records in memory.\n");
        return;
    }
    printf("\n--- All Students in Memory (%d records) ---\n", student_count);
    for (int i = 0; i < student_count; i++) {
        printf("\n[%d] ", i + 1);
        print_student(&students[i]);
    }
    printf("---------------------------------------------\n");
}
 
// == MAIN: Application Menu Loop == //
int main() {
    int choice;
 
    printf("CPE Hub - Student Information Management System\n");
 
    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Add Student Details (Manual Input)\n");
        printf("2. Bulk Import Students (Read from %s)\n", IMPORT_FILE);
        printf("3. Download All Students (Write to %s)\n", EXPORT_FILE);
        printf("4. Find Student by Roll Number\n");
        printf("5. Find Student by First Name\n");
        printf("6. Delete Student by Roll Number\n");
        printf("7. Update Student by Roll Number\n");
        printf("8. Display All Students\n");
        printf("9. Exit\n");
        printf("\nChoose an option (1-9): ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: add_student();     break;
            case 2: bulk_import();     break;
            case 3: download_all();    break;
            case 4: find_by_roll_ui(); break;
            case 5: find_by_name();    break;
            case 6: delete_student();  break;
            case 7: update_student();  break;
            case 8: display_all();     break;
            case 9: printf("\nExiting SIMS. Goodbye!\n"); break;
            default: printf("[ERROR] Invalid option. Enter 1-9.\n"); break;
        }
 
    } while (choice != 9);
 
    return 0;
}