#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Структура для IoT платформы
struct iot_platform {
    char protocols[100];      // Поддерживаемые протоколы
    int max_devices;          // Макс. количество устройств
    char analytics[100];      // Возможности аналитики
    int latency_ms;           // Задержка связи (мс)
    char security[100];       // Безопасность
    float cost_per_device;    // Стоимость за устройство
    char scalability[100];    // Масштабируемость
    char name[50];           // Название платформы
};

typedef struct iot_platform IoTPlatform;

// Функция для вывода информации о платформе
void put_platform(IoTPlatform p) {
    printf("\nПлатформа: %s\n", p.name);
    printf("  Протоколы: %s\n", p.protocols);
    printf("  Макс. устройств: %d\n", p.max_devices);
    printf("  Аналитика: %s\n", p.analytics);
    printf("  Задержка: %d мс\n", p.latency_ms);
    printf("  Безопасность: %s\n", p.security);
    printf("  Стоимость за устройство: $%.2f\n", p.cost_per_device);
    printf("  Масштабируемость: %s\n", p.scalability);
}

// Функция для ввода данных платформы
void input_platform(IoTPlatform* p) {
    printf("Введите название платформы: ");
    scanf(" %[^\n]", p->name);
    printf("Введите поддерживаемые протоколы: ");
    scanf(" %[^\n]", p->protocols);
    printf("Введите макс. количество устройств: ");
    scanf("%d", &p->max_devices);
    printf("Введите возможности аналитики: ");
    scanf(" %[^\n]", p->analytics);
    printf("Введите задержку связи (мс): ");
    scanf("%d", &p->latency_ms);
    printf("Введите информацию о безопасности: ");
    scanf(" %[^\n]", p->security);
    printf("Введите стоимость за устройство: ");
    scanf("%f", &p->cost_per_device);
    printf("Введите масштабируемость: ");
    scanf(" %[^\n]", p->scalability);
}

// Функция для поиска платформ с низкой задержкой (< 50 мс)
void find_low_latency(IoTPlatform platforms[], int count) {
    printf("\n=== Платформы с низкой задержкой (< 50 мс) ===\n");
    for (int i = 0; i < count; i++) {
        if (platforms[i].latency_ms < 50) {
            put_platform(platforms[i]);
        }
    }
}

// Функция для поиска платформ с поддержкой MQTT
void find_mqtt_platforms(IoTPlatform platforms[], int count) {
    printf("\n=== Платформы с поддержкой MQTT ===\n");
    for (int i = 0; i < count; i++) {
        if (strstr(platforms[i].protocols, "MQTT") != NULL) {
            put_platform(platforms[i]);
        }
    }
}

// Функция для поиска бюджетных платформ (< $1 за устройство)
void find_budget_platforms(IoTPlatform platforms[], int count) {
    printf("\n=== Бюджетные платформы (< $1 за устройство) ===\n");
    for (int i = 0; i < count; i++) {
        if (platforms[i].cost_per_device < 1.0) {
            put_platform(platforms[i]);
        }
    }
}

// Функция для поиска платформ с высокой масштабируемостью
void find_high_scalability(IoTPlatform platforms[], int count) {
    printf("\n=== Платформы с высокой масштабируемостью ===\n");
    for (int i = 0; i < count; i++) {
        if (strstr(platforms[i].scalability, "высокая") != NULL ||
            strstr(platforms[i].scalability, "high") != NULL) {
            put_platform(platforms[i]);
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    IoTPlatform platforms[5];
    int p_c = 0;
    char choice;

    printf("=== Система управления IoT платформами ===\n");

    do {
        printf("\nВыберите действие:\n");
        printf("1 - Добавить платформу\n");
        printf("2 - Показать все платформы\n");
        printf("3 - Найти платформы с низкой задержкой\n");
        printf("4 - Найти платформы с MQTT\n");
        printf("5 - Найти бюджетные платформы\n");
        printf("6 - Найти высокомасштабируемые платформы\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");

        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            if (p_c < 5) {
                printf("\n=== Ввод данных платформы %d ===\n", p_c + 1);
                input_platform(&platforms[p_c]);
                p_c++;
                printf("Платформа добавлена!\n");
            }
            else {
                printf("Достигнут максимум платформ (5)!\n");
            }
            break;

        case '2':
            printf("\n=== Все платформы ===\n");
            for (int i = 0; i < p_c; i++) {
                put_platform(platforms[i]);
            }
            break;

        case '3':
            find_low_latency(platforms, p_c);
            break;

        case '4':
            find_mqtt_platforms(platforms, p_c);
            break;

        case '5':
            find_budget_platforms(platforms, p_c);
            break;

        case '6':
            find_high_scalability(platforms, p_c);
            break;

        case '0':
            printf("Выход из программы.\n");
            break;

        default:
            printf("Неверный выбор!\n");
        }

    } while (choice != '0');

    return 0;
}