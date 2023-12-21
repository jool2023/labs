Задача 1.
Необходимо написать bash-скрипт, который обработает текстовый файл log.txt в формате Acсess log веб-сервера Apache и выведет в консоль информацию, которая описана в секции “Расшифровка”.
#!/bin/bash

# Проверка наличия аргумента - имени файла
if [ -z "$1" ]; then
    echo "log.txt"
    exit 1
fi

# Чтение файла построчно
while IFS= read -r line; do
    # Разделение строки на поля, используя пробел как разделитель
    fields=($line)

    # Извлечение нужных полей
    client_host=${fields[0]}
    timestamp=${fields[3]} ${fields[4]}
    request=${fields[5]} ${fields[6]} ${fields[7]}
    http_status=${fields[8]}
    bytes_transferred=${fields[9]}
    referer=${fields[10]}
    user_agent=${fields[11]}

    # Вывод информации
    echo "Хост клиента: $client_host"
    echo "Время: $timestamp"
    echo "HTTP-запрос: $request"
    echo "HTTP-статус: $http_status"
    echo "Переданные байты: $bytes_transferred"
    echo "Реферер: $referer"
    echo "Клиент: $user_agent"

    # Разделитель для удобства чтения вывода
    echo "----------------------------------------"

done < "$1"


Задача 2.
Модифицируйте программу так, чтобы ей можно было передать один (необязательный) параметр, в котором указать код завершения операции. При указании этого параметра, программа фильтрует содержимое файла и выводить только те строчки, которые имеют именно этот код процесса.

#!/bin/bash

# Проверка наличия аргумента - имени файла
if [ -z "$1" ]; then
    echo "log.txt"
    exit 1
fi

# Код завершения операции (если указан)
exit_code=$2

# Чтение файла построчно
while IFS= read -r line; do
    # Разделение строки на поля, используя пробел как разделитель
    fields=($line)

    # Извлечение нужных полей
    client_host=${fields[0]}
    timestamp=${fields[3]} ${fields[4]}
    request=${fields[5]} ${fields[6]} ${fields[7]}
    http_status=${fields[8]}
    bytes_transferred=${fields[9]}
    referer=${fields[10]}
    user_agent=${fields[11]}

    # Вывод информации
    echo "Хост клиента: $client_host"
    echo "Время: $timestamp"
    echo "HTTP-запрос: $request"
    echo "HTTP-статус: $http_status"
    echo "Переданные байты: $bytes_transferred"
    echo "Реферер: $referer"
    echo "Клиент: $user_agent"

    # Разделитель для удобства чтения вывода
    echo "----------------------------------------"

    # Проверка кода завершения операции
    if [ -n "$exit_code" ] && [ "$http_status" != "$exit_code" ]; then
        continue
    fi

    # Вывод строки, если код завершения совпадает
    echo "$line"

done < "$1"


Задача 3.
Добавьте в программу возможность указывать ключи (количество и наименования по вашему усмотрению) для фильтрации данных по любому полю.
#!/bin/bash

# Параметры по умолчанию
file_name=""
exit_code=""
filter_field=""
filter_value=""

# Обработка ключей командной строки
while getopts ":f:c:k:v:" opt; do
    case $opt in
        f) file_name="$OPTARG";;
        c) exit_code="$OPTARG";;
        k) filter_field="$OPTARG";;
        v) filter_value="$OPTARG";;
        \?) echo "Неверный ключ: -$OPTARG" >&2; exit 1;;
    esac
done

# Проверка наличия обязательного параметра - имени файла
if [ -z "$log.txt" ]; then
    echo "log.txt"
    exit 1
fi

# Чтение файла построчно
while IFS= read -r line; do
    # Разделение строки на поля, используя пробел как разделитель
    fields=($line)

    # Извлечение нужных полей
    client_host=${fields[0]}
    timestamp=${fields[3]} ${fields[4]}
    request=${fields[5]} ${fields[6]} ${fields[7]}
    http_status=${fields[8]}
    bytes_transferred=${fields[9]}
    referer=${fields[10]}
    user_agent=${fields[11]}

    # Вывод информации
    echo "Хост клиента: $client_host"
    echo "Время: $timestamp"
    echo "HTTP-запрос: $request"
    echo "HTTP-статус: $http_status"
    echo "Переданные байты: $bytes_transferred"
    echo "Реферер: $referer"
    echo "Клиент: $user_agent"

    # Разделитель для удобства чтения вывода
    echo "----------------------------------------"

    # Проверка кода завершения операции
    if [ -n "$exit_code" ] && [ "$http_status" != "$exit_code" ]; then
        continue
    fi

    # Проверка фильтрации по ключам
    if [ -n "$filter_field" ] && [ -n "$filter_value" ]; then
        field_value=${fields[$filter_field]}
        if [ "$field_value" != "$filter_value" ]; then
            continue
        fi
    fi

    # Вывод строки, если все условия выполнены
    echo "$line"

done < "$log.txt"


