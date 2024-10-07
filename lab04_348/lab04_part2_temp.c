#include <stdio.h>

double fahrenheit_to_celsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}

double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32;
}

double kelvin_to_celsius(double k) {
    return k - 273.15;
}

double celsius_to_kelvin(double c) {
    return c + 273.15;
}

void print_weather_advisory(double temp_celsius) {
    if (temp_celsius < 0) {
        printf("Weather advisory: Freezing. Advisory: Wear heavy winter clothing.\n");
    } else if (temp_celsius >= 0 && temp_celsius <= 10) {
        printf("Weather advisory: Cold. Advisory: Wear a jacket.\n");
    } else if (temp_celsius > 10 && temp_celsius <= 25) {
        printf("Weather advisory: Comfortable. Advisory: You should feel comfortable.\n");
    } else if (temp_celsius > 25 && temp_celsius <= 35) {
        printf("Weather advisory: Hot. Advisory: Stay hydrated.\n");
    } else {
        printf("Weather advisory: Extreme Heat. Advisory: Stay indoors.\n");
    }
}

int main() {
    double temp_input; 
    double temp_output;
    int input_scale; 
    int output_scale;

    
    printf("Enter the temperature value: ");
    scanf("%lf", &temp_input);

    
    printf("Choose the input scale (1 = Fahrenheit, 2 = Celsius, 3 = Kelvin): ");
    scanf("%d", &input_scale);

    
    printf("Choose the output scale (1 = Fahrenheit, 2 = Celsius, 3 = Kelvin): ");
    scanf("%d", &output_scale);

    double temp_celsius;

    
    if (input_scale == 1) {
        temp_celsius = fahrenheit_to_celsius(temp_input);
    } else if (input_scale == 2) {
        temp_celsius = temp_input;
    } else if (input_scale == 3) {
        temp_celsius = kelvin_to_celsius(temp_input);
    } else {
        printf("Invalid input scale.\n");
        return 1;
    }

    
    if (output_scale == 1) {
        temp_output = celsius_to_fahrenheit(temp_celsius);
        printf("Converted temperature: %.2f°F\n", temp_output);
    } else if (output_scale == 2) {
        temp_output = temp_celsius;
        printf("Converted temperature: %.2f°C\n", temp_output);
    } else if (output_scale == 3) {
        temp_output = celsius_to_kelvin(temp_celsius);
        printf("Converted temperature: %.2fK\n", temp_output);
    } else {
        printf("Invalid output scale.\n");
        return 1;
    }

    
    print_weather_advisory(temp_celsius);

    return 0;
}