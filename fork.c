#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Başlangıç - PID: %d\n", getpid());

    pid_t child_pid = fork();  // Yeni bir işlem oluşturuluyor

    if (child_pid < 0) {
        fprintf(stderr, "Fork başarısız oldu\n");
        return 1;
    }

    if (child_pid == 0) {
        // Çocuk işlemi
        printf("Çocuk İşlem - PID: %d, Ebeveyn PID: %d\n", getpid(), getppid());
    } else {
        // Ebeveyn işlemi
        printf("Ebeveyn İşlem - PID: %d, Çocuk PID: %d\n", getpid(), child_pid);
    }

    // Her iki işlem de bu noktadan sonra devam eder
    printf("Bitiş - PID: %d\n", getpid());

    return 0;
}
