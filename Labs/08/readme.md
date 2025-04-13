##  Code 1 
### (c)
![image](https://github.com/user-attachments/assets/6b0833d2-c4a7-4469-8bb0-046a3330f3cc)

## Code 2 
### (a)
![image](https://github.com/user-attachments/assets/58b3f936-80bd-43d8-81e3-f284a787cb80)
### (b)
The threads produce different counter values because they simultaneously access and modify the shared counter variable without synchronization, causing a race condition where increments are lost due to interleaved operations.
### (c)
![image](https://github.com/user-attachments/assets/b45fbb06-ec63-4591-9799-a71b9ab5b561)
Making counter local to each thread causes them to increment their own copies (0 → 10000000), while the global counter remains untouched at 0.

