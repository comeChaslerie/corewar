# Corewar — Virtual Machine

A C implementation of the **Corewar** virtual machine (Epitech project). Several
assembly programs — *champions* — are loaded into a shared circular memory arena
and fight for survival by executing their bytecode cycle after cycle. The last
champion still reporting itself *alive* wins.

This repository contains the **VM / arena** side of Corewar (the runtime that
executes compiled `.cor` champions). The assembler that compiles `.s` source
files into `.cor` bytecode lives in the companion
[robot-factory](https://github.com/comeChaslerie/robot-factory-mirror) project.

## Features

- Full circular memory arena (`MEM_SIZE = 6 KiB`) with wrap-around addressing
- Cycle-accurate game loop with `CYCLE_TO_DIE` decay and `live` accounting
- Process forking (`fork` / `lfork`) with parent/child program counters
- Carry flag handling and the complete instruction set (see below)
- Memory dump of the arena (`-dump`) matching the reference output byte for byte
- Unit tests (Criterion) and an end-to-end return-value tester against the
  reference binary

## Build & Run

```bash
make                 # builds the ./corewar binary (CC = epiclang)
```

### Usage

```bash
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] champion.cor] ...
```

| Flag    | Description                                                        |
|---------|--------------------------------------------------------------------|
| `-dump` | Dump the arena memory after `nbr_cycle` cycles and exit            |
| `-n`    | Force the player number of the next champion                       |
| `-a`    | Force the load address of the next champion in the arena           |

Example:

```bash
./corewar -n 1 examples/champions/abel.cor -n 2 examples/champions/bill.cor
./corewar -dump 0 examples/champions/abel.cor   # print the initial arena
```

## Instruction Set

| Op   | Mnemonic | Args                    | Cycles | Description           |
|------|----------|-------------------------|--------|-----------------------|
| 0x01 | `live`   | T_DIR                   | 10     | report a player alive |
| 0x02 | `ld`     | T_DIR/T_IND, T_REG      | 5      | load                  |
| 0x03 | `st`     | T_REG, T_REG/T_IND      | 5      | store                 |
| 0x04 | `add`    | T_REG, T_REG, T_REG     | 10     | addition              |
| 0x05 | `sub`    | T_REG, T_REG, T_REG     | 10     | subtraction           |
| 0x06 | `and`    | T_REG/T_DIR/T_IND ×2, T_REG | 6  | bitwise AND           |
| 0x07 | `or`     | T_REG/T_DIR/T_IND ×2, T_REG | 6  | bitwise OR            |
| 0x08 | `xor`    | T_REG/T_DIR/T_IND ×2, T_REG | 6  | bitwise XOR           |
| 0x09 | `zjmp`   | T_DIR (index)           | 20     | jump if carry is set  |
| 0x0A | `ldi`    | T_REG/T_DIR/T_IND, T_REG/T_DIR, T_REG | 25 | load indirect |
| 0x0B | `sti`    | T_REG, T_REG/T_DIR/T_IND, T_REG/T_DIR | 25 | store indirect |
| 0x0C | `fork`   | T_DIR (index)           | 800    | fork the process      |
| 0x0D | `lld`    | T_DIR/T_IND, T_REG      | 10     | long load             |
| 0x0E | `lldi`   | T_REG/T_DIR/T_IND, T_REG/T_DIR, T_REG | 50 | long load indirect |
| 0x0F | `lfork`  | T_DIR (index)           | 1000   | long fork             |
| 0x10 | `print`  | T_REG                   | 2      | print a character     |

Argument types: `T_REG` register (1 byte), `T_DIR` direct value (4 bytes),
`T_IND` indirect/relative pointer (2 bytes).

## Tests

```bash
make tests_run       # build & run the Criterion unit tests
make coverage        # unit tests + line/branch coverage report (gcovr)
make valgrind        # run a full game under Valgrind (leak check)
python3 tester/run.py  # compare return codes against the reference binary
```

## Project Layout

```
include/      public headers (struct, define, op, game, utils, ...)
src/
  init/         arena and champion initialisation
  parsing_args/ command-line flag parsing (-dump / -n / -a)
  game_loop/    cycle scheduler, instruction fetch & apply
  instructions/ implementation of every opcode
  compute/      binary/hexadecimal arithmetic helpers
  utils/        string, number and conversion helpers
tests/        Criterion unit tests
examples/     champions (.s / .cor) and the reference binary
tester/       end-to-end return-value tester
```

## Tech Stack

C • epiclang • Makefile • Criterion • gcovr • Valgrind • GitHub Actions CI
