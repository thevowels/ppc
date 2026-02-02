# Parallel Processing in C (PPC)

A comprehensive project exploring parallel processing concepts and implementations in the C programming language.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Parallel Programming Concepts](#parallel-programming-concepts)
- [Examples](#examples)
- [Performance Benchmarks](#performance-benchmarks)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project demonstrates various parallel processing techniques in C, including:
- Multi-threading with pthreads
- Process-based parallelism with fork()
- OpenMP implementations
- Message passing with MPI (if applicable)
- Synchronization mechanisms
- Performance optimization strategies

## Features

- [ ] Basic threading examples
- [ ] Thread synchronization (mutexes, semaphores, condition variables)
- [ ] Process creation and management
- [ ] Shared memory implementations
- [ ] Producer-consumer patterns
- [ ] Parallel algorithms (sorting, searching, mathematical computations)
- [ ] Performance measurement utilities
- [ ] Memory management in parallel contexts

## Prerequisites

- GCC compiler with C11 support
- POSIX-compliant system (Linux/Unix)
- pthread library
- OpenMP library (optional)
- MPI library (optional, for distributed computing examples)

### Required Libraries

```bash
# Ubuntu/Debian
sudo apt-get install build-essential libomp-dev

# CentOS/RHEL
sudo yum install gcc openmp-devel

# For MPI support (optional)
sudo apt-get install libopenmpi-dev openmpi-bin
```

## Installation

1. Clone the repository:
```bash
git clone https://github.com/thevowels/ppc.git
cd ppc
```

2. Compile the examples:
```bash
make all
```

Or compile individual examples:
```bash
gcc -pthread -o example example.c
gcc -fopenmp -o openmp_example openmp_example.c
```

## Usage

Run individual examples:
```bash
./example
./openmp_example
```

Run performance benchmarks:
```bash
make benchmark
```

## Project Structure

```
ppc/
├── src/               # Source code files
├── include/           # Header files
├── examples/          # Example implementations
├── benchmarks/        # Performance testing code
├── docs/              # Documentation
├── tests/             # Unit tests
├── Makefile           # Build configuration
└── README.md          # This file
```

## Parallel Programming Concepts

### Threading
- Thread creation and management
- Thread pools
- Race conditions and their prevention
- Deadlock avoidance

### Synchronization
- Mutexes (mutual exclusion)
- Semaphores
- Condition variables
- Read-write locks
- Barriers

### Process Management
- Process creation with fork()
- Inter-process communication (IPC)
- Shared memory
- Pipes and message queues

### Performance Considerations
- Load balancing
- Cache efficiency
- False sharing
- NUMA awareness

## Examples

### Basic Threading
```c
#include <pthread.h>
#include <stdio.h>

void* worker_thread(void* arg) {
    // Thread implementation
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, worker_thread, NULL);
    pthread_join(thread, NULL);
    return 0;
}
```

### OpenMP Parallel Loop
```c
#include <omp.h>

int main() {
    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        // Parallel processing
    }
    return 0;
}
```

## Performance Benchmarks

Performance metrics and comparisons between:
- Sequential vs. parallel implementations
- Different synchronization mechanisms
- Scaling with number of threads/processes
- Memory usage patterns

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-example`)
3. Commit your changes (`git commit -am 'Add new parallel algorithm'`)
4. Push to the branch (`git push origin feature/new-example`)
5. Create a Pull Request

### Code Style
- Follow K&R C coding style
- Use meaningful variable names
- Include proper documentation
- Add performance measurements for new algorithms

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## References

- POSIX Threads Programming: https://computing.llnl.gov/tutorials/pthreads/
- OpenMP Specifications: https://www.openmp.org/
- Linux System Programming by Robert Love
- The Art of Multiprocessor Programming by Maurice Herlihy

---

**Note**: This project is for educational purposes and demonstrates various parallel processing techniques in C programming.