������ 1.
���������� �������� bash-������, ������� ���������� ��������� ���� log.txt � ������� Ac�ess log ���-������� Apache � ������� � ������� ����������, ������� ������� � ������ �������������.
#!/bin/bash

# �������� ������� ��������� - ����� �����
if [ -z "$1" ]; then
    echo "log.txt"
    exit 1
fi

# ������ ����� ���������
while IFS= read -r line; do
    # ���������� ������ �� ����, ��������� ������ ��� �����������
    fields=($line)

    # ���������� ������ �����
    client_host=${fields[0]}
    timestamp=${fields[3]} ${fields[4]}
    request=${fields[5]} ${fields[6]} ${fields[7]}
    http_status=${fields[8]}
    bytes_transferred=${fields[9]}
    referer=${fields[10]}
    user_agent=${fields[11]}

    # ����� ����������
    echo "���� �������: $client_host"
    echo "�����: $timestamp"
    echo "HTTP-������: $request"
    echo "HTTP-������: $http_status"
    echo "���������� �����: $bytes_transferred"
    echo "�������: $referer"
    echo "������: $user_agent"

    # ����������� ��� �������� ������ ������
    echo "----------------------------------------"

done < "$1"


������ 2.
������������� ��������� ���, ����� �� ����� ���� �������� ���� (��������������) ��������, � ������� ������� ��� ���������� ��������. ��� �������� ����� ���������, ��������� ��������� ���������� ����� � �������� ������ �� �������, ������� ����� ������ ���� ��� ��������.

#!/bin/bash

# �������� ������� ��������� - ����� �����
if [ -z "$1" ]; then
    echo "log.txt"
    exit 1
fi

# ��� ���������� �������� (���� ������)
exit_code=$2

# ������ ����� ���������
while IFS= read -r line; do
    # ���������� ������ �� ����, ��������� ������ ��� �����������
    fields=($line)

    # ���������� ������ �����
    client_host=${fields[0]}
    timestamp=${fields[3]} ${fields[4]}
    request=${fields[5]} ${fields[6]} ${fields[7]}
    http_status=${fields[8]}
    bytes_transferred=${fields[9]}
    referer=${fields[10]}
    user_agent=${fields[11]}

    # ����� ����������
    echo "���� �������: $client_host"
    echo "�����: $timestamp"
    echo "HTTP-������: $request"
    echo "HTTP-������: $http_status"
    echo "���������� �����: $bytes_transferred"
    echo "�������: $referer"
    echo "������: $user_agent"

    # ����������� ��� �������� ������ ������
    echo "----------------------------------------"

    # �������� ���� ���������� ��������
    if [ -n "$exit_code" ] && [ "$http_status" != "$exit_code" ]; then
        continue
    fi

    # ����� ������, ���� ��� ���������� ���������
    echo "$line"

done < "$1"


������ 3.
�������� � ��������� ����������� ��������� ����� (���������� � ������������ �� ������ ����������) ��� ���������� ������ �� ������ ����.
#!/bin/bash

# ��������� �� ���������
file_name=""
exit_code=""
filter_field=""
filter_value=""

# ��������� ������ ��������� ������
while getopts ":f:c:k:v:" opt; do
    case $opt in
        f) file_name="$OPTARG";;
        c) exit_code="$OPTARG";;
        k) filter_field="$OPTARG";;
        v) filter_value="$OPTARG";;
        \?) echo "�������� ����: -$OPTARG" >&2; exit 1;;
    esac
done

# �������� ������� ������������� ��������� - ����� �����
if [ -z "$log.txt" ]; then
    echo "log.txt"
    exit 1
fi

