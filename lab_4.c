###1. Создание нити
Напишите программу, которая создает поток. Используйте атрибуты по умолчанию. Родительская и вновь созданная
нити должны распечатать десять строк текста. При использовании stdout выключите буферизацию (setvbuf).


#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Thread: Line %d\n", i + 1);
    }
    return NULL;
}

int main() {
    // Отключаем буферизацию stdout
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

    // Ждем завершения созданного потока
    pthread_join(thread, NULL);
    return 0;
}

###2 Модифицируйте программу упр. 1 так, чтобы вывод родительской нити производился после завершения дочерней. Используйте pthread_join.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Thread: Line %d\n", i + 1);
    }
    return NULL;
}

int main() {
    // Отключаем буферизацию stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // Ждем завершения созданного потока
    pthread_join(thread, NULL);

    for (int i = 0; i < 10; i++) {
        printf("Main: Line %d\n", i + 1);
    }

    return 0;
}


###3 Модифицируйте программу упр. 1 так, чтобы созданная поток распечатывала свои идентификатор нити и приоритет. Используйте pthread_self и pthread_getschedparam.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    // Получаем ID нити
    pthread_t thread_id = pthread_self();

    // Получаем информацию о приоритете
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
    // Отключаем буферизацию stdout
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

    // Ждем завершения созданного потока
    pthread_join(thread, NULL);

    return 0;
}


###4Напишите программу, которая создает четыре нити,
исполняющие одну и ту же функцию. Эта функция должна распечатать последовательность текстовых строк, переданных как параметр. Каждая из созданных нитей должна распечатать различные последовательности строк.
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
    // Отключаем буферизацию stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    // Массив строк для каждой нити
    char *thread1_strings[] = {"Thread 1 Line 1", "Thread 1 Line 2", "Thread 1 Line 3", NULL};
    char *thread2_strings[] = {"Thread 2 Line 1", "Thread 2 Line 2", "Thread 2 Line 3", NULL};
    char *thread3_strings[] = {"Thread 3 Line 1", "Thread 3 Line 2", "Thread 3 Line 3", NULL};
    char *thread4_strings[] = {"Thread 4 Line 1", "Thread 4 Line 2", "Thread 4 Line 3", NULL};

    pthread_t thread1, thread2, thread3, thread4;

    // Создаем четыре нити
    pthread_create(&thread1, NULL, thread_function, (void *)thread1_strings);
    pthread_create(&thread2, NULL, thread_function, (void *)thread2_strings);
    pthread_create(&thread3, NULL, thread_function, (void *)thread3_strings);
    pthread_create(&thread4, NULL, thread_function, (void *)thread4_strings);

    // Ждем завершения всех нитей
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    return 0;
}


###5 Модифицируйте программу упр. 1 так, чтобы родительская и дочерняя нити распечатали адрес какой-либо локальной переменной. (используйте printf("%p", &i));. Убедитесь, что различные нити используют различные стеки.
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int local_var = 42; // Локальная переменная
    printf("Thread: Local Variable Address: %p\n", &local_var);
    return NULL;
}

int main() {
    // Отключаем буферизацию stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    int local_var = 10; // Локальная переменная в главной нити
    printf("Main: Local Variable Address: %p\n", &local_var);

    // Ждем завершения созданного потока
    pthread_join(thread, NULL);

    return 0;
}



###6 Создайте атрибуты нити. Установите приоритет нити и стек. Запустите поток с указанными атрибутами, распечатайте приоритет и указатель на локальную переменную. Убедитесь, что параметры соответствуют установленным.
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
    // Отключаем буферизацию stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    pthread_attr_t attr;

    // Инициализация атрибутов нити
    pthread_attr_init(&attr);

    // Установка приоритета
    struct sched_param param;
    param.sched_priority = 20; // Устанавливаем приоритет 20
    pthread_attr_setschedparam(&attr, &param);

    // Установка размера стека
    size_t stack_size = 4096; // Устанавливаем размер стека 4KB
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

    // Ждем завершения созданного потока
    pthread_join(thread, NULL);

    // Освобождаем атрибуты
    pthread_attr_destroy(&attr);

    return 0;
}


###7 Родительская поток должна послать дочерней сигнал SIGINT. Дочерняя поток должна перехватить этот сигнал и распечатать пришедший сигнал и свой идентификатор нити.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *child_thread(void *arg) {
    // Ждем, пока родительский поток отправит семафор
    sem_wait(&semaphore);

    // Печатаем пришедший сигнал и ID нити
    printf("Child Thread: Received a signal, Thread ID: %lu\n", (unsigned long)pthread_self());

    return NULL;
}

int main() {
    // Инициализируем семафор
    sem_init(&semaphore, 0, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // Отправляем семафор дочерней нити
    sem_post(&semaphore);

    // Ждем завершения созданной нити
    pthread_join(thread, NULL);

    // Уничтожаем семафор
    sem_destroy(&semaphore);

    return 0;
}


###8 Дочерняя поток должна распечатывать текст на экран. Через две секунды после создания дочерней нити, родительская поток должна прервать ее вызовом функции pthread_cancel.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *child_thread(void *arg) {
    // Ждем, чтобы быть уверенными, что родительский поток отправил cancel
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

    // Подождать 2 секунды
    sleep(2);

    // Отправляем запрос на отмену дочерней нити
    pthread_cancel(thread);

    // Ждем завершения созданной нити
    pthread_join(thread, NULL);

    return 0;
}


