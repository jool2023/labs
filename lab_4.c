###1. �������� ����
�������� ���������, ������� ������� �����. ����������� �������� �� ���������. ������������ � ����� ���������
���� ������ ����������� ������ ����� ������. ��� ������������� stdout ��������� ����������� (setvbuf).


#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Thread: Line %d\n", i + 1);
    }
    return NULL;
}

int main() {
    // ��������� ����������� stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("Main: Line %d\n", i + 1);
    }

    // ���� ���������� ���������� ������
    pthread_join(thread, NULL);
    return 0;
}

###2 ������������� ��������� ���. 1 ���, ����� ����� ������������ ���� ������������ ����� ���������� ��������. ����������� pthread_join.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Thread: Line %d\n", i + 1);
    }
    return NULL;
}

int main() {
    // ��������� ����������� stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // ���� ���������� ���������� ������
    pthread_join(thread, NULL);

    for (int i = 0; i < 10; i++) {
        printf("Main: Line %d\n", i + 1);
    }

    return 0;
}


###3 ������������� ��������� ���. 1 ���, ����� ��������� ����� ������������� ���� ������������� ���� � ���������. ����������� pthread_self � pthread_getschedparam.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    // �������� ID ����
    pthread_t thread_id = pthread_self();

    // �������� ���������� � ����������
    struct sched_param param;
    int policy;
    pthread_getschedparam(thread_id, &policy, &param);

    printf("Thread ID: %lu, Priority: %d\n", (unsigned long)thread_id, param.sched_priority);

    for (int i = 0; i < 10; i++) {
        printf("Thread: Line %d\n", i + 1);
    }
    return NULL;
}

int main() {
    // ��������� ����������� stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("Main: Line %d\n", i + 1);
    }

    // ���� ���������� ���������� ������
    pthread_join(thread, NULL);

    return 0;
}


###4�������� ���������, ������� ������� ������ ����,
����������� ���� � �� �� �������. ��� ������� ������ ����������� ������������������ ��������� �����, ���������� ��� ��������. ������ �� ��������� ����� ������ ����������� ��������� ������������������ �����.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    char **strings = (char **)arg;
    for (int i = 0; strings[i] != NULL; i++) {
        printf("Thread: %s\n", strings[i]);
    }
    return NULL;
}

int main() {
    // ��������� ����������� stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    // ������ ����� ��� ������ ����
    char *thread1_strings[] = {"Thread 1 Line 1", "Thread 1 Line 2", "Thread 1 Line 3", NULL};
    char *thread2_strings[] = {"Thread 2 Line 1", "Thread 2 Line 2", "Thread 2 Line 3", NULL};
    char *thread3_strings[] = {"Thread 3 Line 1", "Thread 3 Line 2", "Thread 3 Line 3", NULL};
    char *thread4_strings[] = {"Thread 4 Line 1", "Thread 4 Line 2", "Thread 4 Line 3", NULL};

    pthread_t thread1, thread2, thread3, thread4;

    // ������� ������ ����
    pthread_create(&thread1, NULL, thread_function, (void *)thread1_strings);
    pthread_create(&thread2, NULL, thread_function, (void *)thread2_strings);
    pthread_create(&thread3, NULL, thread_function, (void *)thread3_strings);
    pthread_create(&thread4, NULL, thread_function, (void *)thread4_strings);

    // ���� ���������� ���� �����
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    return 0;
}


###5 ������������� ��������� ���. 1 ���, ����� ������������ � �������� ���� ����������� ����� �����-���� ��������� ����������. (����������� printf("%p", &i));. ���������, ��� ��������� ���� ���������� ��������� �����.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int local_var = 42; // ��������� ����������
    printf("Thread: Local Variable Address: %p\n", &local_var);
    return NULL;
}

int main() {
    // ��������� ����������� stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    int local_var = 10; // ��������� ���������� � ������� ����
    printf("Main: Local Variable Address: %p\n", &local_var);

    // ���� ���������� ���������� ������
    pthread_join(thread, NULL);

    return 0;
}