# ������ ����� ���������
while IFS= read -r line; do
    # ���������� ������ �� ����, ��������� ������ ��� �����������
    fields=($line)

    # ���������� ������ �����
    client_host=${fields[0]}
    timestamp=${fields[3]} ${fields[4]}
    request=${fields[5]} ${fields[6]} ${fields[7]}
    http_status=${fields[8]}
    bytes_transferred=${fields[9]}
    referer=${fields[10]}
    user_agent=${fields[11]}

    # ����� ����������
    echo "���� �������: $client_host"
    echo "�����: $timestamp"
    echo "HTTP-������: $request"
    echo "HTTP-������: $http_status"
    echo "���������� �����: $bytes_transferred"
    echo "�������: $referer"
    echo "������: $user_agent"

    # ����������� ��� �������� ������ ������
    echo "----------------------------------------"

    # �������� ���� ���������� ��������
    if [ -n "$exit_code" ] && [ "$http_status" != "$exit_code" ]; then
        continue
    fi

    # �������� ���������� �� ������
    if [ -n "$filter_field" ] && [ -n "$filter_value" ]; then
        field_value=${fields[$filter_field]}
        if [ "$field_value" != "$filter_value" ]; then
            continue
        fi
    fi

    # ����� ������, ���� ��� ������� ���������
    echo "$line"

done < "$log.txt"


������ 4.
����������� ������ 1-3 ��� ������ ����� ���������������� C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������� ��� �������� ������ �� log-�����
struct LogEntry {
    char client_host[256];
    char timestamp[256];
    char request[1024];
    char http_status[4];
    char bytes_transferred[16];
    char referer[1024];
    char user_agent[1024];
};

// ������� ��� ��������� log-����� � ������ ����������
void processLogFile(const char *file_name, const char *exit_code, const char *filter_field, const char *filter_value) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("������ �������� �����");
        exit(EXIT_FAILURE);
    }

    struct LogEntry entry;
    char line[4096];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s - - [%s] %s %s %s %s %s",
               entry.client_host, entry.timestamp, entry.request, entry.http_status,
               entry.bytes_transferred, entry.referer, entry.user_agent);

        // ����� ����������
        printf("���� �������: %s\n", entry.client_host);
        printf("�����: %s\n", entry.timestamp);
        printf("HTTP-������: %s\n", entry.request);
        printf("HTTP-������: %s\n", entry.http_status);
        printf("���������� �����: %s\n", entry.bytes_transferred);
        printf("�������: %s\n", entry.referer);
        printf("������: %s\n", entry.user_agent);

        // ����������� ��� �������� ������ ������
        printf("----------------------------------------\n");

        // �������� ���� ���������� ��������
        if (exit_code != NULL && strcmp(entry.http_status, exit_code) != 0) {
            continue;
        }

        // �������� ���������� �� ������
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
                    fprintf(stderr, "�������� ����� ���� ��� ����������\n");
                    exit(EXIT_FAILURE);
            }

            if (strcmp(field_value, filter_value) != 0) {
                continue;
            }
        }

        // ����� ������, ���� ��� ������� ���������
        printf("%s", line);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "������� ��� ����� � �������� ���������\n");
        return EXIT_FAILURE;
    }

    const char *file_name = argv[1];
    const char *exit_code = NULL;
    const char *filter_field = NULL;
    const char *filter_value = NULL;

    // ��������� ������ ��������� ������
    for (int i = 2; i < argc; i += 2) {
        if (i + 1 < argc) {
            if (strcmp(argv[i], "-c") == 0) {
                exit_code = argv[i + 1];
            } else if (strcmp(argv[i], "-k") == 0) {
                filter_field = argv[i + 1];
            } else if (strcmp(argv[i], "-v") == 0) {
                filter_value = argv[i + 1];
            } else {
                fprintf(stderr, "�������� ����: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "����������� �������� ��� �����: %s\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    // ����� ������� ��� ��������� log-�����
    processLogFile(file_name, exit_code, filter_field, filter_value);

    return EXIT_SUCCESS;
}


����������
1. ���������� ���� ������ (Caesar Cipher)
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

    // ���������� � ������������
    encryptCaesar(text, shift);
    printf("Encrypted: %s\n", text);

    decryptCaesar(text, shift);
    printf("Decrypted: %s\n", text);

    return 0;
}

2. �������������� ������, �� ���� ����� (Brute Force)
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

    // �������������� ������ ��� ������ �����
    bruteForceDecryptCaesar(text);

    return 0;
}

3. ���� ������� (Vernam Cipher)
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

    // ���������� � ������������
    encryptVernam(text, key);
    printf("Encrypted: %s\n", text);

    decryptVernam(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}

4. �������� OTP (One-Time Pad)
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

    // ���������� � ������������
    encryptOTP(text, key);
    printf("Encrypted: %s\n", text);

    decryptOTP(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
