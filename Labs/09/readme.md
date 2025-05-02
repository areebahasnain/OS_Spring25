## Code 1
![image](https://github.com/user-attachments/assets/103b22ce-744b-4094-b6b7-e8c03a50c786)

## Code 1a
![image](https://github.com/user-attachments/assets/67589307-517d-48ca-8920-92a029871af5)

## Code 2a
![image](https://github.com/user-attachments/assets/84c7dc6b-8670-4577-9397-5a317e8a1f68)

**Dry Run:**

| Step | Process     | Code / Action                              | Output / Effect                        |
|------|-------------|---------------------------------------------|----------------------------------------|
| 1    | Parent      | `main()` starts                             | —                                      |
| 2    | Parent      | `signal(SIGCHLD, proc_exit);`               | Registers `proc_exit` as SIGCHLD handler |
| 3    | Parent + Child | `fork()` called                          | Creates a child process                |
| 4    | Child       | `case 0:` branch                            | Child enters its code block            |
| 5    | Child       | `printf("I'm alive...")`                    | `I'm alive (temporarily)`              |
| 6    | Child       | `ret_code = rand();` (e.g., 83)             | Generates random return code           |
| 7    | Child       | `printf("Return code is %d", ret_code);`   | `Return code is 83`                    |
| 8    | Child       | `exit(ret_code);`                           | Child exits, sends SIGCHLD to parent   |
| 9    | Parent      | `pause();`                                  | Suspends until signal (SIGCHLD) arrives |
| 10   | Parent      | SIGCHLD received → `proc_exit()` runs       | Signal handler activated               |
| 11   | Parent      | `wait3(&wstat, WNOHANG, NULL)`              | Reaps child process                    |
| 12   | Parent      | `printf("Return code: %d", wstat);`         | `Return code: 21248` (example)         |
| 13   | Parent      | `wait3()` returns 0                         | No more children                       |
| 14   | Parent      | `printf("return value of wait3() is 0");`   | `return value of wait3() is 0`         |
| 15   | Parent      | `proc_exit()` returns → back to `pause()`   | —                                      |
| 16   | Parent      | `exit(0);`                                  | Program ends                           |


## Code 2b 
![image](https://github.com/user-attachments/assets/37d9aedb-4a17-439b-ac7a-d0747b01b1e6)

## Code 3a
![image](https://github.com/user-attachments/assets/619ea754-73e9-4b20-a88f-d606172aa957)

## Code 3c
![image](https://github.com/user-attachments/assets/42a6f048-481f-43d5-bb80-167ecd6ccc98)

