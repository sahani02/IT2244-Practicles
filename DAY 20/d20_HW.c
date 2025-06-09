#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

// Structure for inputs
typedef struct {
    int shapeCode;  // 1: Circle, 2: Rectangle, 3: Square, 4: Triangle
    float dim1, dim2;
} ShapeInput;

int main() {
    int pipefd[2];
    pid_t pid;

    // Create shared memory
    int shmid = shmget(IPC_PRIVATE, sizeof(float), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child Process
        close(pipefd[1]); // Close write end

        ShapeInput input;
        read(pipefd[0], &input, sizeof(input));
        close(pipefd[0]);

        float area = 0;
        switch (input.shapeCode) {
            case 1: // Circle
                area = 3.1416 * input.dim1 * input.dim1;
                break;
            case 2: // Rectangle
			 area = input.dim1 * input.dim2;
                break;
            case 3: // Square
                area = input.dim1 * input.dim1;
                break;
            case 4: // Triangle
                area = 0.5 * input.dim1 * input.dim2;
                break;
            default:
                fprintf(stderr, "Invalid shape code received.\n");
                exit(1);
        }

        // Write result to shared memory
        float *shm_area = (float *)shmat(shmid, NULL, 0);
        *shm_area = area;
        shmdt(shm_area);

        exit(0);
    }
    else {
        // Parent Process
        close(pipefd[0]); // Close read end

        ShapeInput input;
        printf("Area Calculation Program\n");
        printf("Choose a shape:\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Square\n");
        printf("4. Triangle\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &input.shapeCode);

        switch (input.shapeCode) {
            case 1:
                printf("Enter radius: ");
                scanf("%f", &input.dim1);
                input.dim2 = 0;
                break;
            case 2:
                printf("Enter length: ");
                scanf("%f", &input.dim1);
                printf("Enter width: ");
                scanf("%f", &input.dim2);
                break;
             case 3:
                printf("Enter side length: ");
                scanf("%f", &input.dim1);
                input.dim2 = 0;
                break;
            case 4:
                printf("Enter base: ");
                scanf("%f", &input.dim1);
                printf("Enter height: ");
                scanf("%f", &input.dim2);
                break;
            default:
                printf("Invalid choice\n");
                close(pipefd[1]);
                shmctl(shmid, IPC_RMID, NULL);
                exit(1);
		}

			write(pipefd[1], &input, sizeof(input));
			close(pipefd[1]);

			wait(NULL); // Wait for child to finish

			float *shm_area = (float *)shmat(shmid, NULL, 0);
			const char *shape_names[] = {"", "Circle", "Rectangle", "Square", "Triangle"};
			printf("Area of %s = %.2f\n", shape_names[input.shapeCode], *shm_area);
			shmdt(shm_area);
			shmctl(shmid, IPC_RMID, NULL); // Cleanup
	}

		return 0;
}