Задача 4.
Реализовать задачи 1-3 при помощи языка программирования C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения данных из log-файла
struct LogEntry {
    char client_host[256];
    char timestamp[256];
    char request[1024];
    char http_status[4];
    char bytes_transferred[16];
    char referer[1024];
    char user_agent[1024];
};

// Функция для обработки log-файла и вывода информации
void processLogFile(const char *file_name, const char *exit_code, const char *filter_field, const char *filter_value) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }

    struct LogEntry entry;
    char line[4096];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s - - [%s] %s %s %s %s %s",
               entry.client_host, entry.timestamp, entry.request, entry.http_status,
               entry.bytes_transferred, entry.referer, entry.user_agent);

        // Вывод информации
        printf("Хост клиента: %s\n", entry.client_host);
        printf("Время: %s\n", entry.timestamp);
        printf("HTTP-запрос: %s\n", entry.request);
        printf("HTTP-статус: %s\n", entry.http_status);
        printf("Переданные байты: %s\n", entry.bytes_transferred);
        printf("Реферер: %s\n", entry.referer);
        printf("Клиент: %s\n", entry.user_agent);

        // Разделитель для удобства чтения вывода
        printf("----------------------------------------\n");

        // Проверка кода завершения операции
        if (exit_code != NULL && strcmp(entry.http_status, exit_code) != 0) {
            continue;
        }

        // Проверка фильтрации по ключам
        if (filter_field != NULL && filter_value != NULL) {
            int field = atoi(filter_field);
            char *field_value;

            switch (field) {
                case 1:
                    field_value = entry.client_host;
                    break;
                case 2:
                    field_value = entry.timestamp;
                    break;
                case 3:
                    field_value = entry.request;
                    break;
                case 4:
                    field_value = entry.http_status;
                    break;
                case 5:
                    field_value = entry.bytes_transferred;
                    break;
                case 6:
                    field_value = entry.referer;
                    break;
                case 7:
                    field_value = entry.user_agent;
                    break;
                default:
                    fprintf(stderr, "Неверный номер поля для фильтрации\n");
                    exit(EXIT_FAILURE);
            }

            if (strcmp(field_value, filter_value) != 0) {
                continue;
            }
        }

        // Вывод строки, если все условия выполнены
        printf("%s", line);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Укажите имя файла в качестве аргумента\n");
        return EXIT_FAILURE;
    }

    const char *file_name = argv[1];
    const char *exit_code = NULL;
    const char *filter_field = NULL;
    const char *filter_value = NULL;

    // Обработка ключей командной строки
    for (int i = 2; i < argc; i += 2) {
        if (i + 1 < argc) {
            if (strcmp(argv[i], "-c") == 0) {
                exit_code = argv[i + 1];
            } else if (strcmp(argv[i], "-k") == 0) {
                filter_field = argv[i + 1];
            } else if (strcmp(argv[i], "-v") == 0) {
                filter_value = argv[i + 1];
            } else {
                fprintf(stderr, "Неверный ключ: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "Отсутствует значение для ключа: %s\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    // Вызов функции для обработки log-файла
    processLogFile(file_name, exit_code, filter_field, filter_value);

    return EXIT_SUCCESS;
}


Шифрование
1. Обобщенный шифр Цезаря (Caesar Cipher)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptCaesar(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] + shift - 'a') % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] + shift - 'A') % 26 + 'A';
        }
    }
}

void decryptCaesar(char *text, int shift) {
    encryptCaesar(text, 26 - shift);
}

int main() {
    char text[] = "Hello, World!";
    int shift = 3;

    // Шифрование и дешифрование
    encryptCaesar(text, shift);
    printf("Encrypted: %s\n", text);

    decryptCaesar(text, shift);
    printf("Decrypted: %s\n", text);

    return 0;
}

2. Восстановление текста, не зная ключа (Brute Force)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bruteForceDecryptCaesar(char *text) {
    int i;
    for (i = 1; i <= 25; ++i) {
        printf("Shift %d: ", i);
        decryptCaesar(text, i);
        printf("%s\n", text);
    }
}

int main() {
    char text[] = "Khoor, Zruog!";

    // Восстановление текста без знания ключа
    bruteForceDecryptCaesar(text);

    return 0;
}

3. Шифр Вернама (Vernam Cipher)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptVernam(char *text, const char *key) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        text[i] = text[i] ^ key[i % strlen(key)];
    }
}

void decryptVernam(char *text, const char *key) {
    encryptVernam(text, key);
}

int main() {
    char text[] = "Hello, World!";
    const char key[] = "secretkey";

    // Шифрование и дешифрование
    encryptVernam(text, key);
    printf("Encrypted: %s\n", text);

    decryptVernam(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}

4. Алгоритм OTP (One-Time Pad)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptOTP(char *text, const char *key) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        text[i] = text[i] ^ key[i];
    }
}

void decryptOTP(char *text, const char *key) {
    encryptOTP(text, key);
}

int main() {
    char text[] = "Hello, World!";
    const char key[] = "randomkey";

    // Шифрование и дешифрование
    encryptOTP(text, key);
    printf("Encrypted: %s\n", text);

    decryptOTP(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
