#include <stdio.h>
//Om Hinge

#define FILE_NAME "field_data.txt"
#define MOISTURE_LIMIT 30.0  

typedef struct {
    int id;             // Field/Plot ID
    float moisture;     // Soil moisture (%)
    float temperature;  // Temperature (C)
    float humidity;     // Humidity (%)
    int cropHealth;     // Crop health (1 = poor, 10 = excellent)
    float latitude;     // GPS latitude
    float longitude;    // GPS longitude
} Field;

/* Store readings collected by the robot into the file */
void storeData(void) {
    FILE *fp = fopen(FILE_NAME, "a");
    Field f;
    int n, i;

    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return;
    }

    printf("How many field records to enter? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Field ID: ");
        scanf("%d", &f.id);
        printf("Soil moisture (%%): ");
        scanf("%f", &f.moisture);
        printf("Temperature (C): ");
        scanf("%f", &f.temperature);
        printf("Humidity (%%): ");
        scanf("%f", &f.humidity);
        printf("Crop health (1-10): ");
        scanf("%d", &f.cropHealth);
        printf("GPS latitude: ");
        scanf("%f", &f.latitude);
        printf("GPS longitude: ");
        scanf("%f", &f.longitude);

        fprintf(fp, "%d %f %f %f %d %f %f\n", f.id, f.moisture,
                f.temperature, f.humidity, f.cropHealth,
                f.latitude, f.longitude);
    }

    fclose(fp);
    printf("\nData stored successfully.\n");
}

/* Read stored data and show fields that need irrigation */
void findIrrigationAreas(void) {
    FILE *fp = fopen(FILE_NAME, "r");
    Field f;
    int found = 0;

    if (fp == NULL) {
        printf("No data file found. Store data first.\n");
        return;
    }

    printf("\nAreas requiring irrigation (moisture < %.1f%%):\n", MOISTURE_LIMIT);
    while (fscanf(fp, "%d %f %f %f %d %f %f", &f.id, &f.moisture,
                  &f.temperature, &f.humidity, &f.cropHealth,
                  &f.latitude, &f.longitude) == 7) {
        if (f.moisture < MOISTURE_LIMIT) {
            printf("Field %d | Moisture: %.1f%% | Location: (%.4f, %.4f)\n",
                   f.id, f.moisture, f.latitude, f.longitude);
            found = 1;
        }
    }

    if (!found)
        printf("No field needs irrigation.\n");

    fclose(fp);
}

/* Generate the full field monitoring report */
void generateReport(void) {
    FILE *fp = fopen(FILE_NAME, "r");
    Field f;
    int count = 0, irrigate = 0;
    float sumMoist = 0, sumTemp = 0, sumHum = 0;

    if (fp == NULL) {
        printf("No data file found. Store data first.\n");
        return;
    }

    printf("\n========== FIELD MONITORING REPORT ==========\n");
    printf("ID   Moist  Temp   Humid  Health  Latitude   Longitude  Status\n");
    printf("---------------------------------------------------------------\n");

    while (fscanf(fp, "%d %f %f %f %d %f %f", &f.id, &f.moisture,
                  &f.temperature, &f.humidity, &f.cropHealth,
                  &f.latitude, &f.longitude) == 7) {
        printf("%-4d %-6.1f %-6.1f %-6.1f %-7d %-10.4f %-10.4f %s\n",
               f.id, f.moisture, f.temperature, f.humidity, f.cropHealth,
               f.latitude, f.longitude,
               (f.moisture < MOISTURE_LIMIT) ? "IRRIGATE" : "OK");

        sumMoist += f.moisture;
        sumTemp += f.temperature;
        sumHum += f.humidity;
        if (f.moisture < MOISTURE_LIMIT)
            irrigate++;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("---------------------------------------------------------------\n");
    printf("Total fields           : %d\n", count);
    printf("Fields needing water   : %d\n", irrigate);
    printf("Average moisture       : %.2f%%\n", sumMoist / count);
    printf("Average temperature    : %.2f C\n", sumTemp / count);
    printf("Average humidity       : %.2f%%\n", sumHum / count);
}

int main(void) {
    int choice;

    do {
        printf("\n--- Agricultural Robot Field Monitoring ---\n");
        printf("1. Store field data\n");
        printf("2. Find areas requiring irrigation\n");
        printf("3. Generate field report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: storeData(); break;
            case 2: findIrrigationAreas(); break;
            case 3: generateReport(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
