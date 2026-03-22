# Philosophers

## Description

This repository contains the 42 **Philosophers** project implemented in C, with:

- `philo/`: mandatory version using **threads** and **mutexes**
- `philo_bonus/`: bonus version using **processes** and **POSIX semaphores**

The program simulates the dining philosophers problem with strict timing constraints (`time_to_die`, `time_to_eat`, `time_to_sleep`) and synchronized state logging.

Note: no project subject PDF was found in this repository at generation time, so this README is based on verified source code and Makefiles only.

## Features

- Input parsing and validation (syntax, positive values, `INT_MAX` boundary checks)
- Mandatory implementation with one thread per philosopher and one monitor thread
- Bonus implementation with one process per philosopher; each child starts one philosopher routine thread and monitors death in the child process main flow
- Fork/resource synchronization (`pthread_mutex_t` in mandatory, named semaphores in bonus)
- Death detection based on elapsed time since last meal
- Optional stop condition when each philosopher has eaten `number_of_times_each_philosopher_must_eat`
- Mandatory code includes explicit single-philosopher handling; the bonus code does not have a dedicated one-philosopher branch
- Timestamped, serialized state output (`has taken a ... fork`, `is eating`, `is sleeping`, `is thinking`, `died`)

## How it works

### Mandatory (`philo`)

Each philosopher owns a left fork mutex and references the next philosopher's left fork as right fork. A monitor thread continuously checks starvation by comparing `current_time_ms()` against `last_eat`. The simulation stops when a death is detected or when all philosophers reached the optional meal target.

To reduce contention/deadlocks, the routine computes lock order from fork pointer ordering and offsets odd philosopher starts slightly.

### Bonus (`philo_bonus`)

The parent process forks one child per philosopher. In each child, the main flow monitors starvation while a routine thread runs the philosopher loop. Named semaphores are used for forks and serialized printing, and the parent uses waitpid/kill to stop the remaining children after a death-triggered exit.

## Installation / Build

### Requirements

- `cc`
- `make`
- POSIX threads support for `philo` and POSIX named semaphore support for `philo_bonus`
- `libft` available to the linker (`-lft`)

### Build mandatory

```bash
cd philo
make CFLAGS='-Wall -Wextra -pthread -g3 -MMD'
```

At the current repository state, default `make` in `philo/` fails because `-Werror` turns an existing unused-variable warning into an error.
If your linker cannot find `libft`, rerun with `make LIBFTDIR=/path/to/libft ...`.

### Build bonus

```bash
cd philo_bonus
make
```

If your linker cannot find `libft`, rerun with `make LIBFTDIR=/path/to/libft`.

## Usage

### Mandatory

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Bonus

```bash
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All time values are in milliseconds.

## Example

```bash
./philo 2 200 100 100 1
./philo_bonus 2 200 100 100 1
```

Example output shape:

```text
0 1 has taken a left fork
1 1 has taken a right fork
1 1 is eating
...
802 3 died
```

## Project Structure

```text
.
├── philo/
│   ├── include/philosophers.h
│   ├── src/philosophers.c      # main, init, thread lifecycle
│   ├── src/parrsing.c          # argument parsing/validation
│   ├── src/routine.c           # philosopher loop
│   ├── src/monitor.c           # death/full monitoring
│   ├── src/time.c              # timing helpers
│   ├── src/utils.c             # state print, sync helpers
│   ├── src/mini_lib.c
│   ├── src/free_err.c
│   ├── src/ft_itoa_nosigne.c
│   └── Makefile
├── philo_bonus/
│   ├── include/bonus_philosophers.h
│   ├── src/bonus_philosophers.c # main/init
│   ├── src/bonus_parrsing.c     # parsing + semaphore init
│   ├── src/bonus_fork.c         # process creation/wait/kill
│   ├── src/bonus_routine.c      # philosopher routine
│   ├── src/bonus_monitor.c      # death checking in child
│   ├── src/bonus_time.c
│   ├── src/bonus_mini_lib.c
│   ├── src/bonus_free_err.c
│   ├── src/bonus_ft_itoa_nosigne.c
│   └── Makefile
└── README.md
```

## What I learned

- Building safe concurrent logic with shared state protection
- Designing stop conditions and monitor loops for deterministic simulation shutdown
- Handling two concurrency models for the same problem: threads/mutexes and processes/semaphores
- Coordinating timing-sensitive actions while preserving readable synchronized logs
