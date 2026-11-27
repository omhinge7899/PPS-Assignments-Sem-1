#include <stdio.h>
#include <string.h>
// Om Hinge

#define MAX 100

struct Sensor {
    int id;
    char type[30];
    float reading, min, max;
};

void accept(struct Sensor s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter Sensor ID: ");
        scanf("%d", &s[i].id);
        printf("Enter Sensor Type: ");
        scanf("%29s", s[i].type);
        printf("Enter Reading, Minimum and Maximum: ");
        scanf("%f %f %f", &s[i].reading, &s[i].min, &s[i].max);
        if (s[i].min > s[i].max) {
            printf("Invalid range!\n");
            i--;
        }
    }
}

int normal(struct Sensor *p) {
    return p->reading >= p->min && p->reading <= p->max;
}

void classify(struct Sensor s[], int n) {
    printf("\nSensor Classification:\n");
    for (int i = 0; i < n; i++)
        printf("\nSensor %d: %s", s[i].id, normal(&s[i]) ? "NORMAL" : "ABNORMAL");
    printf("\n");
}

void average(struct Sensor s[], int n) {
    char type[30];
    float sum = 0;
    int count = 0;

    printf("\nEnter Sensor Type for Average: ");
    scanf("%29s", type);
    for (int i = 0; i < n; i++)
        if (strcmp(s[i].type, type) == 0) {
            sum += s[i].reading;
            count++;
        }
    if (count)
        printf("Average Reading = %.2f\n", sum / count);
    else
        printf("No sensors of that type.\n");
}

void abnormal(struct Sensor s[], int n) {
    printf("\nAbnormal Sensors:\n");
    int any = 0;
    for (int i = 0; i < n; i++)
        if (!normal(&s[i])) {
            printf("ID: %d Type: %s Reading: %.2f\n", s[i].id, s[i].type, s[i].reading);
            any = 1;
        }
    if (!any)
        printf("None\n");
}

int main(void) {
    struct Sensor s[MAX];
    int n;

    printf("Enter Number of Sensors: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of sensors.\n");
        return 1;
    }
    accept(s, n);
    classify(s, n);
    average(s, n);
    abnormal(s, n);
    return 0;
}
