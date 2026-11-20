#include <stdio.h>
#include <string.h>

struct Device {
    int id;
    char type[10];      // Diode / BJT / MOSFET / LED
    float vf;           // Forward voltage (V)
    float ir;           // Reverse leakage current (uA)
    float vr;           // Rated voltage (V)
    char status[6];     // "Pass" / "Fail"
};

void getLimits(char type[], float *maxVf, float *maxIr, float *minVr)
{
    if (strcmp(type, "Diode") == 0) {
        *maxVf = 0.8;  *maxIr = 5.0;   *minVr = 50.0;
    } else if (strcmp(type, "BJT") == 0) {
        *maxVf = 0.8;  *maxIr = 10.0;  *minVr = 40.0;
    } else if (strcmp(type, "MOSFET") == 0) {
        *maxVf = 1.0;  *maxIr = 10.0;  *minVr = 30.0;
    } else {            /* LED */
        *maxVf = 3.3;  *maxIr = 10.0;  *minVr = 5.0;
    }
}

int main()
{
    struct Device d[50];
    int n, i, failCount = 0;
    float maxVf, maxIr, minVr;

    printf("Enter number of devices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for device %d:\n", i + 1);
        printf("Device ID: ");
        scanf("%d", &d[i].id);
        printf("Device Type (Diode/BJT/MOSFET/LED): ");
        scanf("%s", d[i].type);
        printf("Forward Voltage Vf (V): ");
        scanf("%f", &d[i].vf);
        printf("Reverse Leakage Current Ir (uA): ");
        scanf("%f", &d[i].ir);
        printf("Rated Voltage Vr (V): ");
        scanf("%f", &d[i].vr);

        getLimits(d[i].type, &maxVf, &maxIr, &minVr);

        if (d[i].vf > maxVf || d[i].ir > maxIr || d[i].vr < minVr) {
            strcpy(d[i].status, "Fail");
            failCount++;
        } else {
            strcpy(d[i].status, "Pass");
        }
    }

    printf("\n%-6s %-8s %-8s %-8s %-8s %-6s\n",
           "ID", "Type", "Vf", "Ir", "Vr", "Status");
    for (i = 0; i < n; i++) {
        printf("%-6d %-8s %-8.2f %-8.2f %-8.2f %-6s\n",
               d[i].id, d[i].type, d[i].vf, d[i].ir, d[i].vr, d[i].status);
    }

    printf("\nFailed (Out of Spec) devices: %d\n", failCount);
    for (i = 0; i < n; i++) {
        if (strcmp(d[i].status, "Fail") == 0)
            printf("Device ID %d (%s)\n", d[i].id, d[i].type);
    }

    return 0;
}