###6 �������� �������� ����. ���������� ��������� ���� � ����. ��������� ����� � ���������� ����������, ������������ ��������� � ��������� �� ��������� ����������. ���������, ��� ��������� ������������� �������������.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int local_var = 42;
    printf("Thread: Local Variable Address: %p\n", &local_var);

    struct sched_param param;
    int policy;
    pthread_getschedparam(pthread_self(), &policy, &param);
    printf("Thread: Priority: %d\n", param.sched_priority);

    return NULL;
}

int main() {
    // ��������� ����������� stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    pthread_attr_t attr;

    // ������������� ��������� ����
    pthread_attr_init(&attr);

    // ��������� ����������
    struct sched_param param;
    param.sched_priority = 20; // ������������� ��������� 20
    pthread_attr_setschedparam(&attr, &param);

    // ��������� ������� �����
    size_t stack_size = 4096; // ������������� ������ ����� 4KB
    pthread_attr_setstacksize(&attr, stack_size);

    int result = pthread_create(&thread, &attr, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    int local_var = 10;
    printf("Main: Local Variable Address: %p\n", &local_var);

    struct sched_param main_param;
    int main_policy;
    pthread_getschedparam(pthread_self(), &main_policy, &main_param);
    printf("Main: Priority: %d\n", main_param.sched_priority);

    // ���� ���������� ���������� ������
    pthread_join(thread, NULL);

    // ����������� ��������
    pthread_attr_destroy(&attr);

    return 0;
}


###7 ������������ ����� ������ ������� �������� ������ SIGINT. �������� ����� ������ ����������� ���� ������ � ����������� ��������� ������ � ���� ������������� ����.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *child_thread(void *arg) {
    // ����, ���� ������������ ����� �������� �������
    sem_wait(&semaphore);

    // �������� ��������� ������ � ID ����
    printf("Child Thread: Received a signal, Thread ID: %lu\n", (unsigned long)pthread_self());

    return NULL;
}

int main() {
    // �������������� �������
    sem_init(&semaphore, 0, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // ���������� ������� �������� ����
    sem_post(&semaphore);

    // ���� ���������� ��������� ����
    pthread_join(thread, NULL);

    // ���������� �������
    sem_destroy(&semaphore);

    return 0;
}


###8 �������� ����� ������ ������������� ����� �� �����. ����� ��� ������� ����� �������� �������� ����, ������������ ����� ������ �������� �� ������� ������� pthread_cancel.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *child_thread(void *arg) {
    // ����, ����� ���� ����������, ��� ������������ ����� �������� cancel
    sleep(2);
    printf("Child Thread: Received a cancel request, Thread ID: %lu\n", (unsigned long)pthread_self());
    pthread_testcancel();
    return NULL;
}

int main() {
    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // ��������� 2 �������
    sleep(2);

    // ���������� ������ �� ������ �������� ����
    pthread_cancel(thread);

    // ���� ���������� ��������� ����
    pthread_join(thread, NULL);

    return 0;
}


###9 ������������� ��������� ���. 8 ���, ����� �������� ����� ����� ����������� ������������� ��������� �� ����. ����������� pthread_cleanup_push.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup_handler(void *arg) {
    printf("Child Thread: Cleanup function executed, Thread ID: %lu\n", (unsigned long)pthread_self());
}

void *child_thread(void *arg) {
    // ������������ ������� �������
    pthread_cleanup_push(cleanup_handler, NULL);

    // ����, ����� ���� ����������, ��� ������������ ����� �������� cancel
    sleep(2);
    printf("Child Thread: Received a cancel request, Thread ID: %lu\n", (unsigned long)pthread_self());
    pthread_testcancel();

    // ������� ������� ������� �� �����
    pthread_cleanup_pop(1);

    return NULL;
}

int main() {
    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // ��������� 2 �������
    sleep(2);

    // ���������� ������ �� ������ �������� ����
    pthread_cancel(thread);

    // ���� ���������� ��������� ����
    pthread_join(thread, NULL);

    return 0;
}


###10 ������������� ��������� ���. 1 ���, ����� ����� ������������ � �������� ����� ��� �������������: ������� ������������ �����
�������� ������ ������, ����� ��������, ����� ������������ ������ ������ � �.�. ����������� �������. ����������� ������������ ����� (pthread_yeld) � ������� (sleep � �.�.) �������� ���������� ����� ������ � �������� � �����.
#include <stdio.h>
#include <pthread.h>

