#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Simulated sensor data structure
typedef struct {
    float temperature;
    float humidity;
    float pressure;
} SensorData;

// Function prototypes
SensorData readSensorData();
void displaySensorData(SensorData data);
void provideWeatherSuggestions(SensorData data);
void setUserLocation(char location[]);
void viewHistoricalWeatherData();

int main() {
    srand(time(NULL)); // Seed for random number generation

    char location[100]; // Buffer to store user location

    setUserLocation(location);

    while (1) {
        // Simulate reading sensor data
        SensorData data = readSensorData();

        // Display sensor data
        printf("\nCurrent Weather at %s:\n", location);
        displaySensorData(data);

        // Provide weather suggestions
        provideWeatherSuggestions(data);

        // View historical weather data
        viewHistoricalWeatherData();

        // Delay for demonstration purposes (simulate real-time data)
        // Adjust the delay based on your requirements
        // Here, we're delaying for 5 seconds
        printf("\n-------------------------------------------\n");
        printf("Press Ctrl+C to stop.\n");
        printf("-------------------------------------------\n");
        fflush(stdout); // Flush output buffer
        sleep(5); // Delay for 5 seconds
    }

    return 0;
}

// Simulate reading sensor data
SensorData readSensorData() {
    SensorData data;
    // Simulate temperature, humidity, and pressure readings
    data.temperature = (float)(rand() % 50); // Random temperature between 0 to 50 degrees Celsius
    data.humidity = (float)(rand() % 100); // Random humidity between 0 to 100%
    data.pressure = (float)(rand() % 1000); // Random pressure between 0 to 1000 millibars
    return data;
}

// Display sensor data
void displaySensorData(SensorData data) {
    printf("Temperature: %.2f°C\n", data.temperature);
    printf("Humidity: %.2f%%\n", data.humidity);
    printf("Pressure: %.2f mb\n", data.pressure);
}

// Provide weather suggestions based on the current conditions
void provideWeatherSuggestions(SensorData data) {
    printf("\nWeather Suggestions:\n");
    if (data.temperature > 30) {
        printf("- It's hot outside! Consider wearing light clothing and staying hydrated.\n");
    } else if (data.temperature < 10) {
        printf("- It's cold outside! Bundle up and dress warmly.\n");
    } else {
        printf("- Enjoy the weather!\n");
    }
    if (data.humidity > 80) {
        printf("- It's humid! Be prepared for sticky conditions.\n");
    }
}

// Set user location
void setUserLocation(char location[]) {
    printf("Enter your location: ");
    fgets(location, 100, stdin);
    // Remove newline character if present
    if (location[strlen(location) - 1] == '\n') {
        location[strlen(location) - 1] = '\0';
    }
}

// View historical weather data
void viewHistoricalWeatherData() {
    // Placeholder for viewing historical weather data
    printf("\nTo view historical weather data, please log in to your account.\n");
    printf("This feature will be available in future updates.\n");
}