###9 Модифицируйте программу упр. 8 так, чтобы дочерняя поток перед завершением распечатывала сообщение об этом. Используйте pthread_cleanup_push.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup_handler(void *arg) {
    printf("Child Thread: Cleanup function executed, Thread ID: %lu\n", (unsigned long)pthread_self());
}

void *child_thread(void *arg) {
    // Регистрируем функцию очистки
    pthread_cleanup_push(cleanup_handler, NULL);

    // Ждем, чтобы быть уверенными, что родительский поток отправил cancel
    sleep(2);
    printf("Child Thread: Received a cancel request, Thread ID: %lu\n", (unsigned long)pthread_self());
    pthread_testcancel();

    // Убираем функцию очистки из стека
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

    // Подождать 2 секунды
    sleep(2);

    // Отправляем запрос на отмену дочерней нити
    pthread_cancel(thread);

    // Ждем завершения созданной нити
    pthread_join(thread, NULL);

    return 0;
}


###10 Модифицируйте программу упр. 1 так, чтобы вывод родительской и дочерней нитей был синхронизован: сначала родительская поток
выводила первую строку, затем дочерняя, затем родительская вторую строку и т.д. Используйте мутексы. Запрещается использовать явные (pthread_yeld) и неявные (sleep и т.д.) передачи управления между нитями и ожидание в цикле.
#include <stdio.h>
#include <pthread.h>

// Объявляем мьютексы
pthread_mutex_t parent_mutex;
pthread_mutex_t child_mutex;

void *child_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        // Захватываем мьютекс родительской нити
        pthread_mutex_lock(&parent_mutex);

        // Выводим строку
        printf("Child: Line %d\n", i + 1);

        // Освобождаем мьютекс родительской нити
        pthread_mutex_unlock(&parent_mutex);

        // Сигнализируем родительской нити, что дочерняя нить закончила вывод
        pthread_mutex_lock(&child_mutex);
        pthread_mutex_unlock(&child_mutex);
    }
    return NULL;
}

int main() {
    // Инициализируем мьютексы
    pthread_mutex_init(&parent_mutex, NULL);
    pthread_mutex_init(&child_mutex, NULL);

    // Запускаем дочернюю нить
    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        // Захватываем мьютекс родительской нити
        pthread_mutex_lock(&parent_mutex);

        // Выводим строку
        printf("Main: Line %d\n", i + 1);

        // Освобождаем мьютекс родительской нити
        pthread_mutex_unlock(&parent_mutex);

        // Сигнализируем дочерней нити, что родительская нить закончила вывод
        pthread_mutex_unlock(&child_mutex);

        // Ожидаем, пока дочерняя нить закончит вывод
        pthread_mutex_lock(&child_mutex);
        pthread_mutex_unlock(&child_mutex);
    }

    // Ждем завершения созданной нити
    pthread_join(thread, NULL);

    // Уничтожаем мьютексы
    pthread_mutex_destroy(&parent_mutex);
    pthread_mutex_destroy(&child_mutex);

    return 0;
}



###11 Докажите, что задача 10 не может быть решена с использованием двух мутексов (без использования других средств синхронизации).
будет нарушено условие "сначала родительская нить выводит первую строку, затем дочерняя, затем родительская вторую строку и так далее".

Родительская нить захватывает parent_mutex и начинает выводить строку.
Дочерняя нить захватывает child_mutex и начинает выводить строку.
Родительская нить освобождает parent_mutex, а затем захватывает child_mutex.
В этом сценарии родительская нить начнет выводить следующую строку до завершения вывода дочерней нити, что нарушает условие.


###12 Решите задачу 10 с использованием условной переменной и двух мутексов.
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t parent_mutex;
pthread_mutex_t child_mutex;
pthread_cond_t parent_condition;
int turn = 0; // Определяет, какая нить должна выполнить следующий шаг

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


###13 Решите задачу 10 с использованием двух семафоров-счетчиков
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t parent_sem;
sem_t child_sem;

void *child_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&parent_sem); // Ждем разрешения от родительской нити
        printf("Child: Line %d\n", i + 1);
        sem_post(&child_sem); // Сообщаем родительской нити, что дочерняя нить завершила
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int result;

    sem_init(&parent_sem, 0, 1); // Инициализируем семафор для родительской нити
    sem_init(&child_sem, 0, 0);  // Инициализируем семафор для дочерней нити

    result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        sem_wait(&child_sem); // Ждем разрешения от дочерней нити
        printf("Main: Line %d\n", i + 1);
        sem_post(&parent_sem); // Сообщаем дочерней нити, что родительская нить завершила
    }

    pthread_join(thread, NULL);

    sem_destroy(&parent_sem);
    sem_destroy(&child_sem);

    return 0;
}