// ��������� ��������
pthread_mutex_t parent_mutex;
pthread_mutex_t child_mutex;

void *child_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        // ����������� ������� ������������ ����
        pthread_mutex_lock(&parent_mutex);

        // ������� ������
        printf("Child: Line %d\n", i + 1);

        // ����������� ������� ������������ ����
        pthread_mutex_unlock(&parent_mutex);

        // ������������� ������������ ����, ��� �������� ���� ��������� �����
        pthread_mutex_lock(&child_mutex);
        pthread_mutex_unlock(&child_mutex);
    }
    return NULL;
}

int main() {
    // �������������� ��������
    pthread_mutex_init(&parent_mutex, NULL);
    pthread_mutex_init(&child_mutex, NULL);

    // ��������� �������� ����
    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        // ����������� ������� ������������ ����
        pthread_mutex_lock(&parent_mutex);

        // ������� ������
        printf("Main: Line %d\n", i + 1);

        // ����������� ������� ������������ ����
        pthread_mutex_unlock(&parent_mutex);

        // ������������� �������� ����, ��� ������������ ���� ��������� �����
        pthread_mutex_unlock(&child_mutex);

        // �������, ���� �������� ���� �������� �����
        pthread_mutex_lock(&child_mutex);
        pthread_mutex_unlock(&child_mutex);
    }

    // ���� ���������� ��������� ����
    pthread_join(thread, NULL);

    // ���������� ��������
    pthread_mutex_destroy(&parent_mutex);
    pthread_mutex_destroy(&child_mutex);

    return 0;
}



###11 ��������, ��� ������ 10 �� ����� ���� ������ � �������������� ���� �������� (��� ������������� ������ ������� �������������).
����� �������� ������� "������� ������������ ���� ������� ������ ������, ����� ��������, ����� ������������ ������ ������ � ��� �����".

������������ ���� ����������� parent_mutex � �������� �������� ������.
�������� ���� ����������� child_mutex � �������� �������� ������.
������������ ���� ����������� parent_mutex, � ����� ����������� child_mutex.
� ���� �������� ������������ ���� ������ �������� ��������� ������ �� ���������� ������ �������� ����, ��� �������� �������.


###12 ������ ������ 10 � �������������� �������� ���������� � ���� ��������.
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t parent_mutex;
pthread_mutex_t child_mutex;
pthread_cond_t parent_condition;
int turn = 0; // ����������, ����� ���� ������ ��������� ��������� ���

void *child_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&child_mutex);

        while (turn != 1) {
            pthread_cond_wait(&parent_condition, &child_mutex);
        }

        printf("Child: Line %d\n", i + 1);
        turn = 0;

        pthread_mutex_unlock(&parent_mutex);
        pthread_cond_signal(&parent_condition);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int result;

    pthread_mutex_init(&parent_mutex, NULL);
    pthread_mutex_init(&child_mutex, NULL);
    pthread_cond_init(&parent_condition, NULL);

    result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&parent_mutex);

        while (turn != 0) {
            pthread_cond_wait(&parent_condition, &parent_mutex);
        }

        printf("Main: Line %d\n", i + 1);
        turn = 1;

        pthread_mutex_unlock(&child_mutex);
        pthread_cond_signal(&parent_condition);
    }

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&parent_mutex);
    pthread_mutex_destroy(&child_mutex);
    pthread_cond_destroy(&parent_condition);

    return 0;
}


###13 ������ ������ 10 � �������������� ���� ���������-���������
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t parent_sem;
sem_t child_sem;

void *child_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&parent_sem); // ���� ���������� �� ������������ ����
        printf("Child: Line %d\n", i + 1);
        sem_post(&child_sem); // �������� ������������ ����, ��� �������� ���� ���������
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int result;

    sem_init(&parent_sem, 0, 1); // �������������� ������� ��� ������������ ����
    sem_init(&child_sem, 0, 0);  // �������������� ������� ��� �������� ����

    result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        sem_wait(&child_sem); // ���� ���������� �� �������� ����
        printf("Main: Line %d\n", i + 1);
        sem_post(&parent_sem); // �������� �������� ����, ��� ������������ ���� ���������
    }

    pthread_join(thread, NULL);

    sem_destroy(&parent_sem);
    sem_destroy(&child_sem);

    return 0;
}
